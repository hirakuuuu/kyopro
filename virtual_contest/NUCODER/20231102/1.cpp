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
    ll gocho = 5000000000000000;
    string s; cin >> s;
    ll k; cin >> k;
    ll cnt = 0;
    for(auto ss: s){
        if(ss == '1'){
            cnt++;
        }else{
            cout << ss << endl;
            return 0;
        }
        if(cnt == k){
            cout << 1 << endl;
            return 0;
        }
    }
    
    return 0;
}