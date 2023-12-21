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
// https://atcoder.jp/contests/abc237/tasks/abc237_c

int main(){
    string s; cin >> s;
    int n = s.size();
    int l = 0, r = 0;
    rep(i, 0, n){
        if(s[i] == 'a') l++;
        else break;
    }
    rrep(i, n-1, 0){
        if(s[i] == 'a') r++;
        else break;
    }

    if(l > r){
        cout << "No" << endl;
        return 0;
    }

    bool f = true;
    rep(i, l, n-r){
        if(s[i] != s[n-r-1-(i-l)]) f = false;
    }

    if(f) cout << "Yes" << endl;
    else cout << "No" << endl;



    
    return 0;
}