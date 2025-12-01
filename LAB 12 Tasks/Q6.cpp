#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

void dijkstra(map<string, vector<pair<string,int>>> &graph, string src, string dest) {
    map<string, int> dist;
    map<string, string> parent;

    for (auto &n : graph)
        dist[n.first] = INT_MAX;

    dist[src] = 0;

    priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        greater<pair<int,string>>
    > pq;

    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        string u = top.second;

        if (d > dist[u]) continue;

        for (auto &edge : graph[u]) {
            string v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distance B → E = " << dist[dest] << endl;

    cout << "Path: ";
    vector<string> path;
    string cur = dest;

    while (cur != src) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(src);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i) cout << " -> ";
    }
    cout << endl;
}

int main() {
    map<string, vector<pair<string,int>>> graph;

    graph["B"] = {{"A",4},{"C",9}};
    graph["A"] = {{"B",4},{"D",8}};
    graph["C"] = {{"B",9},{"D",6},{"E",14}};
    graph["D"] = {{"A",8},{"C",6},{"F",4}};
    graph["F"] = {{"D",4},{"E",3}};
    graph["E"] = {{"C",14},{"F",3}};

    dijkstra(graph, "B", "E");

    return 0;
}
 