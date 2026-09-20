#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,Q,u,v;
int st[MAXN][22],a[MAXN];

void prepare() {
 for (int i = 1; i <= N; i++) st[i][0] = a[i];
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i + (1 << j) - 1 <= N; i++)
     st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int get(int L,int R) {
 int d = R - L + 1;
 int k = __lg(d);
 return max(st[L][k],st[R-(1<<k)+1][k]);
}
int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N >> Q;
 for (int i = 1; i <= N; i++) cin >> a[i];
 prepare();
 while (Q--) {
    cin >> u >> v;
    cout << get(u,v) << "\n";
 }
}
