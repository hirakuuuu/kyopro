#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/2882

/*
重複ありのナップサック
忘れてるから要復習
*/

vector<int> poloc;

void init_poloc(){
    int s = 1;
    while(s*(s+1)*(s+2)/6 <= 1000005){
        poloc.push_back(s*(s+1)*(s+2)/6);
        s++;
    }
}

int main(){
    init_poloc();
    vector<int> ans(1000005), ans_o(1000005);
    rep(i, 1, 1000005){
        ans[i] = i;
        ans_o[i] = i;
    }
    for(auto p: poloc){
        rep(i, p, 1000005){
            ans[i] = min(ans[i], ans[i-p]+1);
        }
        if(p%2){
            rep(i, p, 1000005){
                ans_o[i] = min(ans_o[i], ans_o[i-p]+1);
            }
        }

    }

    while(true){
        int n; cin >> n;
        if(n == 0) break;
        cout << ans[n] << " " << ans_o[n] << endl;
    }

    return 0;
}