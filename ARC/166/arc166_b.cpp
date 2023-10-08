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
// https://atcoder.jp/contests/arc166/tasks/arc166_b

int main(){
    ll n, a, b, c; cin >> n >> a >> b >> c;

    vector<ll> A(n);
    rep(i, 0, n) cin >> A[i];

    // 1つの数をa, b, cの最小公倍数にする
    ll abc = lcm(a, lcm(b, c));
    ll ans = 9e18;
    rep(i, 0, n){
        chmin(ans, (abc-A[i]%abc)%abc);
    }

    // １つをaの倍数, １つをb, cの最小公倍数にする
    if(n >= 2){
        vector<ll> s = {a, b, c};
        rep(i, 0, 3){
            ll a_ = s[i], bc = lcm(s[(i+1)%3], s[(i+2)%3]);

            vector<pair<ll, ll>> cnt_a_(n), cnt_bc(n);
            rep(j, 0, n){
                cnt_a_[j] = {(a_-A[j]%a_)%a_, j};
                cnt_bc[j] = {(bc-A[j]%bc)%bc, j};
            }
            sort(cnt_a_.begin(), cnt_a_.end());
            sort(cnt_bc.begin(), cnt_bc.end());

            if(cnt_a_[0].second != cnt_bc[0].second) chmin(ans, cnt_a_[0].first+cnt_bc[0].first);
            else chmin(ans, min(cnt_a_[0].first+cnt_bc[1].first, cnt_a_[1].first+cnt_bc[0].first));
        }
    }

    // １つをaの倍数, １つをbの倍数, １つをcの倍数にする
    if(n >= 3){
        vector<pair<ll, ll>> cnt_a(n), cnt_b(n), cnt_c(n);
        rep(j, 0, n){
            cnt_a[j] = {(a-A[j]%a)%a, j};
            cnt_b[j] = {(b-A[j]%b)%b, j};
            cnt_c[j] = {(c-A[j]%c)%c, j};
        }

        sort(cnt_a.begin(), cnt_a.end());
        sort(cnt_b.begin(), cnt_b.end());
        sort(cnt_c.begin(), cnt_c.end());

        rep(i, 0, 3){
            rep(j, 0, 3){
                rep(k, 0, 3){
                    set<ll> t;
                    t.insert(cnt_a[i].second);
                    t.insert(cnt_b[j].second);
                    t.insert(cnt_c[k].second);

                    if(t.size() != 3) continue;
                    chmin(ans, cnt_a[i].first+cnt_b[j].first+cnt_c[k].first);
                }
            }
        }
    }
    

    cout << ans << endl;


    
    return 0;
}