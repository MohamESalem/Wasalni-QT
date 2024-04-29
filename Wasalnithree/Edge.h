#ifndef EDGE_H
#define EDGE_H

struct Edge {
    int weight;
    bool isEmpty;
    Edge() {
        this->isEmpty = true;
    }

    Edge(int weight) {
        this->isEmpty = false;
        this->weight = weight;
    }
};

#endif // EDGE_H
