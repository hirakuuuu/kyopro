#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/abc101/tasks/arc099_b

ll s(ll n){
    ll m = n, res = 0;
    while(m){
        res += m%10;
        m /= 10;
    }
    return res;
}


int main(){
    ll k; cin >> k;
    vector<ll> p;
    rep(i, 1, 1000){
        string s = to_string(i);
        rep(j, 0, 16){
            if(s.size() > 15) break;
            p.push_back(stoll(s));
            s += '9';
        }
    }
    sort(p.rbegin(), p.rend());
    p.erase(unique(p.begin(), p.end()), p.end());

    vector<ll> ans;
    ll tmp = 1000000000000000, S = 0;
    for(auto pp: p){
        if(tmp*s(pp) >= pp*S){
            ans.push_back(pp);
            tmp = pp;
            S = s(pp);
        }
    }

    sort(ans.begin(), ans.end());
    rep(i, 0, k){
        cout << ans[i] << endl;
    }

    


   





    
    return 0;
}