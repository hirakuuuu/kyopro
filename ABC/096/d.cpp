#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc096/tasks/abc096_d

vector<int> p, p5;
void mkf(int n){
    bool f = false;
    rep(i, 2, 55556){
        f = false;
        for(auto pp: p){
            if(i%pp == 0){
                f = true;
                break;
            }
        }
        if(f) continue;
        p.push_back(i);
        if(i%5 == 1) p5.push_back(i);
        if(p5.size() >= n) return;
    }
}

int main(){
    int n; cin >> n;
    mkf(n);
    rep(i, 0 ,n){
        if(i > 0) cout << " ";
        cout << p5[i];
    }
    cout <<  endl;
    
    return 0;
}