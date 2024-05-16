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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    vector<ll> stc;
    rep(i, 0, n){
        stc.push_back(a[i]);
        while(stc.size() >= 2){
            ll a1 = stc.back(); stc.pop_back();
            ll a2 = stc.back(); stc.pop_back();
            if(a1 == a2){
                stc.push_back(a1+1);
            }else{
                stc.push_back(a2);
                stc.push_back(a1);
                break;
            }
        }
        
    }
    cout << stc.size() << endl;
    return 0;
}