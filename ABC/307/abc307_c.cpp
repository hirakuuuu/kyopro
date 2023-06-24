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
// https://atcoder.jp/contests/abc307/tasks/abc307_c

int main(){
    int ha, wa; cin >> ha >> wa;
    vector<string> a(ha);
    rep(i, 0, ha) cin >> a[i];
    int hb, wb; cin >> hb >> wb;
    vector<string> b(hb);
    rep(i, 0, hb) cin >> b[i];
    int hx, wx; cin >> hx >> wx;
    vector<vector<char>> x(hx, vector<char>(wx));
    rep(i, 0, hx)rep(j, 0, wx) cin >> x[i][j];

    // 黒いマスをすべて含む必要がある
    int la = -1, ra = 0, ta = -1, ba = 0;
    rep(i, 0, ha){
        rep(j, 0, wa){
            if(a[i][j] == '#'){
                if(ta == -1) ta = i;
                ba = i;
            }
        }
    }
    rep(i, 0, wa){
        rep(j, 0, ha){
            if(a[j][i] == '#'){
                if(la == -1) la = i;
                ra = i;
            }
        }
    }
    int lb = -1, rb = 0, tb = -1, bb = 0;
    rep(i, 0, hb){
        rep(j, 0, wb){
            if(b[i][j] == '#'){
                if(tb == -1) tb = i;
                bb = i;
            }

        }
    }
    rep(i, 0, wb){
        rep(j, 0, hb){
            if(b[j][i] == '#'){
                if(lb == -1) lb = i;
                rb = i;
            }

        }
    }

    // 全ての黒マスを含んだうえで切り出せない
    if(wx < max((ra-la), (rb-lb)) || hx < max((ba-ta), (bb-tb))){
        cout << "No" << endl;
        return 0;
    }

    rep(i, 0, hx-(ba-ta)){
        rep(j, 0, wx-(ra-la)){
            rep(k, 0, hx-(bb-tb)){
                rep(l, 0, wx-(rb-lb)){
                    vector<vector<char>> y(hx, vector<char>(wx));
                    rep(ii, 0, hx){
                        rep(jj, 0, wx) y[ii][jj] = '.';
                    }

                    rep(ii, ta, ba+1){
                        rep(jj, la, ra+1){
                            if(a[ii][jj] == '#') y[i+ii-ta][j+jj-la] = '#';
                        }
                    }
                    rep(ii, tb, bb+1){
                        rep(jj, lb, rb+1){
                            if(b[ii][jj] == '#') y[k+ii-tb][l+jj-lb] = '#';
                        }
                    }


                    if(x == y){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}