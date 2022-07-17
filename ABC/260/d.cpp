#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc260/tasks/abc260_d

int main(){
    ll n, k; cin >> n >> k;
    vector<ll> p(n);
    rep(i, 0, n) cin >> p[i];
    vector<ll> pos(n+1), turn(n+1, -1);
    set<pll> card;

    ll cnt = 0;
    rep(i, 0, n){
        auto itr = card.lower_bound({p[i], 0LL});
        if(card.size() == 0 or itr == card.end()){
            if(k == 1){
                pos[p[i]] = cnt;
                cnt++;
                turn[pos[p[i]]] = i+1;
            }else{
                card.insert({p[i], 1LL});
                pos[p[i]] = cnt;
                cnt++;
            }
        }else{
            pll sento = *itr;
            card.erase(itr);
            pos[p[i]] = pos[sento.first];
            if(sento.second == k-1){
                turn[pos[sento.first]] = i+1;
            }else{
                card.insert({p[i], sento.second+1});
            }
        }
    }

    rep(i, 1, n+1){
        cout << turn[pos[i]] << "\n";
    }


    
    return 0;
}