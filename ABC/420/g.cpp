#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll x; cin >> x;
    ll y = 1LL-4LL*x;
    vector<ll> yakusu;
    for(ll i = 1; i*i <= abs(y); i++){
        if(y%i == 0){
            yakusu.push_back(i);
            yakusu.push_back(-i);
            if(abs(y/i) != abs(i)){
                yakusu.push_back(y/i);
                yakusu.push_back(-y/i);
            }
        }
    }

    vector<ll> ans;
    for(auto a: yakusu){
        ll b = y/a;
        if((a+b)%4 == 2 && (a-b >= 0 && (a-b)%4 == 0)){
            ans.push_back(((a+b)/2-1)/2);
        }
    }
    {
        vector<ll> _ans;
        for(auto aa: ans){
            _ans.push_back(aa);
            _ans.push_back(-aa-1);
        }
        swap(_ans, ans);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    } 
    cout << endl;



    return 0;
}