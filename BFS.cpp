#include <iostream>
#include <queue>
#include <limits>
#include <vector>

class Vertex{
public:
    int id; // unique identifier for vertex
    int distance; // distance from source
    Vertex* path; // previous vertex in path
    std::vector<Vertex*> neighbors; // adj list vertices

    // Constructor(s)
    Vertex(int _id) : id(_id), distance(std::numeric_limits<int>::max()), path(nullptr) {}

    // Add a neighbor (directed or undirected)
    void addNeighbor(Vertex* neighbor) {
        neighbors.push_back(neighbor);
    }

    // Check if a vertex is a neighbor (directed or undirected)
    bool isNeighbor(Vertex *neighbor) const {
        return std::find(neighbors.begin(), neighbors.end(), neighbor) != neighbors.end();
    }
};

class Graph{
public:

    std::vector<Vertex> vertices;

    void BFS(Vertex &s){

        std::queue<Vertex*> q;

        for (auto v : vertices){
            v.distance = std::numeric_limits<int>::max(); // initialize v.distance 
        }
        s.distance = 0;
        q.push(&s);

        while(!q.empty()){
            Vertex* v = q.front(); // process next V every cycle
        //    if (v.neighbors.size() > 1){
        //         std::cout << "Check\n";
        //     }
        //     std::cout << v.distance;

            // for each Vertex w adjacent to v (use adjacency list)
            for (auto w : q.front()->neighbors){
                // std::cout << w->distance;
                if(w->distance == std::numeric_limits<int>::max()){
                    w->distance = v->distance + 1;
                    w->path = v;
                    q.push(w);
                }
            }
            q.pop();
        }

        for (auto vertex : vertices){
            std::cout << vertex.distance << std::endl;
        }
    }
};

int main() {
  // Create a graph with some vertices and edges
  Graph graph;
  Vertex v1(1), v2(2), v3(3), v4(4), v5(5);
  v1.addNeighbor(&v2); v1.addNeighbor(&v4);
  v2.addNeighbor(&v1); v2.addNeighbor(&v3);
  v3.addNeighbor(&v2); v3.addNeighbor(&v5);
  v4.addNeighbor(&v1); v4.addNeighbor(&v5);
  v5.addNeighbor(&v3); v5.addNeighbor(&v4);
  graph.vertices.push_back(v1); graph.vertices.push_back(v2);
  graph.vertices.push_back(v3); graph.vertices.push_back(v4);
  graph.vertices.push_back(v5);

  // Start BFS from vertex 1 and print distances
//   Vertex source = graph.vertices[0]; // Assume v1 is the source
  graph.BFS(graph.vertices[0]);
  std::cout << "Distances from source vertex " << graph.vertices[0].id << ":" << std::endl;
  for (const auto& vertex : graph.vertices) {
    if (vertex.distance == std::numeric_limits<int>::max()) {
      std::cout << "\tVertex " << vertex.id << ": unreachable" << std::endl;
    } else {
      std::cout << "\tVertex " << vertex.id << ": distance " << vertex.distance << std::endl;
    }
  }
  return 0;
}
