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
    ll n, x; cin >> n >> x;
    string s; cin >> s;
    stack<char> stc;
    rep(i, 0, n){
        if(!stc.empty() && stc.top() != 'U' && s[i] == 'U') stc.pop();
        else stc.push(s[i]);
    }
    string t; cin >> t;
    while(!stc.empty()){
        t += stc.top(); stc.pop();
    }
    reverse(t.begin(), t.end());
    rep(i, 0, t.size()){
        if(t[i] == 'U') x = x/2;
        else if(t[i] == 'L') x = 2*x;
        else if(t[i] == 'R') x = 2*x+1;
    }
    cout << x << endl;
    
    return 0;
}