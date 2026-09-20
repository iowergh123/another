#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int tin[MAXN],tout[MAXN];
int timer,N,M,u,v;
vector<int> adj[MAXN];

void DFS(int u) {
 tin[u] = ++timer;
 for (int &v : adj[u])
    if (tin[v] == 0) DFS(v);
 tout[u] = timer;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N >> M;
 for (int i = 1; i <= M; i++) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
 }
 DFS(1);
 for (int i = 1; i <= N; i++)
    cout << tin[i] << " " << tout[i] << "\n";
}

