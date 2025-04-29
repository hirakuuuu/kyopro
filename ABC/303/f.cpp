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
    int n; cin >> n;
    ll h; cin >> h;

    vector<ll> t(n), d(n);
    rep(i, 0, n) cin >> t[i] >> d[i];

    ll ng = 0, ok = h;
    vector<pair<ll, ll>> event;
    rep(i, 0, n) event.push_back({t[i], d[i]});
    sort(event.rbegin(), event.rend());

    vector<ll> mxv(n+1);
    rrep(i, n-1, 0){
        auto [time, num] = event[i];
        mxv[i] = max(mxv[i+1], time*num);
    }
    
    while((ok-ng) > 1){
        ll mid = (ok+ng)/2;
        // mid ターン以内に倒せるかどうか
        // → 各ターンで最適な魔法が定まるのでそれの総ダメージが h 以上になるかを判定

        __int128_t pre = 0, mx = 0, sum = 0;
        // cout << "###################" << mid << endl;
        rep(i, 0, n){
            auto [time, num] = event[i];
            __int128_t turn = max(0LL, mid-time+1);
            // cout << turn << ' ' << num << ' ' << time << endl;
            if(pre != turn){
                // [pre+1, turn] 分の処理
                // 最初は mx を使った方がよい，だんだん able.max() の方が良くなる
                // cout << "[" << pre+1 << ", " << turn << "]" << endl;
                if(mx == 0){
                    __int128_t tmp = mxv[i];
                    sum += tmp*(turn-pre);
                }else{
                    __int128_t tmp = mxv[i];
                    __int128_t r = mid-(pre+1)+1, l = r+1;
                    // cout << mid-pre << ' ' << (tmp+mx-1)/mx << endl;
                    if(mid-pre >= (tmp+mx-1)/mx){
                        l = max(mid-turn+1, (tmp+mx-1)/mx);
                    }
                    // cout << r << ' ' << l << ' ' << (mid-turn+1) << endl;
                    sum += mx*(l+r)*(r-l+1)/2;
                    sum += tmp*(l-(mid-turn+1));
                }
                // cout << sum << endl;
            }

            chmax(mx, num);
            pre = turn;
            // if(sum >= h) break;

        }
        sum += mx*(mid-pre)*(mid-pre+1)/2;

        if(sum >= h) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}