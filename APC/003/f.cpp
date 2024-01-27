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

int main(){
    ll n, s, k; cin >> n >> s >> k;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<vector<ll>> memo(n+1, vector<ll>(s+1, -1));
    auto dfs = [&](auto sfs, int pos, ll tmp)-> ll {
        if(memo[pos][tmp] != -1) return memo[pos][tmp];
        if(pos == n){
            if(tmp == 0) return memo[pos][tmp] = 1;
            else return memo[pos][tmp] = 0;
        }
        if(tmp-a[pos] >= 0) return memo[pos][tmp] = sfs(sfs, pos+1, tmp)+sfs(sfs, pos+1, tmp-a[pos]);
        return memo[pos][tmp] = sfs(sfs, pos+1, tmp);
    };
    cout << dfs(dfs, 0, s) << endl;
    



    
    
    return 0;
}