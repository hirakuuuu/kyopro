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
// https://atcoder.jp/contests/abc199/tasks/abc199_c

int main(){
    int n;
    string s;
    int q; 
    cin >> n >> s >> q;
    int f = 0;
    while(q--){
        int t, a, b; cin >> t >> a >> b;
        if(t == 1){
            a--, b--;
            swap(s[(a+n*f)%(2*n)], s[(b+n*f)%(2*n)]);
        }else{
            f = 1-f;
        }
    }

    rep(i, 0, 2*n){
        cout << s[(i+f*n)%2*n];
    }
    cout << endl;
    
    return 0;
}