#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,M,u,v,d,x,timer;
int low[MAXN],num[MAXN];
vector<int> adj[MAXN];
vector<int> SCC[MAXN];
bitset<MAXN> in_stack;
stack<int> st;

void DFS(int u) {
  low[u] = num[u] = ++timer;
  in_stack[u] = true;
  st.emplace(u);

  for (int v : adj[u]) {
        if (num[v] == 0) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (num[u]==low[u]) {
         d++;
         while (true) {
            x = st.top();
            st.pop();
            in_stack[x] = false;
            SCC[d].emplace_back(x);
            if (x == u) break;
         }
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
 }
 DFS(1);
 for (int i = 1; i <= d; i++) {
    for (int x : SCC[i]) cout << x << " ";
    cout << "\n";
 }

}
