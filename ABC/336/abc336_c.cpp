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
// https://atcoder.jp/contests/abc336/tasks/abc336_c

int main(){
    ll n; cin >> n;
    n--;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    while(n){
        ans.push_back(n%5);
        n /= 5;
    }
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa*2;
    }
    cout << endl;
    
    return 0;
}