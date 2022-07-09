#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1610
const int INF = 7368792;
vector<bool> e(INF, false);

int main(){
    while(true){
        int m, n; cin >> m >> n; 
        e.assign(INF, false);
        if(m*n == 0){
            break;
        }
        int rest = n;
        rep(i, m, INF){
            if(e[i]) continue;
            if(!e[i] and rest == 0){
                cout << i << endl;
                break;
            }else{
                for(int j = i; j < INF; j += i) e[j] = true;
                rest--;
            }
        }
    }
    return 0;
}