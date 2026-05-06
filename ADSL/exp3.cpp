#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Node for Adjacency List
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
        n = nodes;
        for (int i = 0; i < 10; i++) {
            adjList[i] = NULL;
            for (int j = 0; j < 10; j++) adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int u, int v) {
        // 1. Update Adjacency Matrix (For DFS)
        adjMatrix[u][v] = adjMatrix[v][u] = 1;

        // 2. Update Adjacency List (For BFS)
        Node* newNode = new Node(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = new Node(u); // Since map paths are usually two-way
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    void resetVisited() {
        for (int i = 0; i < 10; i++) visited[i] = false;
    }

    // DFS using Adjacency Matrix (Recursive)
    void DFS(int u) {
        cout << landmarks[u] << " ";
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] == 1 && !visited[v]) {
                DFS(v);
            }
        }
    }

    // BFS using Adjacency List (Queue)
    void BFS(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << landmarks[u] << " ";

            Node* temp = adjList[u];
            while (temp) {
                if (!visited[temp->id]) {
                    visited[temp->id] = true;
                    q.push(temp->id);
                }
                temp = temp->next;
            }
        }
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