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
    ll ans = -9e18;
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n){
        cin >> c[i];
        chmax(ans, c[i]);
    }
    vector<vector<int>> roop(n);
    vector<vector<ll>> score(n);
    rep(i, 0, n){
        vector<bool> seen(n);
        int pos = i;
        score[i].push_back(0);
        while(!seen[pos]){
            seen[pos] = true;
            pos = p[pos];
            score[i].push_back(score[i].back()+c[pos]);
        }
        ll s = score[i].size(), t = score[i].back();
        if(t <= 0){
            rep(j, 1, s){
                chmax(ans, score[i][j]);
            }
        }else{
            rep(j, 1, s){
                if(k-j >= 0){
                    chmax(ans, t*((k-j)/(s-1))+score[i][j]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}