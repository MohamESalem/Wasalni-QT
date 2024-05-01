#include "graph.h"
#include <limits>
#include <queue>
Graph::Graph() {}

void Graph::addCity(City &city)
{
    // Check if the city already exists in the graph
    if (adjList.find(city) == adjList.end()) {
        // If not, add it to the adjacency list
        adjList[city] = std::vector<std::pair<City, int>>();
        qDebug() << "Added city:" << city.getText()->toPlainText();
    } else {
        qDebug() << "City already exists";
    }
}

void Graph::addEdge(City &source, City &destination, int weight)
{
    // Check if both cities exist in the graph
    if (adjList.find(source) != adjList.end() && adjList.find(destination) != adjList.end()) {
        // Add the edge from source to destination with the specified weight
        adjList[source].push_back(std::make_pair(destination, weight));
        qDebug() << "Added edge from " << source.getText()->toPlainText() << " to "
                 << destination.getText()->toPlainText() << " with weight " << weight;
    } else {
        qDebug() << "One or both cities don't exist in the graph";
    }
}

std::pair<int, std::vector<City>> Graph::dijkstra(City &source, City &destination)
{
    std::map<City, int> distances;
    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        distances[it->first] = INT_MAX;
    }

    distances[source] = 0;

    std::priority_queue<std::pair<int, City>,
                        std::vector<std::pair<int, City>>,
                        std::greater<std::pair<int, City>>>
        pq;
    pq.push(std::make_pair(0, source));

    std::map<City, City> previous;

    while (!pq.empty()) {
        City current = pq.top().second;
        pq.pop();

        if (current == destination) {
            break;
        }
        for (auto it = adjList[current].begin(); it != adjList[current].end(); ++it) {
            City neighbor = it->first;
            int weight = it->second;
            int newDistance = distances[current] + weight;
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                previous[neighbor] = current;
                pq.push(std::make_pair(newDistance, neighbor));
            }
        }
    }

    std::vector<City> path;
    if (distances[destination] != INT_MAX) {
        City current = destination;
        while (current != source) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
    }

    return std::make_pair(distances[destination], path);
}
