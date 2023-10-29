#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i, 0, h) cin >> a[i];
    rep(i, 0, h) cin >> b[i];

    rep(s, 0, h){
        rep(t, 0, w){

            bool same = true;
            rep(i, 0, h){
                rep(j, 0, w){
                    if(a[(i+s)%h][(j+t)%w] != b[i][j]){
                        same = false;
                    }
                }
            }
            if(same){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }
    cout << "No" << endl;
    return 0;
}