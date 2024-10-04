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
const int MAX_N = 10000005;
vector<int> erat(MAX_N);
void init_e(){
    rep(i, 2, sqrt(MAX_N)){
        if(erat[i] == 0){
            for(int j = i*i; j <= MAX_N; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}


int main(){
    return 0;
}