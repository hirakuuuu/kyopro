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
// https://atcoder.jp/contests/abc300/tasks/abc300_b

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i, 0, h) cin >> a[i];
    rep(i, 0, h) cin >> b[i];

    rep(i, 0, h){
        rep(j, 0, w){
            bool f = true;
            rep(k, 0, h){
                rep(l, 0, w){
                    f &= (a[(k+i)%h][(l+j)%w] == b[k][l]);
                }
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
    
    return 0;
}