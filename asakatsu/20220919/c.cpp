#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(ll i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/caddi2018b/tasks/caddi2018_a

vector<ll> P(1000005), p_list;
void init_p(){
    rep(i, 2, 1000005){
        if(!P[i]){
            p_list.push_back(i);
            P[i] = i;
            for(ll j = i*i; j < 1000005; j += i){
                P[j] = i;
            }
        }
    }
}

int main(){
    ll n, p; cin >> n >> p;
    init_p();

    if(n == 1){
        cout << p << endl;
        return 0;
    }

    ll ans = 1;
    for(auto pp: p_list){
        int cnt = 0;
        while(p%pp == 0){
            p /= pp;
            cnt++;
        }
        rep(i, 0, cnt/n){
          ans *= pp;
        }
    }


    cout << ans << endl;


    return 0;
}