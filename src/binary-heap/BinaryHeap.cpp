#include "BinaryHeap.hpp"
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <fstream>
#include <limits>

using namespace std;

const float INF = numeric_limits<float>::infinity();

BinaryHeap::BinaryHeap(int size) {
    this->size = size;
    this->pq.resize(size);

    vector<int> tmp(size,0);
    this->index_map = tmp;
}

BinaryHeap::~BinaryHeap() {
    delete this;
}

// Shift up the key with lower value.
void BinaryHeap::bubbleUp(int index) {
    int parent = (index-1)/2;
    while(index >= 0 && pq[index].first < pq[parent].first) {
        index_map[pq[index].second] = parent;
        index_map[pq[parent].second] = index;
        swap(pq[index], pq[parent]);
        index = parent;
        parent = (index - 1)/2;
    }
}

// Shift down the key with higher value.
void BinaryHeap::bubbleDown(int index) {
    int left = 2*index+1, right = 2*index+2;
    int min_index = index;
    if(left < size && pq[left].first < pq[min_index].first)
        min_index = left;
    if(right < size && pq[right].first < pq[min_index].first)
        min_index = right;
    if(min_index != index) {
        index_map[pq[index].second] = min_index;
        index_map[pq[min_index].second] = index;
        std::swap(pq[index], pq[min_index]);
        bubbleDown(min_index);
    }
}

// Extract the minimum element from priority queue.
pair<float, int> BinaryHeap::extractMin() {
    index_map[pq[0].second] = size-1;
    index_map[pq[size-1].second] = 0;
    swap(pq[0], pq[size-1]);
    size -= 1;
    bubbleDown(0);
    return pq[size];
}

// Change the value at index 'index' to 'value'.
void BinaryHeap::decreaseKey(int index, float value) {
    float temp = pq[index].first;
    pq[index].first = value;
    if(value < temp) {
        bubbleUp(index);
    } else {
        bubbleDown(index);
    }
}

// Initialise and heapify the priority queue.
void BinaryHeap::heapify(int start_index) {
    for(int i = 0; i < this->size; i++) {
        pq[i].first = INF;
        pq[i].second = i;
    }
    pq[0].first = 0.0;
    pq[start_index].second = start_index;

    for(int i = this->size-1; i >= 0; i--) {
        bubbleDown(i);
    }
}
