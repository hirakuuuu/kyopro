#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int f(int x, int y, int z){
    return x*x+y*y+z*z+x*y+y*z+z*x;
}

int main(){
    int n; cin >> n;
    vector<int> ans(n+1);
    for(int x = 1; f(x, 1, 1) <= n; x++){
        for(int y = 1; f(x, y, 1) <= n; y++){
            for(int z = 1; f(x, y, z) <= n; z++){
                ans[f(x, y, z)]++;
            }
        }
    }
    
    rep(i, 1, n+1){
        cout << ans[i] << endl;
    }
    return 0;
}