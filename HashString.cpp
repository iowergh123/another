#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef long long ll;

int BASE;
const ll MOD1 = 1000000141;
const ll MOD2 = 2000000087;
const int MAXN = 200005;

ll POW1[MAXN];
ll POW2[MAXN];
ll H1[MAXN];
ll H2[MAXN];

int n;
string s;

void pre() {

    POW1[0] = 1;
    POW2[0] = 1;
    for (int i = 1; i <= n; i++) {
        POW1[i] = (POW1[i - 1] * BASE) % MOD1;
        POW2[i] = (POW2[i - 1] * BASE) % MOD2;
    }

    for (int i = 1; i <= n; i++) {
        H1[i] = (H1[i - 1] * BASE + s[i] - 'a' + 1) % MOD1;
        H2[i] = (H2[i - 1] * BASE + s[i] - 'a' + 1) % MOD2;
    }
}

pair<ll,ll> get(int L, int R) {
    ll fv = (H1[R] - H1[L - 1] * POW1[R - L + 1] + MOD1 * MOD1) % MOD1;
    ll sv = (H2[R] - H2[L - 1] * POW2[R - L + 1] + MOD2 * MOD2) % MOD2;
    return {fv,sv};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(311, 1000000000);
    BASE = dist(rng);
    cin >> n;
    cin >> s;
    s = " " + s;
    pre();
    pair<ll,ll> a = get(1,3);
    pair<ll,ll> b = get(4,6);
    cout << a.first << " " << a.second << "\n";
    cout << b.first << " " << b.second << "\n";


    return 0;
}
