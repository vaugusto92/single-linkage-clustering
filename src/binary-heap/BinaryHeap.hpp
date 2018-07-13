#ifndef _INC_BINARYHEAP_H
#define _INC_BINARYHEAP_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;
/**
 * Class that represents a Binary Heap for the 
 * Priority Queue with Decrease Key operation.
 */
class BinaryHeap {

    public:

        vector<pair<float, int>> pq;
        int size;
        vector<int> index_map;

        BinaryHeap(int size);
        ~BinaryHeap();

        void bubbleUp(int index);
        void bubbleDown(int index);
        pair<float, int> extractMin();
        void decreaseKey(int index, float value);
        void heapify(int start_index);
};

#endif