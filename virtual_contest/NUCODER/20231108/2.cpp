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
    int n, s; cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i] >> b[i];
    vector<pair<bool, string>> ok(s+1);
    ok[0] = {true, ""};
    rep(i, 0, n){
        vector<pair<bool, string>> ok_(s+1);
        rep(j, 0, s+1){
            if(ok[j].first){
                if(j+a[i] <= s) ok_[j+a[i]] = {true, ok[j].second+'H'};
                if(j+b[i] <= s) ok_[j+b[i]] = {true, ok[j].second+'T'};
            }
        }
        ok = ok_;
    }
    if(ok[s].first){
        cout << "Yes" << endl;
        cout << ok[s].second << endl;
    }else cout << "No" << endl;
    return 0;
}