#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include "Edge.h"
#include <vector>

class graph
{
    std::vector<Node*> vertices;            //vector of vertices
    std::vector<std::vector<Edge*>> edges;  //vector of vectors of edges
public:
    graph();
    int getIndex(Node* n);
    Node* addNode(int X, int Y, std::string name);
    void removeNode(Node* n);
    Edge* addEdge(Node* from, Node* to, int weight);
    void removeEdge(Edge* e);
    std::vector<Edge*> edgesFrom(Node* n);
    std::vector<Edge*> edgesTo(Node* n);
    Node* findVertex(std::string name);
    Edge* findEdge(std::string from_name, std::string to_name);
    bool hasEdge(Node* firstNode, Node* secondNode);
};

#endif // GRAPH_H
