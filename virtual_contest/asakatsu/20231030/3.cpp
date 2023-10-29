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
// 

int main(){
    ll n, w; cin >> n >> w;
    vector<vector<ll>> s(200005), t(200005);
    rep(i, 0, n){
        ll S, T, P; cin >> S >> T >> P;
        s[S].push_back(P);
        t[T].push_back(P);
    }


    ll now = 0;
    rep(i, 0, 200005){
        for(auto ss: s[i]) now += ss;
        for(auto tt: t[i]) now -= tt;
        if(now > w){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}