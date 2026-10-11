
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void DFS(int v, vector<int> adj[], bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            DFS(u, adj, visited);
        }
    }
}
void BFS(int start, vector<int> adj[], int n) {
    bool visited[100] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
int main() {
    int n, e, a, b, start;
    cout << "Enter number of buildings: ";
    cin >> n;
    cout << "Enter number of roads: ";
    cin >> e;
    vector<int> adj[100];
    for (int i = 0; i < e; i++) {
        cout << "Enter two connected buildings: ";
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "Enter starting building: ";
    cin >> start;
    bool visited[100] = {false};
    cout << "\nDFS Traversal: ";
    DFS(start, adj, visited);
    cout << "\nBFS Traversal: ";
    BFS(start, adj, n);
    cout << endl;
    return 0;
}
