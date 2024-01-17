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
// https://atcoder.jp/contests/agc045/tasks/agc045_a

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        reverse(a.begin(), a.end());
        string s; cin >> s;
        reverse(s.begin(), s.end());
        bool f = false;
        vector<ll> base;
        rep(i, 0, n){
            ll v = a[i];
            for(auto b: base) chmin(v, v^b);
            if(v){
                if(s[i] == '1'){
                    f = true;
                    break;
                }
                base.push_back(v);
            }
        }
        if(f) cout << 1 << endl;
        else cout << 0 << endl;
    }
    
    return 0;
}