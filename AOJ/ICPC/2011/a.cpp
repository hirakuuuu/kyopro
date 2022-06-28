#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1172

vector<int> p, e(300005);

void init_p(){
    rep(i, 2, 300005){
        if(e[i] == 0){
            p.push_back(i);
            for(int j = i; j <= 300005; j += i){
                e[j] = 1;
            }
        }
    }
}

int main(){
    init_p();
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        int cnt = upper_bound(p.begin(), p.end(), 2*n)-upper_bound(p.begin(), p.end(), n);
        cout << cnt << endl;
    }

    
    return 0;
}