#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> p(n), c(n);
    ll ans = -(1LL<<60);
    rep(i, 0, n){
        cin >> p[i];
        p[i]--;
    }
    rep(i, 0, n){
        cin >> c[i];
        chmax(ans, c[i]);
    }

    rep(i, 0, n){
        vector<bool> seen(n);
        vector<ll> score={0};
        ll pos = i;
        while(!seen[pos]){
            seen[pos] = true;
            score.push_back(score.back()+c[p[pos]]);
            pos = p[pos];
        }
        ll s = score.size();
        ll t = score.back();
        if(t <= 0){
            rep(j, 1, s){
                chmax(ans, score[j]);
            } 
        }else{
            rep(j, 1, s){
                if(k-j >= 0) chmax(ans, t*((k-j)/(s-1))+score[j]);
            }  
        }
    }
    cout << ans << endl;



    
    return 0;
}