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
// https://atcoder.jp/contests/abc329/tasks/abc329_f

int main(){
    int n, q; cin >> n >> q;
    vector<int> c(n);
    rep(i, 0, n) cin >> c[i];

    vector<set<int>> s(n);
    rep(i, 0, n) s[i].insert(c[i]);
    rep(i, 0, q){
        int a, b; cin >> a >> b;
        a--, b--;
        if(s[b].size() >= s[a].size()){
            for(auto ss: s[a]){
                s[b].insert(ss);
            }
        }else{
            for(auto ss: s[b]){
                s[a].insert(ss);
            }
            swap(s[a], s[b]);
        }
        s[a].clear();
        cout << s[b].size() << endl;
    }


    
    return 0;
}