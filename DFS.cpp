#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,M,a,b,u,v;
vector<int> adj[MAXN];
vector<int> ans;
bool vs[MAXN];

void DFS(int u) {
  ans.push_back(u);
  vs[u] = true;
  for (int &v : adj[u])
    if (!vs[v]) DFS(v);
}

void DFS1() {
   stack<int> st;
   st.push(1);
   while (!st.empty()) {
    u = st.top();
    st.pop();
    if (vs[u]) continue; // có dòng này để tránh bị lặp đỉnh
    vs[u] = true;
    ans.push_back(u);
    for (int &v : adj[u])
        if (!vs[v]) st.push(v);
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
 DFS1();
 for (int &u : ans)  cout << u << " ";

}
