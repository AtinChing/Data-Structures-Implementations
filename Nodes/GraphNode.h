// Simple graph node declaration that will be used a lot in the other graph theory algorithms
#include <vector>
class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<GraphNode*> adj;  // List of adjacent nodes (neighbors)

    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}

    // Add an edge to an adjacent node
    void addEdge(GraphNode* neighbor) {
        adj.push_back(neighbor);
    }
};
