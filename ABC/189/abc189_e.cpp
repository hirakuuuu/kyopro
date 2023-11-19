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

// 問題
// https://atcoder.jp/contests/abc189/tasks/abc189_e

int main(){
    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    int m; cin >> m;
    vector<int> rotate(m+1), mv_x(m+1), mv_y(m+1);
    vector<pair<ll, ll>> pos(m+1);
    rep(i, 1, m+1){
        int t; cin >> t;
        rotate[i] = rotate[i-1];
        mv_x[i] = mv_x[i-1];
        mv_y[i] = mv_y[i-1];
        if(t == 1){
            rotate[i] = (rotate[i-1]+1)%4;
            pos[i] = {pos[i-1].second, -pos[i-1].first};
            swap(mv_x[i], mv_y[i]);
        }else if(t == 2){
            rotate[i] = (rotate[i-1]+3)%4;
            pos[i] = {-pos[i-1].second, pos[i-1].first};
            swap(mv_x[i], mv_y[i]);
        }else{
            ll p; cin >> p;
            if(t == 3){
                pos[i] = {2*p-pos[i-1].first, pos[i-1].second};
                mv_x[i] = 1-mv_x[i-1];
            }else if(t == 4){
                pos[i] = {pos[i-1].first, 2*p-pos[i-1].second};
                mv_y[i] = 1-mv_y[i-1];
            }
        }
    }
    int q; cin >> q;
    while(q--){
        int a, b; cin >> a >> b;
        b--;
        if(rotate[a] == 0){
            cout << pos[a].first+(mv_x[a] ? -1 : 1)*x[b] << ' ' << pos[a].second+(mv_y[a] ? -1 : 1)*y[b] << endl;
        }else if(rotate[a] == 1){
            cout << pos[a].first+(mv_x[a] ? -1 : 1)*y[b] << ' ' << pos[a].second-(mv_y[a] ? -1 : 1)*x[b] << endl;
        }else if(rotate[a] == 2){
            cout << pos[a].first-(mv_x[a] ? -1 : 1)*x[b] << ' ' << pos[a].second-(mv_y[a] ? -1 : 1)*y[b] << endl;
        }else if(rotate[a] == 3){
            cout << pos[a].first-(mv_x[a] ? -1 : 1)*y[b] << ' ' << pos[a].second+(mv_y[a] ? -1 : 1)*x[b] << endl;
        }
    }
    return 0;
}