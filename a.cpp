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

int main(){
    rep(i, 0, 15){
        cout << 0;
    }
    cout << endl;
    rep(i, 0, 15){
        rep(j, 0, 15){
            if(i == j) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    
    return 0;
}