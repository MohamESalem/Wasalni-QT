#ifndef GRAPH_H
#define GRAPH_H

#include "city.h"
#include "edge.h"
// an instance of the Graph class exists in mainwindow.h
class Graph {
private:
    std::map<City*, std::vector<std::pair<City*, int>>> adjList;
    std::vector<Edge*> edgesv;
    // this map assigns each city to a vector of the cities conneceted to it
    // the pair consists of two items: the city connected to + weight of the edge connecting the two cities
    // NOTE: ALWAYS USE POINTERS

public:
    Graph();
    // add function protoypes here
    void addCity(City*);
    void addEdge(City*,City*,int);
    void removeCity(City*); //remove it by name
    void removeEdge(City*,City*);
    bool isPathExist(City*,City*); // LACKS TESTING
    City* findCity(QString);
    std::pair<int, std::vector<City*>> dijkstra(City*,City*);
    bool isEdgeExist(City* source, City* destination);
    void printGraph() const;
    std::vector<Edge*> getEdgesVector();
    std::map<City*, std::vector<std::pair<City*, int>>> getAdjList();
    void clearAdjList();
};

#endif // GRAPH_H
