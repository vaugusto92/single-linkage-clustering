#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include "KClustering.hpp"
#include <ctime>
#include <set>

using namespace std;

main (int argc, char **argv) {

    if (argc <= 2) {
        cout << "You must choose between Kruskal (1) or Prim (2) and enter the number of clusters..." << endl;
        exit(1);
    }

    int method = atoi(argv[1]);
    int k = atoi(argv[2]);
    bool exec_time = false;
    if (argv[3] != NULL) {
        exec_time = true;
    }

    KClustering *clustering = new KClustering(k);
    clustering->readData("../input/data.txt");

    clock_t begin;
    clock_t end; 
    double elapsed_secs;

    if (exec_time) {
        clock_t begin = clock();
    } 

    if (method == 1) {
        vector<pair<pair<int, int>, float>> edges = clustering->generateOptimizedEdges();
        clustering->kruskal(edges);
    }

    if (method == 2) {
        vector<vector<pair<int, float>>> graph = clustering->loadGraph();
        clustering->prim(graph);
    }

    if (exec_time) {
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "Elapsed: " << elapsed_secs << endl;
    }

    clustering->classify(method);
    clustering->printClusters();
}
