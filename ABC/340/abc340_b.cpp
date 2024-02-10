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
// https://atcoder.jp/contests/abc340/tasks/abc340_b

int main(){
    int q; cin >> q;
    vector<int> a;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            a.push_back(x);
        }else{
            int k; cin >> k;
            cout << a[a.size()-k] << endl;
        }
    }
    
    return 0;
}