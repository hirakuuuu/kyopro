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
// https://atcoder.jp/contests/abc337/tasks/abc337_e

int main(){
    int n; cin >> n;
    int m = 0, n_ = n;
    while(n_){
        m++;
        n_ /= 2;
    }
    if(n == 1<<(m-1)){
        m--;
    }

    cout << m << endl;
    rep(i, 0, m){
        vector<int> a;
        rep(j, 1, n+1){
            if((j>>i)&1) a.push_back(j);
        }
        cout << a.size();
        for(auto aa: a) cout << ' ' << aa;
        cout << endl;
    }

    string s; cin >> s;
    int ans = 0;
    rep(i, 0, m){
        if(s[i] == '1') ans += (1<<i);
    }
    if(ans == 0) ans += 1<<m;
    cout << ans << endl;

    
    return 0;
}