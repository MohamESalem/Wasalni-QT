#include "graph.h"
#include "stack"
#include "queue"
#include "edge.h"
#include <QGraphicsScene>
#include "mainwindow.h"

extern MainWindow* w;

Graph::Graph() {
    // std::vector<City*>path = dijkstra(c1,c3).second;
    // for(auto&c:path) qDebug() << c->getName();
    // removeCity(c1);
    // removeEdge(c3,c1);
    // printGraph();

}

void Graph::addCity(City* city)
{
    // Check if the city already exists in the graph
    if (findCity(city->getName()) == NULL && adjList.find(city) == adjList.end()) {
        // If not, add it to the adjacency list
        adjList[city] = std::vector<std::pair<City*, int>>();
        w->getMap()->getScene()->addItem(city);
        // qDebug() << "Added city:" << city->getText()->toPlainText();
    } else {
        // output error message
        qDebug() << "City already exists";
    }
}

void Graph::addEdge(City* source, City* destination, int weight)
{
    // Check if both cities exist in the graph
    if (source != NULL && destination != NULL &&
        adjList.find(source) != adjList.end() && adjList.find(destination) != adjList.end()) {
        // Add the edge from source to destination with the specified weight
        adjList[source].push_back(std::make_pair(destination, weight));
        adjList[destination].push_back({source,weight});
        Edge* l = new Edge(source->getX(),source->getY(),destination->getX(),destination->getY(),weight);
        w->getMap()->getScene()->addItem(l);
        edgesv.push_back(l);
        // qDebug() << "Added edge from " << source->getText()->toPlainText() << " to "
                 // << destination->getText()->toPlainText() << " with weight " << weight;
    } else {
        qDebug() << "One or both cities don't exist in the graph";
    }
    // printGraph();
}
void Graph::removeCity(City* city)
{
    // Check if the city exists in the graph
    if (city != NULL && adjList.find(city) != adjList.end()) {
        // Remove all edges associated with the city
        for (auto it = adjList.begin(); it != adjList.end(); ++it) {
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
                if (jt->first == city) {
                    removeEdge(it->first,jt->first);
                    it->second.erase(jt);

                    break;
                }
            }
        }

        // Remove the city itself from the adjacency list
        w->getMap()->getScene()->removeItem(city);
        adjList.erase(city);

        // qDebug() << "Removed city:" << city->getText()->toPlainText();
    } else {
        // output error message and comment qDebug()
        qDebug() << "City not found in the graph";
    }
    // printGraph();
}
void Graph::removeEdge(City* source, City* destination)
{
    bool found = false;

    // Check if both cities exist in the graph
    if (source != NULL && destination != NULL &&
        adjList.find(source) != adjList.end() && adjList.find(destination) != adjList.end()) {
        // Find the edge and remove it
        for (auto it = adjList[source].begin(); it != adjList[source].end(); ++it) {
            if (it->first == destination) {
                adjList[source].erase(it);
                found = true;
                break;
                // qDebug() << "Removed edge from " << source->getText()->toPlainText() << " to "
                         // << destination->getText()->toPlainText();
            }
        }
        for (auto it = adjList[destination].begin(); it != adjList[destination].end(); ++it) {
            if (it->first == source) {
                adjList[destination].erase(it);
                break;
                // qDebug() << "Removed edge from " << source->getText()->toPlainText() << " to "
                // << destination->getText()->toPlainText();
            }
        }
        if(!found) {
            // output an error mesage in the main window - comment the qDebug()
            qDebug() << "Edge not found between " << source->getText()->toPlainText() << " and "
                     << destination->getText()->toPlainText();
        } else {
            for(int i=0;i<int(edgesv.size());i++)
            {
                if(((edgesv[i]->xi==source->getX()&&edgesv[i]->yi==source->getY())
                     &&(edgesv[i]->xe==destination->getX()&&edgesv[i]->ye==destination->getY()))
                    || ((edgesv[i]->xi==destination->getX()&&edgesv[i]->yi==destination->getY())
                        &&(edgesv[i]->xe==source->getX()&&edgesv[i]->ye==source->getY()) ))
                {
                    // qDebug() << "Entered Here\n";
                    w->getMap()->getScene()->removeItem(edgesv[i]);
                }
            }
        }
    } else {
        qDebug() << "One or both cities don't exist in the graph";
    }
    // printGraph();
}
bool Graph::isEdgeExist(City* source, City* destination) {
    // Check if both source and destination cities exist in the graph
    if (adjList.find(source) != adjList.end() && adjList.find(destination) != adjList.end()) {
        // Iterate through the adjacency list of the source city
        for (const auto& edge : adjList[source]) {
            // Check if the destination city is connected to the source city
            if (edge.first == destination) {
                return true; // Edge exists
            }
        }
    }
    return false; // Edge doesn't exist or one or both cities don't exist
}


bool Graph::isPathExist(City *c1, City *c2)
{
    if(c1 == c2) return true;
    // do a DFS traversal using stacks
    std::map<City*,bool> visited;
    std::stack<City*> st;
    visited[c1] = true;
    st.push(c1);
    while(!st.empty()) {
        City* curr = st.top();
        st.pop();
        for(auto& obj : adjList[curr]) {
            City* adjCity = obj.first;
            if(adjCity == c2) return true;
            if(!visited[adjCity]) {
                st.push(adjCity);
                visited[adjCity] = true;
            }
        }
    }
    return false;
}

City *Graph::findCity(QString n)
{
    for(auto it=adjList.begin();it!=adjList.end();it++)
    {
        if (it->first->getName()==n)
        {
            return it->first;
        }
    }
    return NULL;
}

std::pair<int, std::vector<City*>> Graph::dijkstra(City* source, City* destination)
{
    std::map<City*, int> distances;
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        distances[it->first] = INT_MAX;
    }

    distances[source] = 0;

    std::priority_queue<std::pair<int, City*>,
                        std::vector<std::pair<int, City*>>,
                        std::greater<std::pair<int, City*>>>
        pq;

    pq.push(std::make_pair(0, source));

    std::map<City*, City*> previous;

    while (!pq.empty()) {
        City* current = pq.top().second;
        pq.pop();

        if (current == destination) {
            break;
        }
        for (auto it = adjList[current].begin(); it != adjList[current].end(); ++it) {
            City* neighbor = it->first;
            int weight = it->second;
            int newDistance = distances[current] + weight;
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                previous[neighbor] = current;
                pq.push(std::make_pair(newDistance, neighbor));
            }
        }
    }

    std::vector<City*> path;
    if (distances[destination] != INT_MAX) {
        City* current = destination;
        while (current != source) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
    }

    return std::make_pair(distances[destination], path);
}
void Graph::printGraph() const
{
    qDebug() << "Graph:";
    for (const auto& entry : adjList) {
        qDebug() << "City:" << entry.first->getName();
        qDebug() << "Adjacent Cities:";
        for (const auto& edge : entry.second) {
            qDebug() << "- " << edge.first->getName() << " (Weight: " << edge.second << ")";
        }
    }
}

std::vector<Edge *> Graph::getEdgesVector()
{
    return edgesv;
}

std::map<City *, std::vector<std::pair<City *, int> > > Graph::getAdjList()
{
    return adjList;
}

void Graph::clearAdjList()
{
    adjList.clear();
}
