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
    int s, t, x; cin >> s >> t >> x;
    if(s < t){
        if(s <= x && x < t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(t <= x && x < s) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}