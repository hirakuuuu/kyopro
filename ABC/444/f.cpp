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
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        ll sum = 0;
        rep(i, 0, n) cin >> a[i], sum += a[i];

        auto sep = [&](ll x, ll len) -> vector<pair<ll, ll>> {
            ll tmp = len, num = 1;
            while(tmp >= 2*x-1){
                tmp /= 2;
                num *= 2;
            }
            ll r = len-num*tmp, l = num-r;
            vector<pair<ll, ll>> res;
            if(tmp >= x && l > 0) res.push_back({tmp, l});
            if(tmp+1 == 2*x-1){
                res.push_back({x, r});
            }else if(tmp+1 >= x && r > 0){
                res.push_back({tmp+1, r});
            }
            return res;
        };

        ll ok = 1, ng = INF;
        while(ng-ok > 1){
            ll mid = (ok+ng)/2;
            vector<pair<ll, ll>> vec;
            ll big = 0;
            rep(i, 0, n){
                if(a[i] >= mid) big++;
                vector<pair<ll, ll>> nums = sep(mid, a[i]);
                for(auto [len, cnt]: nums){
                    vec.push_back({len, cnt});
                }
                // cout << mx.first << ' ' << mx.second << endl;
                // cout << mi.first << ' ' << mi.second << endl;
                // if(mx.first >= mid) vec.push_back(mx);
                // if(mi.first >= mid) vec.push_back(mi);
            }
            if(big+m < (n+m+1)/2){
                ng = mid;
                continue;
            }
            sort(vec.begin(), vec.end());
            ll tmp = 0, need = (n+m+1)/2;
            for(auto [len, cnt]: vec){
                // cout << len << ' ' << cnt << endl;
                if(need == 0){
                    break;
                }else if(need-cnt < 0){
                    tmp += need*len;
                    need = 0;
                }else{
                    tmp += cnt*len;
                    need -= cnt;
                }
            }
            // cout << mid << ' ' << sum << ' ' << tmp << ' ' << need << endl;
            if(need == 0 && (sum-tmp) >= (n+m-1)/2) ok = mid;
            else ng = mid;
        }

        cout << ok << endl;
    }
    return 0;
}