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
constexpr int inf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc120/tasks/arc120_d


int main(){
    int n; cin >> n;
    vector<int> a(2*n);
    rep(i, 0, 2*n) cin >> a[i];

    vector<pii> b(2*n);
    rep(i, 0, 2*n) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    vector<int> c(2*n);
    rep(i, n, 2*n) c[b[i].second] = 1;

    vector<char> ans(2*n);
    stack<int> stc;
    vector<int> f(2);
    rep(i, 0, 2*n){
        if(f[1-c[i]]){
            int s = stc.top(); stc.pop();
            ans[s] = '(';
            ans[i] = ')';
            if(!stc.size()) f[1-c[i]] = 0;
        }else{
            stc.push(i);
            f[c[i]] = 1;
        }
    }

    rep(i, 0, 2*n) cout << ans[i];
    cout << endl;

    return 0;
}