#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc046/tasks/arc046_b

int main(){
    int n, a, b; cin >> n >> a >> b;
    if(n <= a){
        cout << "Takahashi" << endl;
    }else{
        if(a == b){
            if(n%(a+1) == 0) cout << "Aoki" << endl;
            else cout << "Takahashi" << endl;
        }else if(a > b){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }

    
    return 0;
}