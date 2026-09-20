#include <bits/stdc++.h>
#define MAXN 200005
#define tiii tuple<int,int,int>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
int up[MAXN][20],depth[MAXN];
int mn[MAXN][20],mx[MAXN][20];
vector<pii> adj[MAXN];
int u,v,N,M,K,w;

void DFS(int u) {
 for (pii x : adj[u]) {
    tie(v,w) = x;
    if (up[v][0] == 0 && v != 1) {
       up[v][0] = u;
       mn[v][0] = w;
       mx[v][0] = w;
       depth[v] = depth[u] + 1;
       DFS(v);
    }
 }
}

void prepare() {
 DFS(1);
 for (int j = 1; j <= 18; j++)
    for (int i = 1; i <= N; i++) {
        up[i][j] = up[up[i][j-1]][j-1];
        mn[i][j] = min(mn[i][j-1],mn[up[i][j-1]][j-1]);
        mx[i][j] = max(mx[i][j-1],mx[up[i][j-1]][j-1]);
    }
}

void solve(int u, int v) {
 int mnr = 1e9;
 int mxr = -1e9;
 if (depth[v] > depth[u]) swap(u,v);
 int d = depth[u] - depth[v];
 for (int i = 0; i <= 18; i++) {
    if ((d >> i) & 1) {
       mnr = min(mnr,mn[u][i]);
       mxr = max(mxr,mx[u][i]);
       u = up[u][i];
    }
 }
 if (u == v) {
    cout << mnr << " " << mxr << " " << u;
    return;
 }

 for (int i = 18; i >= 0; i--) {
    if (up[u][i] != up[v][i]) { // Nhớ rằng phải kiểm tra trước để mỗi bước nhảy đều nhảy trong phạm vi hợp lệ
    mnr = min({mnr,mn[v][i],mn[u][i]});
    mxr = max({mxr,mx[v][i],mx[u][i]});
    u = up[u][i];
    v = up[v][i];
    }
 }
 mnr = min({mnr,mn[v][0],mn[u][0]});
 mxr = max({mxr,mx[v][0],mx[u][0]});
 u = up[u][0];
 cout << mnr << " " << mxr << " " << u;
 return;
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N;
 for (int i = 1; i <= N-1; i++) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v,w);
    adj[v].emplace_back(u,w);
 }
 cin >> K;
 prepare();
 while(K--) {
    cin >> u >> v;
    solve(u,v);
    cout << "\n";
 }

}
