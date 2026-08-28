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



int main(){
    int h, w; cin >> h >> w;
    int n; cin >> n;
    int sr, sc; cin >> sr >> sc; sr--, sc--;
    string s; cin >> s;
    string t; cin >> t;


    bool f = false;
    {
        int cnt_su = 0, cnt_sd = 0;
        int cnt_tu = 0, cnt_td = 0;
        rep(i, 0, n){
            if(s[i] == 'U'){
                cnt_su++;
                if(!inr(0, sr-cnt_su+cnt_td, h)) f = true;
            }else if(s[i] == 'D'){
                cnt_sd++;
                if(!inr(0, sr+cnt_sd-cnt_tu, h)) f = true;
            }

            if(t[i] == 'U'){
                if(sr+cnt_sd-cnt_tu == 0) continue;
                cnt_tu++;
            }else if(t[i] == 'D'){
                if(sr-cnt_su+cnt_td == h-1) continue;
                cnt_td++;
            }
        }
    }
    {
        int cnt_su = 0, cnt_sd = 0;
        int cnt_tu = 0, cnt_td = 0;
        rep(i, 0, n){
            if(s[i] == 'L'){
                cnt_su++;
                if(!inr(0, sc-cnt_su+cnt_td, w)) f = true;
            }else if(s[i] == 'R'){
                cnt_sd++;
                if(!inr(0, sc+cnt_sd-cnt_tu, w)) f = true;
            }

            if(t[i] == 'L'){
                if(sc+cnt_sd-cnt_tu == 0) continue;
                cnt_tu++;
            }else if(t[i] == 'R'){
                if(sc-cnt_su+cnt_td == w-1) continue;
                cnt_td++;
            }
        }
    }

    if(!f) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}