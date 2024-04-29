#include "graph.h"



graph::graph() = default; //default constructor

int graph::getIndex(Node *n)
{
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i]->name ==n->name)
            return i;
    }
    return -1;
}

Node *graph::addNode(int X, int Y, std::string name)
{
    int index = getIndex(new Node(X, Y, name));
    if (index!= -1) {
        return vertices[index];
    }

    vertices.resize(vertices.size()+1);
    auto newVertex = new Node(X, Y, name);
    vertices[vertices.size() -1] = newVertex;

    std::vector<Edge*> v;
    for (size_t i = 0; i < vertices.size(); ++i) {
        v.push_back(new Edge);
    }
    edges.push_back(v);

    for (size_t i = 0; i < vertices.size()-1; i++) {
        edges[i].push_back(new Edge);
    }

    return newVertex;
}

void graph::removeNode(Node *n)
{
    int index =getIndex(n);
    vertices.erase(vertices.begin()+index);
    edges.erase(edges.begin()+ index);

    for (size_t i = 0; i < vertices.size(); ++i) {
        edges[i].erase(edges[i].begin()+index);
    }
}

Edge *graph::addEdge(Node *from, Node *to, int weight)
{
    int fromVertexID, toVertexID, count =0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        if(vertices[i]->name==from->name) {
            fromVertexID = i;
            count++;
        }

        if(vertices[i]->name==to->name) {
            toVertexID = i;
            count++;
        }

        if(count==2) {
            break;
        }

    }

    edges[fromVertexID][toVertexID] = new Edge(weight);

    return edges[fromVertexID][toVertexID];
}

void graph::removeEdge(Edge *e)
{
    e->isEmpty = true;
    e->weight = false;

}

std::vector<Edge *> graph::edgesFrom(Node *n)
{
    std::vector<Edge*> result;
    int index = getIndex(n);
    for (auto edge : edges[index]) {
        if(!edge->isEmpty)
            result.push_back(edge);
    }
    return result;
}

std::vector<Edge *> graph::edgesTo(Node *n)
{
    std::vector<Edge*> result;
    int index = getIndex(n);
    for (auto edge : edges) {
        if(!edge[index]->isEmpty)
            result.push_back(edge[index]);
    }
    return result;
}

Node *graph::findVertex(std::string name)
{
    Node* n = nullptr;
    for (auto vertex : vertices) {
        if(vertex->name == name)
            return vertex;
    }
    return n;
}

Edge *graph::findEdge(std::string from_name, std::string to_name)
{
    auto from = new Node(-1,-1 , from_name);
    auto to = new Node(-1,-1, to_name);
    return edges[getIndex(from)][getIndex(to)];
}

bool graph::hasEdge(Node *firstNode, Node *secondNode)
{
    int x = getIndex(firstNode);
    if (x==-1) return false;
    int y = getIndex(secondNode);
    if (y==-1) return false;
    return edges[getIndex(firstNode)][getIndex(secondNode)]->isEmpty = false;
}
