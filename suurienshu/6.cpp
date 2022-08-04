#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

ll p[1005], m[1005][1005];
string fk[1005], bk[1005];

ll get_min(ll l, ll r){
    if(m[l][r]){
        return m[l][r];
    }
    if(l == r){
        return m[l][r] = 0;
    }

    ll res = (1LL<<60), pos = l;

    rep(k, l, r){
        ll new_val = get_min(l, k)+get_min(k+1, r)+p[l-1]*p[k]*p[r];
        if(res > new_val){
            res = new_val;
            pos = k;
        }
    }

    if(l != pos){
        fk[l] += '(';
        bk[pos] += ')';
    }
    if(r != pos+1){
        fk[pos+1] += '(';
        fk[r] += ')';
    }

    return m[l][r] = res;
}

int main(){

    int n; cin >> n;
    rep(i, 0, n+1){
        cin >> p[i];
    }

    cout << get_min(1, n) << endl;

    rep(i, 1, n+1){
        cout << fk[i] << i << bk[i];
        if(i < n) cout << ", ";
    }
    cout << endl;
    
    return 0;
}