    #include <iostream>
    #include <vector>
    #include <array>
    #include <unordered_map>
    #include <set>
    #include "../Nodes/GraphNode.h"
    using namespace std;
    template<typename T>
    // this unionfind implementation is intended for GraphNode
    class UnionFind {
        private:
            vector<int> pointsTo; // parent of each elem. holds pointer to parents of each elem
            int size; // num of components
            vector<int> sizeGroup; // size of each component
            int numComponents; // number of components
            unordered_map<int, T*> map; // each number maps to an element. this number is the graph val
        public:
            UnionFind(int size, T** elements){
                this->size = size;
                numComponents = size;
                pointsTo.resize(size);
                sizeGroup.resize(size, 1);
                for(int i = 0; i < size; i++){ // presuming nodes are sorted in order of value
                    T* node = elements[i];
                    pointsTo[node->val] = node->val; // every element initially points to itself
                    map[node->val] = node; // node values used to determine their index in internal array
                }
            }
            T find(T elem){ // finds root that this element actually points to
                int currentIndex = elem.val;
                while(currentIndex != pointsTo[currentIndex]){ // while node not pointing to itself, so its pointing to another node and root not discovered/reached yet
                    currentIndex = pointsTo[currentIndex];
                }
                int rootIndex = currentIndex;
                currentIndex = map[elem.val];
                while(currentIndex != pointsTo[currentIndex]){
                    int next = pointsTo[currentIndex];
                    pointsTo[currentIndex] = rootIndex;
                    currentIndex = next;
                }
                return map[rootIndex];

            }
            T unify(T elem1, T elem2){
                int root1 = find(elem1);
                int root2 = find(elem2);
                if(root1 == root2){return;} // already unified
                if(sizeGroup[root1] > sizeGroup[root2]){
                    pointsTo[root2] = root1;
                    sizeGroup[root1] += sizeGroup[root2];
                    sizeGroup[root2] = 0;
                }
                else{
                    pointsTo[root1] = root2;
                    sizeGroup[root2] += sizeGroup[root1];
                    sizeGroup[root1] = 0;
                }
                numComponents -= 1;
            }
            int componentSize(int p) {
                return sizeGroup[find(p)];
            }

            int components() {
                return numComponents;
            }
    };
    int main(){
        GraphNode* root = new GraphNode(0);
        GraphNode* B = new GraphNode(1);
        GraphNode* C = new GraphNode(2);
        GraphNode* D = new GraphNode(3);
        GraphNode* E = new GraphNode(4);
        GraphNode* F = new GraphNode(5);
        GraphNode* G = new GraphNode(6);
        GraphNode* H = new GraphNode(7);
        const int count = 8;
        GraphNode* arr[count] = {root, B, C, D, E, F, G, H};
        UnionFind<GraphNode> uf = UnionFind(count, &(arr[0]));
        cout << uf.components() << endl;
        uf.unify(*B, *C);
        cout << uf.components() << endl;
    }