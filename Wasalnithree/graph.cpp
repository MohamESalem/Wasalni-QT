#include "graph.h"
#include "stack"

Graph::Graph() {}

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
