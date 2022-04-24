#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc249/tasks/abc249_d

int main(){
    int n; cin >> n;
    vector<ll> a(n), num_a(200005);
    rep(i, 0, n){
        cin >> a[i];
        num_a[a[i]]++;
    }
    sort(a.begin(), a.end());

    vector<vector<ll>> yakusu(n);
    rep(i, 0, n){
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i]%j) continue;
            yakusu[i].push_back(j);
            if(j != a[i]/j) yakusu[i].push_back(a[i]/j);
        }
    }

    // vector<map<ll, ll>> p(n+1);
    // rep(i, 1, n+1){
    //     for(auto pp = p[i-1].begin(); pp != p[i-1].end(); ++pp){
    //         p[i][pp->first] = pp->second;
    //     }
    //     p[i][a[i-1]]++;
    // }

    ll ans = 0;


    rep(i, 0, n){
        for(auto y: yakusu[i]) ans += num_a[y]*num_a[a[i]/y];
    }
    cout << ans << endl;
    
    return 0;
}