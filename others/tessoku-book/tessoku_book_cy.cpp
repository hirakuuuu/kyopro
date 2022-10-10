#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cy

vector<ll> e(1000005);

void init_e(){
    rep(i, 2, 1000005){
        if(e[i] == 0){
            e[i] = i;
            for(ll j = (ll)i*i; j <= 1000005; j += i){
                e[j] = i;
            }
        }
    }
}

int main(){
    int n; cin >> n;
    init_e();

    rep(i, 2, n+1){
        if(e[i] == i) cout << i << '\n';
    }
    
    return 0;
}