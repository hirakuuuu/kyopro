#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    ll l; cin >> l;
    ll cnt = 1;
    vector<int> bunbo(12);
    rep(i, 1, 12){
        cnt *= (l-i);
        rep(j, 1, 12){
            if(bunbo[j] == 0 and cnt%j == 0){
                cnt /= j;
                bunbo[j] = 1;
            }
        }
    }
    cout << cnt << endl;


}