#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc114/tasks/abc114_d

vector<int> e(105);
void init_e(int n){
    rep(i, 2, n+1){
        if(e[i] == 0){
            e[i] = i;
            for(int j = i*i; j <= n; j += i){
                e[j] = i;
            }
        }
    }
}

int main(){
    ll n; cin >> n;
    init_e(100);
    vector<int> cnt(101);
    rep(i, 2, n+1){
        int ii = i;
        while(ii > 1){
            cnt[e[ii]]++;
            ii /= e[ii];
        }
    }

    vector<int> p;

    rep(i, 0, 101){
        if(cnt[i]) p.push_back(cnt[i]);
    }

    int ans = 0;

    // n^74
    rep(i, 0, p.size()){
        if(p[i] >= 74) ans++;
    }

    // n^24*m^2 or n^14*m^4
    rep(i, 0, p.size()){
        rep(j, 0, p.size()){
            if(i == j) continue;
            if(p[i] >= 24 and p[j] >= 2) ans++;
            if(p[i] >= 14 and p[j] >= 4) ans++;
        }
    }


    // n^2*m^4*l^4
    rep(i, 0, p.size()){
        rep(j, i+1, p.size()){
            rep(k, 0, p.size()){
                if(i == j or j == k or k == i) continue;
                if(p[i] >= 4 and p[j] >= 4 and p[k] >= 2) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}