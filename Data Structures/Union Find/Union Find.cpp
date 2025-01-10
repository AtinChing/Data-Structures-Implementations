#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <set>
using namespace std;
template<typename T>
// this unionfind implementation is intended for GraphNode
class UnionFind {
    private:
        int pointsTo[]; // parent of each elem. holds pointer to parents of each elem
        int size; // num of components
        int sizeGroup[]; // size of each component
        int numComponents; // number of components
        unordered_map<int, T*> map; // each number maps to an element. this number is the graph val
    public:
        UnionFind(int size, T* elements){
            this->size = size = numComponents;
            pointsTo = int[size];  
            for(auto node: elements){
                pointsTo[node.val] = node.val; // every element initially points to itself
                map[node.val] = node; // node values used to determine their index in internal array
            }
        }
        T find(T elem){ // finds root that this element actually points to
            int currentIndex = elem.val;
            while(currentIndex != pointsTo[currentIndex]){ // while node not pointing to itself, so its pointing to another node and root not discovered/reached yet
                currentIndex = pointsTo[currentIndex];
            }
            int rootIndex = currentIndex;
            currentIndex = map1[elem];
            while(currentindex != pointsTo[currentIndex]){
                int next = pointsTo[currentIndex];
                pointsTo[currentIndex] = rootIndex;
                currentIndex = next;
            }

        }
        T unify(T elem1, T elem2){
            int root1 = find(elem1);
            int root2 = find(elem2);
            if(root1 == root2){return;} // already unified
            if(sizeGroup[root1] > sizeGroup[root2]){

            }
        }
};