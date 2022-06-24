#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    while(true){
        int n, m; cin >> n >> m;
        if(n+m == 0) break;

        vector<int> st(n), sh(m); 
        int t = 0, h = 0;
        rep(i, 0, n){
            cin >> st[i];
            t += st[i];
        }
        rep(i, 0, m){
            cin >> sh[i];
            h += sh[i];
        }

        int ti = -1, hi = -1, total = 1<<30;
        rep(i, 0, n){
            rep(j, 0, m){
                if(t-st[i]+sh[j] == h-sh[j]+st[i] and st[i]+sh[j] < total){
                    ti = st[i];
                    hi = sh[j];
                    total = st[i]+sh[j];
                }
            }
        }
        if(ti == -1){
            cout << -1 << endl;
        }else cout << ti << " " << hi << endl;


    }
    
    return 0;
}