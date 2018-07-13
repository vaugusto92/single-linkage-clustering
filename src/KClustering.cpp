#include "KClustering.hpp"
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <cstring>
#include <array>

using namespace std;

const float INF = numeric_limits<float>::infinity();

/**
 * Constructor.
 */
KClustering::KClustering(int k) {
    this->k = k;
}

/**
 * Destructor.
 */
KClustering::~KClustering() {
    delete this;
}

bool weightSort(pair<pair <int, int>, float> e, pair<pair <int, int>, float> f) {
    return bool(e.second < f.second);
}

bool weightSort2(pair<int, float> e, pair<int, float> f) {
    return bool(e.second < f.second);
}

/**
 * Kruskal Minimum Spanning Tree Algorithm implementation
 * using a Disjoint Set Data Structure.
 * 
 * @param graph
 * 
 * @return
 * 
 * 
 */
void KClustering::kruskal(vector<pair<pair<int, int>, float>> edges) {

    const int m = vertices.size();

    // Sort weights so that w1 <= w2 <= ... <= wm.
    sort(edges.begin(), edges.end(), weightSort);

    // T = Φ
    vector<pair<pair <int, int>, float>> T = {};

    // For each vertex u ∈ V, make a set containing singleton u.
    ds = new DisjointSet();
    for (int i = 0; i < m; i++) {
        ds->makeSet(i);
    }

    int diff = m;
    for (auto edge : edges) {

        int u = edge.first.first;
        int v = edge.first.second;

        if (ds->findSet(u) != ds->findSet(v)) {

            // T = T U {e}
            T.push_back(edge);

            // Merge the sets containings u and v
            ds->_union(u, v);
            
            diff--;
            if (diff == k) {
                break;
            }
        }
    }

    this->MST = T;
}


void KClustering::prim(Graph graph) {

    BinaryHeap *bh = new BinaryHeap(m);
    int visited[m];
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    bh->heapify(0);

    for(int i = 0; i < m; i++) {
        bh->index_map[bh->pq[i].second] = i;
    }

    vector<int> S = {};

    vector<Edge> T = {};

    int i = 0;
    double peso = 0;
    while(bh->size != 0) {

        /* p.first will contain the cost of the next edge to be added in our
           answer and p.second will give the vertex number.
        */
        pair<float, int> p = bh->extractMin();

        
        visited[p.second] = 1;

        int u = p.second;
        if (i != 0) {
            Edge e = assignEdge(S[i-1], u, p.first);
            T.push_back(e);
        }
        i++;

        S.push_back(u);

        for(int i = 0; i < graph[u].size(); i++) {
            if (u == i) {
                continue;
            }

            int v = graph[u][i].first;
            float c = graph[u][i].second;
            float w = bh->pq[bh->index_map[v]].first;    

            if(!visited[v]) {
                if(c < w) {
                    bh->decreaseKey(bh->index_map[v], graph[u][i].second);
                }
            }
        }

    }

    this->S = S;
    this->MST = T;
}

void KClustering::classify(int method) {
    initializeClusters();

    if (method == 1) {
        kruskalSingleLinkClustering();
    }

    if (method == 2) {
        primSingleLinkClustering();
    }
}

void KClustering::kruskalSingleLinkClustering() {
    int aux = 1;

    map<int, int> node_class_map;
    map<int, int>::iterator it;

    for (int i = 0; i < m; i++) {
        int node = ds->findSet(i);

        if(node_class_map.insert(make_pair(node, aux)).second != false) {
            node_class_map.insert(make_pair(node, aux++));
        }

        clusters[i] = node;
    }

    for (int i = 0; i < m; i++) {
        it = node_class_map.find(clusters[i]);
        clusters[i] = it->second;
    }
}

