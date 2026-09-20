#include <bits/stdc++.h>
#define MAXN 200005
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int sz[MAXN],r[MAXN],N,M,u,v,w;
vector<pii> adj[MAXN];
vector<tuple<int,int,int>> e;
vector<pii> ans;

struct dsu {
  void Make() {
    for (int i = 1; i <= N; i++) sz[i] = 1,r[i] = i;
  }
  int Get(int u) {
     if (u == r[u]) return u;
     return r[u] = Get(r[u]);
  }
  bool Unite(int u, int v) {
     u = Get(u);
     v = Get(v);
     if (u == v) return false;
     if (sz[v] > sz[u]) swap(u,v);
     sz[u] += sz[v];
     r[v] = u;
     return true;
  }
};
dsu DSU;

void Kruskal() {
    int cnt = 0;
    for (tiii &x : e) {
        tie(w,u,v) = x;
        if (DSU.Unite(u,v)) {
            ans.emplace_back(u,v);
            cnt++;
        }
      if (cnt == N-1) break;
    }
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N >> M;
 DSU.Make();
 for (int i = 1 ; i <= M; i++) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
    e.emplace_back(w,u,v);
 }
 sort(e.begin(),e.end());
 Kruskal();
 for (pii x : ans) cout << x.first << " " << x.second << "\n";
}
