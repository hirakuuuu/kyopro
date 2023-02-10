#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/typical90/tasks/typical90_be

int hakidashi(vector<vector<int>> &d, vector<int> &s){
    int h = d.size();
    int w = d[0].size();
    int pos = 0;

    rep(i, 0, w){
        bool found = false;
        rep(j, pos, h){
            if(d[j][i] == 1){
                if(j != pos) swap(d[pos], d[j]);
                found = true;
                break;
            }
        }

        if(found){
            rep(j, 0, h){
                if(j != pos and d[j][i] == 1){
                    rep(k, i, w){
                        d[j][k] ^= d[pos][k];
                    }
                }
            }

            if(s[i] == 1){
                rep(j, i, w){
                    s[j] ^= d[pos][j];
                }
            }
            pos++;
        }
    }

    return pos;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m));
    rep(i, 0, n){
        int t; cin >> t;
        rep(j, 0, t){
            int a; cin >> a;
            d[i][a-1] = 1;
        }
    }

    vector<int> s(m);
    rep(i, 0, m) cin >> s[i];

    int p = hakidashi(d, s);


    if(s == vector<int>(m, 0)){
        int ans = 1;
        rep(i, p, n){
            ans = ans *2 % mod_num;
        }
        cout << ans << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}