void KClustering::primSingleLinkClustering() {
    vector<float> weights;
    vector<float> _weights;
    vector<float> greatestWeights;
    vector<int> positions;

    for (int i = 0; i < MST.size(); i++) {
        weights.push_back(MST.at(i).second);
        _weights.push_back(MST.at(i).second);
    }

    sort(_weights.begin(), _weights.end());

    for (int i = (m - 2); i > (m - k - 1); i--) {
        greatestWeights.push_back(_weights[i]);
    }

    for (int i = 0; i < greatestWeights.size(); i++) {
        for (int j = 0; j < weights.size(); j++) {
            if(weights[j] == greatestWeights[i]) {
                positions.push_back(j);
                break;
            }
        }
    }

    sort(positions.begin(), positions.end());

    ds = new DisjointSet();
    for (int i = 0; i < m; i++) {
        ds->makeSet(i);
    }    

    int diff = m;
    for (int i = 0; i < S.size() - 1; i++) {

        bool found = find(positions.begin(), positions.end(), i) != positions.end();

        if (found) {
            continue;
        }

        int u = S.at(i);
        int v = S.at(i+1);

        if (ds->findSet(u) != ds->findSet(v)) {

            // Merge the sets containings u and v
            ds->_union(u, v);
            
            diff--;
            if (diff == k) {
                break;
            }
        }
    }

    kruskalSingleLinkClustering();
}

void KClustering::initializeClusters() {
    this->clusters = new int[m];

    for (int i = 0; i < m; i++) {
        this->clusters[i] = -1;
    }
}

void KClustering::printClusters() {
    for (int i = 0; i < m; i++) {
        cout << clusters[i] << endl;
    }
}

void KClustering::readData(string filename) {
    string line;
    ifstream file (filename);

    vector<Vertex> _vertices;

    int i = 0;
    if (file.is_open()) {
        while (getline (file, line)){
            int tab = line.find("\t");
            float x = strtof((line.substr(0, tab)).c_str(), 0);
            float y = strtof((line.substr(tab, line.size())).c_str(), 0);

            _vertices.push_back(make_pair(x, y));

            i++;
        }
        file.close();
    }

    this->vertices = _vertices;
    this->m = vertices.size();
}

Graph KClustering::loadGraph() {

    Graph graph(m);
    vector<pair<int, float>> tmp;

    for (int i = 0; i < m; i++) {
        float xa = vertices.at(i).first;
        float ya = vertices.at(i).second;

        for (int j = 0; j < m; j++) {
            float xb = vertices.at(j).first;
            float yb = vertices.at(j).second;

            float w = calculateWeight(xa, ya, xb, yb);

            tmp.push_back(make_pair(j, w));
        }
        graph[i] = tmp;
        tmp.clear();
    }

    return graph;
}

vector<Edge> KClustering::generateOptimizedEdges() {
    vector<Edge> edges;

    for (int i = 0; i < vertices.size(); i++) {
        for (int j = i; j < vertices.size(); j ++) {
            
            // Edge's source and destiny are the same vertex.
            if (i == j) {
                continue;
            }

            pair<int, int> coordinates = make_pair(i, j);

            float xa = vertices.at(i).first;
            float ya = vertices.at(i).second;
            float xb = vertices.at(j).first;
            float yb = vertices.at(j).second;

            float weight = calculateWeight(xa, ya, xb, yb);

            pair<pair<int, int>, float> edge = make_pair(coordinates, weight);
            edges.push_back(edge);
        }
    }

    return edges;
}

Edge KClustering::assignEdge(int u, int v, float w) {
    return make_pair(make_pair(u, v), w);
}

Edge KClustering::makeEdge(int u, int v) {
    pair<int, int> coordinates = make_pair(u, v);

    float xa = vertices.at(u).first;
    float ya = vertices.at(u).second;
    float xb = vertices.at(v).first;
    float yb = vertices.at(v).second;

    float weight = calculateWeight(xa, ya, xb, yb);

    return make_pair(coordinates, weight);
}

float KClustering::calculateWeight(float xa, float ya, float xb, float yb) {
    const float x = abs(xa - xb);
    const float y = abs(ya - yb);
    return sqrt((x*x) + (y*y));
}