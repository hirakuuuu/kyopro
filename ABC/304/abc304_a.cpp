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
// https://atcoder.jp/contests/abc304/tasks/abc304_a

int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<int> a(n);

    rep(i, 0, n) cin >> s[i] >> a[i];

    int pos = 0, min_a = a[0];
    rep(i, 1, n){
        if(min_a > a[i]){
            pos = i;
            min_a = a[i];
        }
    }

    rep(i, 0, n){
        cout << s[(pos+i)%n] << endl;
    }


    
    return 0;
}