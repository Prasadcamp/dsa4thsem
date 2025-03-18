#include <iostream>
#include <string>

using namespace std;

// Define the Edge structure
struct Edge {
    int destination;  // Index of the adjacent vertex
    int weight;       // Weight of the edge
    Edge* next;       // Pointer to the next edge (linked list)

    // Constructor to initialize edge
    Edge(int dest, int w) : destination(dest), weight(w), next(nullptr) {}
};

// Define the Vertex structure
struct Vertex {
    string name;      // Vertex name (or identifier)
    Edge* adjListHead; // Head pointer to the adjacency list (multilist)

    // Constructor to initialize the vertex
    Vertex(string vertexName) : name(vertexName), adjListHead(nullptr) {}
};

// Define the Graph structure
class Graph {
private:
    Vertex** vertices; // Array of vertices
    int numVertices;   // Total number of vertices

public:
    // Constructor to initialize the graph with a fixed number of vertices
    Graph(int n) : numVertices(n) {
        vertices = new Vertex*[numVertices];
    }

    // Destructor to clean up memory
    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete vertices[i];
        }
        delete[] vertices;
    }

    // Add a vertex to the graph (initialize it)
    void addVertex(int index, string vertexName) {
        if (index >= 0 && index < numVertices) {
            vertices[index] = new Vertex(vertexName);
        }
    }

    // Add an edge between two vertices (by their indices)
    void addEdge(int fromIndex, int toIndex, int weight) {
        if (fromIndex >= 0 && fromIndex < numVertices &&
            toIndex >= 0 && toIndex < numVertices) {
            // Create a new edge from "from" to "to" with the given weight
            Edge* newEdge = new Edge(toIndex, weight);

            // Insert the edge into the adjacency list of the "from" vertex
            newEdge->next = vertices[fromIndex]->adjListHead;
            vertices[fromIndex]->adjListHead = newEdge;
        }
    }

    // Display the graph (adjacency multilist)
    void display() {
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << vertices[i]->name << ": ";
            Edge* edge = vertices[i]->adjListHead;
            while (edge != nullptr) {
                cout << "(" << vertices[edge->destination]->name << ", " << edge->weight << ") ";
                edge = edge->next;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add vertices to the graph
    graph.addVertex(0, "A");
    graph.addVertex(1, "B");
    graph.addVertex(2, "C");
    graph.addVertex(3, "D");
    graph.addVertex(4, "E");

    // Add edges between vertices with weights
    graph.addEdge(0, 1, 3);  // A -> B (weight 3)
    graph.addEdge(0, 2, 5);  // A -> C (weight 5)
    graph.addEdge(1, 3, 2);  // B -> D (weight 2)
    graph.addEdge(2, 4, 4);  // C -> E (weight 4)

    // Display the graph's adjacency multilist
    graph.display();

    return 0;
}

