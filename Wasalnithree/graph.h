#ifndef GRAPH_H
#define GRAPH_H

#include "city.h"

// an instance of the Graph class exists in mainwindow.h
class Graph {
private:
    std::map<City, std::vector<std::pair<City, int>>> adjList;
    // this map assigns each city to a vector of the cities conneceted to it
    // the pair consists of two items: the city connected to + weight of the edge connecting the two cities
public:
    Graph();
    // add function protoypes here
};

#endif // GRAPH_H
