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
    ll n, k; cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n) cin >> c[i];
    vector<vector<int>> roop(n);
    vector<int> l(n);
    rep(i, 0, n){
        vector<bool> seen(n);
        seen[i] = true;
        roop[i].push_back(i);
        int pos = i;
        while(!seen[p[pos]]){
            pos = p[pos];
            seen[pos] = true;
            roop[i].push_back(pos);
            l[i]++;
        }
        cout << pos << ' ' << roop[i][l[i]] << endl;
    }


    
    return 0;
}