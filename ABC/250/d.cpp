#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc250/tasks/abc250_d

vector<ll> p, e(1000001);
vector<ll> p_c;
void init_p(){
    rep(i, 2, 1000001){
        if(e[i] == 0){
            p.push_back(i);
            for(int j = i; j < 1000001; j += i) e[j] = 1;
        }
    }
}

int main(){
    ll n; cin >> n;
    init_p();
    for(auto pp: p){
        p_c.push_back(pp*pp*pp);
    }

    ll ans = 0;


    for(auto pp: p){
        if(pp >= n) break;
        auto itr_ = upper_bound(p_c.begin(), p_c.end(), n/pp);
        auto itr = upper_bound(p_c.begin(), p_c.end(), pp*pp*pp);
        if(itr_-itr > 0){
            ans += itr_-itr;
        }
        ++itr;
    }
    cout << ans << endl;

    
    return 0;
}