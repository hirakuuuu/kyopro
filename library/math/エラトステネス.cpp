#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc034/tasks/arc034_3

// 0ならば素数, 0でないなら最小の素因数
const int MAX_N = 1000005;
vector<int> erat(MAX_N+1);
void init_e(){
    rep(i, 2LL, (ll)sqrt(MAX_N)+1){
        if(erat[i] == 0){
            for(ll j = i*i; j <= MAX_N; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

// 素因数分解 O(log{x})
vector<pair<int, int>> prime_factorization(ll x){
    vector<pair<int, int>> res;
    while(erat[x] != 0){
        ll p = erat[x];
        res.push_back({p, 0});
        while(x%p == 0){
            x /= p;
            res.back().second++;
        }
    }
    if(x != 1) res.push_back({x, 1});
    return res;
};


int main(){
    return 0;
}