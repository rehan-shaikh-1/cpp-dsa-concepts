#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct Node {
    int id;
    Node* next;
    Node(int v) : id(v), next(NULL) {}
};

class GraphLandmarks {
    int adjMatrix[10][10];
    Node* adjList[10];
    string landmarks[10] = {"Admin", "Canteen", "Sports", "Workshop", "Library", "Gate", "Hostel"};
    bool visited[10];
    int n;

public:
    GraphLandmarks(int nodes) {

    }

    void addEdge(int u, int v) {

    }

    void resetVisited() {
    }

    void DFS(int u) {

    }

    void BFS(int start) {

    }
};

int main() {
    int nodes, edges, u, v, choice;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    GraphLandmarks g(nodes);

    cout << "Enter number of edges: ";
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);
    }

    do {
        cout << "\n\n1. DFS (Matrix) 2. BFS (List) 3. Exit: ";
        cin >> choice;
        g.resetVisited();
        
        if (choice == 1) {
            cout << "Enter start node: "; cin >> u;
            g.DFS(u);
        } else if (choice == 2) {
            cout << "Enter start node: "; cin >> u;
            g.BFS(u);
        }
    } while (choice != 3);

    return 0;
}