#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

vector<int> p;
void p_init(){
    rep(i, 2, 1001){
        bool f = true;
        for(auto pp: p){
            if(i%pp == 0){
                f = false;
                break;
            }
        }
        if(f) p.push_back(i);
    }
}

vector<int> a(10005);
map<int, int> max_p;
ll lcm(int n){
    rep(i, 0, n){
        int cpa = a[i], cnt = 0;
        for(auto pp: p){
            if(cpa < pp) break;
            cnt = 0;
            while(cpa%pp == 0){
                cnt++;
                cpa /= pp;
            }
            max_p[pp] = max(max_p[pp], cnt);
        }
        if(cpa != 1 and max_p[cpa] == 0){
            p.push_back(cpa);
            max_p[cpa] = 1;
        }
    }
    ll res = 1LL;
    for(auto pp: p){
        res = (res*(ll)pow(pp, max_p[pp]))%MOD;
    }
    return res;
}

vector<ll> inv(1000001);
void inv_init(){
    inv[1] = 1;
    rep(i, 2, 1000001){
        inv[i] = MOD-(inv[MOD%i]*(MOD/i))%MOD;
    }
}

int main(){
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    p_init();
    ll L = lcm(n);
    inv_init();

    ll ans = 0;
    rep(i, 0, n){
        ans = (ans+L*inv[a[i]])%MOD;
    }
    cout << ans << endl;
}