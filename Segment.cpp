#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,u,Q,type,v;
int a[MAXN],st[4*MAXN];

void build(int id, int l, int r) {
 if (l == r) {
    st[id] = a[l];
    return;
 }
 int mid = (l+r)>>1;
 build(id*2,l,mid);
 build(id*2+1,mid+1,r);
 st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int u, int val) {
 if (u < l || r < u) return;
 if (l == r) {
    st[id] = val;
    return;
 }
 int mid = (l+r)>>1;
 update(id*2,l,mid,u,val);
 update(id*2+1,mid+1,r,u,val);
 st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
 if (v < l || r < u) return 0;
 if (u <= l && r <= v) return st[id];
 int mid = (l+r)>>1;
 return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

int main() {
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 freopen("INPUT.INP","r",stdin);
 freopen("OUTPUT.OUT","w",stdout);
 cin >> N >> Q;
 for (int i = 1; i <= N; i++) cin >> a[i];
 build(1,1,N);

 while (Q--) {
    cin >> type >> u >> v;
    if (type == 1) cout << get(1,1,N,u,v) << "\n";
    if (type == 2) update(1,1,N,u,v);
 }
}
