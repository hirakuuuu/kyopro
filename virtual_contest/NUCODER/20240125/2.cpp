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
    ll a, b, k; cin >> a >> b >> k;
    string ans;
    ll n = a+b;
    vector<vector<ll>> combination(100, vector<ll>(100));
    combination[0][0] = 1;
    rep(i, 1, a+b+1){
        combination[i][0] = 1;
        rep(j, 1, i+1){
            combination[i][j] = combination[i-1][j]+combination[i-1][j-1];
        }
    }
    
    rep(i, 0, n){
        if(b <= 0 || k <= combination[a+b-1][b]){
            ans += 'a';
            a--;
        }else{
            ans += 'b';
            k -= combination[a+b-1][b]; 
            b--;
        }
        //cout << k << ' ' << a << ' ' << b << endl;
    }
    cout << ans << endl;
    
    return 0;
}