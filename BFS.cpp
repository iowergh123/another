#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,M,u,v;
bool vs[MAXN];
vector<int> ans;
vector<int> adj[MAXN];

void BFS() {
  queue<int> q;
  q.push(1);
  vs[1] = true;
  while (!q.empty()) {
     u = q.front();
     ans.push_back(u);
     q.pop();
     for (int &v : adj[u])
        if (!vs[v]) vs[v] = true,q.push(v);
  }
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
 BFS();
 for (int &u : ans)  cout << u << " ";
}
