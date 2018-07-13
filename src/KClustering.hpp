#ifndef _INC_KCLUSTERING_H
#define _INC_KCLUSTERING_H

#include <vector>
#include <string>
#include "disjoint-set/DisjointSet.hpp"
#include "binary-heap/BinaryHeap.hpp"

typedef pair<float, float> Vertex;
typedef pair<pair <int, int>, float> Edge;
typedef vector<vector<pair<int, float>>> Graph;

using namespace std;

/**
 *  Class with algorithms for the K-Clustering
 *  application.
 */
class KClustering {

    public:

        vector<Vertex> vertices;
        vector<Edge> MST;
        vector<int> S;
        DisjointSet *ds;
        int *clusters;
        int m;
        int k;

        KClustering(int k);
        ~KClustering();

        void kruskal(vector<Edge> edges);
        void prim(Graph graph);

        void readData(string filename);
        Graph loadGraph();
        vector<Edge> generateOptimizedEdges();
        Edge makeEdge(int u, int v);
        int getVertexIndex(vector<pair<Vertex*, float>> arr, Vertex* v);
        
        void classify(int method);
        void printClusters();

    private:

        void initializeClusters();
        void kruskalSingleLinkClustering();
        void primSingleLinkClustering();
        Edge assignEdge(int u, int v, float w);
        float calculateWeight(float xa, float ya, float xb, float yb);
};

#endif