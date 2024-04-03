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
// div3_496

int main(){
    int n; cin >> n;
    vector<int> a(n+1);
    rep(i, 0, n) cin >> a[i];
    a[n] = 1;
    vector<int> ans;
    rep(i, 0, n){
        if(a[i+1] == 1){
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    
    return 0;
}