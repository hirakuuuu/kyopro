#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<vector<int>> s(105, vector<int>(105));

int sum_s(int i, int j, int k, int l){
    return s[k][l]-s[k][j-1]-s[i-1][l]+s[i-1][j-1];
}

int main(){
    int h, w; cin >> h >> w;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            int c; cin >> c;
            if((i+j)%2) c *= -1;
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c;
        }
    }
    int ans = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            rep(k, i, h+1){
                rep(l, j, w+1){
                    if(sum_s(i, j, k, l) == 0){
                        ans = max(ans, (k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }

    cout << ans << endl;
  
}