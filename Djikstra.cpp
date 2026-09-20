#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MAXN 200005
#define INF 1e18
using namespace std;
ll N,M,u,v,d,w;
vector<pll> adj[MAXN];
ll dis[MAXN];

void solve() {
 priority_queue<pll,vector<pll>,greater<pll>> pq;
 pq.emplace(dis[1],1);
 while (!pq.empty()) {
    tie(d,u) = pq.top();
    pq.pop();
    if (d > dis[u]) continue;
    for (pll x : adj[u]) {
        tie(v,w) = x;
        if (d + w < dis[v]) {
            dis[v] = d + w;
            pq.emplace(dis[v],v);
        }
    }
 }
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 fill(dis,dis+MAXN,INF);
 cin >> N >> M;
 for (int i = 1; i <= M; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
 }
 dis[1] = 0;
 solve();
 cout << dis[N];
}
