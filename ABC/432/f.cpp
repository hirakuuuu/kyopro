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
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum_a = 0;
    rep(i, 0, n){
        cin >> a[i];
        sum_a += a[i];
    }
    if(sum_a%n != 0){
        cout << -1 << endl;
        return 0;
    }
    ll avg = sum_a/n;
    rep(i, 0, n) a[i] -= avg;

    vector<ll> tot(1<<n);
    rep(i, 0, 1<<n){
        rep(j, 0, n){
            if((i>>j)&1) tot[i] += a[j];
        }
    }

    // 累積和としてみると，順列に対して，区切れるところで区切る遷移を考えることで最大化可能
    vector<ll> dp(1<<n);
    rep(i, 0, 1<<n){
        if(tot[i] == 0) dp[i]++;
        rep(j, 0, n){
            if(~i>>j&1){
                chmax(dp[i+(1<<j)], dp[i]);
            }
        }
    }

    vector<ll> p;
    ll s = (1<<n)-1;
    while(s){
        if(tot[s] == 0) dp[s]--;
        rep(j, 0, n){
            if((s>>j)&1){
                if(dp[s] == dp[s-(1<<j)]){
                    p.push_back(j);
                    s -= 1<<j;
                    break;
                }
            }
        }
    }

    vector<tuple<ll, ll, ll>> ans;
    for(ll l = 0; l < n; ){
        ll r = l;
        ll sum = a[p[l]];
        vector<pair<ll, ll>> b = {{a[p[l]], p[l]}};
        while(r < n && sum != 0){
            r++;
            b.push_back({a[p[r]], p[r]});
            sum += a[p[r]];
        }
        sort(b.rbegin(), b.rend());
        rep(i, 0, (ll)b.size()-1){
            ans.push_back({b[i].second, b[i+1].second, b[i].first});
            b[i+1].first += b[i].first;
        }
        l = r+1;
    }
    cout << ans.size() << endl;
    for(auto [x, y, z]: ans){
        cout << x+1 << ' ' << y+1 << ' ' << z << endl;
    }

    return 0;
}