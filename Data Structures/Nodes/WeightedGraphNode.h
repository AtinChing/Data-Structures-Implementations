#include <vector>
#include <utility>
class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<pair<GraphNode*, int>> adj;  // List of adjacent nodes (neighbors)

    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}

    // Add an edge to an adjacent node
    void addEdge(GraphNode* neighbor, int weight) {
        adj.push_back(make_pair(neighbor, weight));
    }
};
