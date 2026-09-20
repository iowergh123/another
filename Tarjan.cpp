#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,M,u,v,timer;
int num[MAXN],low[MAXN];
vector<int> adj[MAXN];
vector<bool> is_joint(MAXN);
vector<pair<int,int>> bridges;

void DFS(int u,int p) {
  int child_count = 0;
  low[u] = num[u] = ++timer;
  for (int &v : adj[u]) {
    if (v==p) continue;
    if (num[v] > 0) low[u] = min(low[u],num[v]);
    else {
        child_count++;
        DFS(v,u);
        low[u] = min(low[v],low[u]);
        if (low[v] > num[u]) bridges.emplace_back(u,v);
        if (low[v] >= num[u] && p != 0) is_joint[u] = true;
    }
  }
  if (child_count > 1 && p == 0) is_joint[u] = true;
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
 DFS(1,0);
 for (pair<int,int> x : bridges)
    cout << x.first << " " << x.second << "\n";
 for (int i = 1; i <= N; i++) cout << is_joint[i] << " ";

}
