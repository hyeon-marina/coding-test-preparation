#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<vector<int>> adj(n + 1);
    for (auto &e : roads) {
        int a = e[0], b = e[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[destination] = 0;
    q.push(destination);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : adj[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }

    vector<int> ans;
    ans.reserve(sources.size());
    for (int s : sources) ans.push_back(dist[s]);
    return ans;
}
