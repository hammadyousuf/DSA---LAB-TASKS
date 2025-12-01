#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printAdjList(vector<vector<int>>& adj) {
    cout << "\nAdjacency List:\n";
    for (int i = 1; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int v : adj[i]) cout << v << " ";
        cout << endl;
    }
}

void printAdjMatrix(vector<vector<int>>& mat) {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i < mat.size(); i++) {
        for (int j = 1; j < mat.size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void BFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

void DFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neigh : adj[node]) {
        if (!visited[neigh])
            DFSUtil(neigh, adj, visited);
    }
}

void DFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    cout << "\nDFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

int main() {

    vector<vector<int>> adj(6);
    vector<vector<int>> mat(6, vector<int>(6, 0));

    vector<pair<int, int>> edges = {
        {1,2}, {1,4}, {2,4}, {2,5}, {3,5}, {4,5}
    };

    for (auto e : edges) {
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mat[u][v] = mat[v][u] = 1;
    }

    printAdjList(adj);
    printAdjMatrix(mat);

    BFS(adj, 1);
    DFS(adj, 1);

    return 0;
}
