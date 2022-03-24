#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    ll n, k; cin >> n >> k;
    vector<pll> ab(n);
    rep(i, 0, n){
        ll a, b; cin >> a >> b;
        ab[i] = {a, b};
    }
    sort(ab.begin(), ab.end());

    ll pos = 0;
    rep(i, 0, n){
        if(k < ab[i].first-pos){
            cout << pos+k << endl;
            return 0;
        }else{
            k -= ab[i].first-pos;
            k += ab[i].second;
            pos = ab[i].first;
        }
    }
    cout << pos+k << endl;

  
}