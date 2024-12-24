#include <vector>
#include <utility>
class GraphNode {
public:
    int val;  // Value or identifier for the node
    std::vector<std::pair<GraphNode*, int>> adj;  // List of adjacent nodes (neighbors)

    // Constructor to initialize the node with a value
    GraphNode(int x) : val(x) {}
    int getInd(GraphNode* neighbor, int weight){
        for(int i = 0; i < adj.size(); i++){if(adj[i].first == neighbor && adj[i].second == weight) return i;}
    }
    // Add an edge to an adjacent node
    void addEdge(GraphNode* neighbor, int weight) {
        adj.push_back(std::make_pair(neighbor, weight));
    }
    void removeEdge(GraphNode* neighbor, int weight){
        adj.erase(adj.begin() + getInd(neighbor, weight));
    }
};