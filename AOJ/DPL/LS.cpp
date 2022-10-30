#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> d(h+1, vector<int>(w+1)), s(h+1, vector<int>(w+1));
    rep(i, 0, h){
        rep(j, 0, w) cin >> d[i+1][j+1];
    }

    int me = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            if(d[i][j] == 1) s[i][j] = 0;
            else s[i][j] = min(s[i-1][j-1], min(s[i-1][j], s[i][j-1]))+1;
            me = max(me, s[i][j]);
        }
    }
    cout << me*me << endl;
}


/*
いもす法でも解けるよって話
vector<vector<int>> num(1405, vector<int>(1405));
int yogore(int h1, int w1, int h2, int w2){
    return num[h2][w2]-num[h1-1][w2]-num[h2][w1-1]+num[h1-1][w1-1];
}
int main(){
    int h, w; cin >> h >> w;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            cin >> num[i][j];
        }
    }
    rep(i, 1, h+1){
        rep(j, 1, w+1) num[i][j] += num[i-1][j]+num[i][j-1]-num[i-1][j-1];
    }
    int ans = 0, me = 0;
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            int i2 = i+me, j2 = j+me;
            while(i2 <= h and j2 <= w){
                if(yogore(i, j, i2, j2)) break;
                ans = max(ans, (i2-i+1)*(j2-j+1));
                me = max(me, i2-i+1);
                i2++, j2++;
            }
        }
    }
    cout << ans << endl;
}
*/