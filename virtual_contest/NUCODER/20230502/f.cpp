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
    int n, m; cin >> n >> m;
    vector<pll> card(n+m);
    rep(i, 0, n){
        ll a; cin >> a;
        card[i] = {a, 1LL};
    }
    rep(i, 0, m){
        ll b, c; cin >> b >> c;
        card[i+n] = {c, b};
    }
    sort(card.begin(), card.end());
    reverse(card.begin(), card.end());

    ll ans = 0, rest = n, id = 0;
    while(rest){
        ll score = card[id].first, num = card[id].second;
        if(rest < num){
            ans += score*rest;
            rest = 0;
        }else{
            ans += score*num;
            rest -= num;
        }
        id++;
    }
    cout << ans << endl;

    
    return 0;
}