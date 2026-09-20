#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
int N,u,v,val,type,Q;
int st[4*MAXN],a[MAXN],lz[4*MAXN],memst[4*MAXN];

void build(int id, int l, int r) {
 if (l==r) {
    st[id] = a[l];
    memst[id] = 1;
    return;
 }
 int mid = (l+r)>>1;
 build(id*2,l,mid);
 build(id*2+1,mid+1,r);
 st[id] = st[id*2] + st[id*2+1];
 memst[id] = memst[id*2]+memst[id*2+1];
}

void push(int id) {
 lz[id*2] += lz[id];
 st[id*2] += lz[id]*memst[id*2];
 lz[id*2+1] += lz[id];
 st[id*2+1] += lz[id]*memst[id*2+1];
 lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
 if (v < l || r < u) return;
 if (u <= l && r <= v) {
    lz[id] += val;
    st[id] += memst[id]*val;
    return;
 }
 push(id);
 int mid = (l+r)>>1;
 update(id*2,l,mid,u,v,val);
 update(id*2+1,mid+1,r,u,v,val);
 st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v) {
 if (v < l || r < u) return 0;
 if (u <= l && r <= v) return st[id];
 push(id);
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
    cin >> type >> u >> v >> val;
    if (type == 1) cout << get(1,1,N,u,v) << "\n";
    if (type == 2) update(1,1,N,u,v,val);
 }
}
