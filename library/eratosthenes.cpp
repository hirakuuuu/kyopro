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

vector<int> erat(100005);
void init_e(){
    rep(i, 2, 100005){
        if(erat[i] == 0){
            erat[i] = i;
            for(int j = i; j <= 100005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    return 0;
}