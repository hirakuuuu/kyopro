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
// https://atcoder.jp/contests/abc252/tasks/abc252_g

int main(){
    string x; cin >> x;
    bool f1 = true, f2 = true;
    rep(i, 0, 3){
        if(x[i] != x[i+1]) f1 = false;
        if((x[i]-'0'+1)%10 != (x[i+1]-'0')%10) f2 = false;
    }
    if(!f1 && !f2) cout << "Strong" << endl;
    else cout << "Weak" << endl; 
    
    return 0;
}