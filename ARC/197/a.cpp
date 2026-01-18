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
    int t; cin >> t;
    while(t--){
        int h, w; cin >> h >> w;
        string s; cin >> s;
        int cnt_d = h-1, cnt_r = w-1;
        rep(i, 0, h+w-2){
            if(s[i] == 'D') cnt_d--;
            if(s[i] == 'R') cnt_r--;
        }

        string s_d = s, s_r = s;
        {
            int cd = cnt_d, cr = cnt_r;
            rep(i, 0, h+w-2){
                if(s_d[i] == '?'){
                    if(cd > 0){
                        s_d[i] = 'D';
                        cd--;
                    }else{
                        s_d[i] = 'R';
                        cr--;
                    }
                }
            }
        }
        {
            int cd = cnt_d, cr = cnt_r;
            rep(i, 0, h+w-2){
                if(s_r[i] == '?'){
                    if(cr > 0){
                        s_r[i] = 'R';
                        cr--;
                    }else{
                        s_r[i] = 'D';
                        cd--;
                    }
                }
            }
        }

        vector<ll> mx(w, -INF), mi(w, INF);
        mx[0] = mi[0] = 0;
        {   
            int ph = 0, pw = 0;
            rep(i, 0, h+w-2){
                if(s_d[i] == 'D') ph++;
                else pw++;
                chmax(mx[pw], ph);
                chmin(mi[pw], ph);
            }
        }
        {   
            int ph = 0, pw = 0;
            rep(i, 0, h+w-2){
                if(s_r[i] == 'D') ph++;
                else pw++;
                chmax(mx[pw], ph);
                chmin(mi[pw], ph);
            }
        }
        ll ans = 0;
        rep(i, 0, w){
            ans += mx[i]-mi[i]+1;
            // p_d++, p_r++;
        }
        cout << ans << endl;

    }
    return 0;
}