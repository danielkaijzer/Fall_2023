/*
Given the root of a binary tree,
return the level order traversal
of its nodes' values.
(i.e., from left to right, level by level)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits>


using namespace std;

class Graph{
public:
    int vertices;
    vector<vector<pair<int,int>>> adjList; // Pair {vertex_id, weight}

    // Constructor
    Graph(int v) : vertices(v), adjList(v) {}

    // Method for adding edges to graph
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        // adjList[v].push_back({u, weight});  // For undirected graph
    }

    /**
     * @brief Method for implementing Dijkstra's Algorithm
     * @post Prints shortest distances from a node S
     *       to all other nodes in graph
     */
    void dijkstra(int S){
        // Initialize distances to all vertices as infinity
        vector<int> distance(vertices, INT_MAX);

        // Distance from start node to itself is 0
        distance[S] = 0;

        // Priority queue to store {distance, vertex} pairs
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        // Enqueue the start node with distance 0
        pq.push({0, S});

        // Dijkstra's Algorithm main loop
        while(!pq.empty()){
            // Get the vertex with the smallest known distance
            int current = pq.top().second; // Current vertex
            int currentDistance = pq.top().first; // Current distance

            pq.pop();

            // Check if the current distance is already greater than the stored distance
            if (currentDistance > distance[current]) {
                continue; // skip to next iteration of loop
            }

            // Explore neighbors of the current node
            for (auto neighbor : adjList[current]){
                int next = neighbor.first;
                int weight = neighbor.second;

                // "Relaxation step", "stop and rest"
                // Update distance if shorter path found
                if (distance[current] + weight < distance[next]){
                    // note that distance[next] is current known shortest distance
                    // since we found a shorter distance, 
                    // update current known shortest distance for this neighbor
                    distance[next] = distance[current] + weight;

                    // Enqueue updated distance and vertex for further exploration
                    pq.push({distance[next], next});
                }
            }
        }


        // Print shortest distances from Start node to all other nodes
        cout << "Shortest distances from node " << S << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "To node " << i << ": " << distance[i] << endl;
        }
    }
};


int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add directed edges with weights to the graph
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    // Run Dijkstra's algorithm starting from node 0
    g.dijkstra(0);

    return 0;
}