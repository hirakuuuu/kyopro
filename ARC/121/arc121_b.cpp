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
// https://atcoder.jp/contests/arc121/tasks/arc121_b


int main(){
    int n; cin >> n;
    vector<vector<ll>> a(3);
    map<char, int> m;
    m['R'] = 0;
    m['G'] = 1;
    m['B'] = 2;
    rep(i, 0, 2*n){
        ll b; cin >> b;
        char c; cin >> c;
        a[m[c]].push_back(b);
    }
    rep(i, 0, 3) sort(a[i].begin(), a[i].end());

    vector<vector<ll>> gap(3, vector<ll>(3, 1LL<<60));

    rep(i, 0, 3){
        rep(j, i+1, 3){
            if(a[j].size() == 0 or a[i].size() == 0) continue;
            int id = 0;
            rep(k, 0, (int)a[i].size()){
                while(id < (int)a[j].size() and a[j][id] < a[i][k]) id++;
                if(id == 0) chmin(gap[i][j], abs(a[j][id]-a[i][k]));
                else if(id == (int)a[j].size()) chmin(gap[i][j], abs(a[j][id-1]-a[i][k]));
                else chmin(gap[i][j], min(abs(a[j][id]-a[i][k]), abs(a[j][id-1]-a[i][k])));
            }
            gap[j][i] = gap[i][j];
        }
    }

    ll ans = 0;
    rep(i, 0, 3){
        rep(j, i+1, 3){
            if(a[i].size()%2 and a[j].size()%2){
                ans = 1LL<<60;
                chmin(ans, gap[i][j]);
                chmin(ans, gap[i][3-i-j]+gap[j][3-i-j]);
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}