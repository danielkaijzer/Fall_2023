#include <iostream>
#include <queue>
#include <limits>
#include <vector>

class Vertex{
public:
    int id; // unique identifier for vertex
    int distance; // distance from source
    bool known;
    Vertex* path; // previous vertex in path
    std::vector<std::pair<Vertex*,int>> neighbors; // adj list vertices

    // Constructor(s)
    Vertex(int _id) : id(_id), distance(std::numeric_limits<int>::max()), known(false), path(nullptr) {}

    // Add a neighbor (directed or undirected)
    void addNeighbor(Vertex *neighbor, int _weight) {
        neighbors.push_back(std::make_pair(neighbor,_weight));
    }

    // Check if a vertex is a neighbor (directed or undirected)
    bool isNeighbor(Vertex *neighbor) const {
        return std::find(neighbors.begin(), neighbors.end(), neighbor) != neighbors.end();
    }
};

class Compare{
    public:
        bool compareVertices(const Vertex& lhs, const Vertex& rhs) {
        // prioritize based on distance and then ID as tiebreaker
        if (lhs.distance < rhs.distance) {
            return true;
        } else if (lhs.distance == rhs.distance) {
            return lhs.id < rhs.id;
        } else {
            return false;
        }
    }
};

class Graph{
public:
    std::vector<Vertex> vertices;

    void Graph::Dijkstra(Vertex s){
        std::queue<Vertex> unknown;
        // std::priority_queue<Vertex, std::vector<Vertex>, Compare> unknown;


        for (auto v : vertices){
            v.distance = std::numeric_limits<int>::max(); // initialize v.distance 
            v.known = false;
        }
        s.distance = 0;

        unknown.push(s); // push start vertex, pass comparator explicitly

        while(!unknown.empty()){ // while there is an unknown vertex

            // Vertex v = smallest unknown vertex
            Vertex* v = &unknown.front();
            unknown.pop();

            v->known = true;

            // for each Vertex w adjacent to v (use adjacency list)
            for (int i = 0; i < v->neighbors.size(); ++i){
                auto w = v->neighbors[i];

                if(!w.first->known){
                    int edge_cost = w.second; // need to get weights working

                    if (v->distance + edge_cost < w.first->distance){
                        // Update w
                        w.first->distance = v->distance + edge_cost;
                        w.first->path = v;
                        unknown.push(*w.first);
                    }
                }
            }
        }
    }

    void Graph::printPath(Vertex* v){
        if (v->path != nullptr){
            printPath(v->path);
            std::cout << " to ";
        }
        std::cout << v->id;
    }
};

int main(){
  // Create a graph with some vertices and edges
  Graph graph;
  Vertex* v1 = new Vertex(1);
  Vertex* v2 = new Vertex(2);
  Vertex* v3 = new Vertex(3);
  Vertex* v4 = new Vertex(4);
  graph.vertices.push_back(*v1);
  graph.vertices.push_back(*v2);
  graph.vertices.push_back(*v3);
  graph.vertices.push_back(*v4);

  v1->addNeighbor(v2, 4);
  v1->addNeighbor(v3, 2);
  v2->addNeighbor(v4, 1);
  v3->addNeighbor(v4, 5);

  // Choose a starting vertex
  Vertex start = *v1;

  // Run Dijkstra's algorithm
  graph.Dijkstra(start);

  // Print the shortest paths from the starting vertex
  std::cout << "Shortest paths from vertex " << start.id << ":" << std::endl;
  for (auto& v : graph.vertices) {
    if (v.id != start.id) {
      graph.printPath(&v);
      std::cout << " (distance: " << v.distance << ")" << std::endl;
    }
  }
}