#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll acc[11][11][11][11][11][11];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    rep(i1, 0, 11) rep(i2, 0, 11) rep(i3, 0, 11) rep(i4, 0, 11) rep(i5, 0, 11) rep(i6, 0, 11){
        acc[i1][i2][i3][i4][i5][i6] = 0;
    }
    int n; cin >> n;
    vector<string> s(n);
    vector<ll> v(n);
    rep(i, 0, n){
        cin >> s[i] >> v[i];
        vector<int> ncnt(6);
        rep(j, 0, 6) ncnt[j] = s[i][j]-'0'+1;
        acc[ncnt[0]][ncnt[1]][ncnt[2]][ncnt[3]][ncnt[4]][ncnt[5]] = v[i];
    }



    vector<int> cnt(6);
    rep(i1, 0, 10) rep(i2, 0, 10) rep(i3, 0, 10) rep(i4, 0, 10) rep(i5, 0, 10) rep(i6, 0, 10){
        cnt = {i1, i2, i3, i4, i5, i6};
        vector<int> ncnt = cnt;
        rep(i, 0, 6) ncnt[i]++;
        rep(i, 0, (1<<6)-1){
            vector<int> nncnt = cnt;
            rep(j, 0, 6) if(i>>j&1) nncnt[j]++;
            // rep(j, 0, 6){
            //     cout << nncnt[j] << ' ';
            // }
            // cout << ": " << acc[nncnt[0]][nncnt[1]][nncnt[2]][nncnt[3]][nncnt[4]][nncnt[5]] << endl;
            if((__builtin_popcount(i)&1) == 0){
                acc[ncnt[0]][ncnt[1]][ncnt[2]][ncnt[3]][ncnt[4]][ncnt[5]]
                -= acc[nncnt[0]][nncnt[1]][nncnt[2]][nncnt[3]][nncnt[4]][nncnt[5]];
            }else{
                acc[ncnt[0]][ncnt[1]][ncnt[2]][ncnt[3]][ncnt[4]][ncnt[5]]
                += acc[nncnt[0]][nncnt[1]][nncnt[2]][nncnt[3]][nncnt[4]][nncnt[5]];
            }
        }
        // cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << ' ' << i5 << ' ' << i6 << ": " << acc[i1+1][i2+1][i3+1][i4+1][i5+1][i6+1] << endl;
    }

    // auto f = [&](string x) -> int {
    //     vector<int> ncnt(6);
    //     rep(j, 0, 6) ncnt[j] = x[j]-'0'+1;
    //     return acc[ncnt[0]][ncnt[1]][ncnt[2]][ncnt[3]][ncnt[4]][ncnt[5]];
    // };
    int q; cin >> q;
    while(q--){
        string x, y; cin >> x >> y;
        // cout << f(y) << ' ' << f(x) << endl;
        vector<int> nx(6), ny(6);
        bool ok = true;
        rep(j, 0, 6){
            nx[j] = x[j]-'0';
            ny[j] = y[j]-'0'+1;
            if(x[j] > y[j]) ok = false;
        }
        ll ans = 0;
        rep(i, 0, (1<<6)){
            vector<int> nncnt(6);
            rep(j, 0, 6){
                if(i>>j&1) nncnt[j] = ny[j];
                else nncnt[j] = nx[j];
            }
            if((__builtin_popcount(i)&1) == 0){
                ans += acc[nncnt[0]][nncnt[1]][nncnt[2]][nncnt[3]][nncnt[4]][nncnt[5]];
            }else{
                ans -= acc[nncnt[0]][nncnt[1]][nncnt[2]][nncnt[3]][nncnt[4]][nncnt[5]];
            }
        }
        if(!ok) ans = 0;
        cout << ans << endl;
    }

    
    return 0;
}