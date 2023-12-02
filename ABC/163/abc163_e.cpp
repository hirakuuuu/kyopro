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
// https://atcoder.jp/contests/abc163/tasks/abc163_e

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int i, int j){
        return a[i] > a[j];
    });

    ll ans = 0;
    vector<ll> b = {a[ind[0]]};
    vector<pair<ll, ll>> c = {{-ind[0], ind[0]}};

    rep(i, 1, n){
        vector<ll> sum(i+1);
        rrep(j, i, 1){
            if(c[j-1].first >= 0) sum[j-1] = sum[j]+b[j-1];
            else sum[j-1] = sum[j]-b[j-1];
        }
        ll mx = -9e18, mi = -1, d = -i;
        rep(j, 0, i+1){
            // (i-j)*a[i]+sum[j];
            if(mx < abs(d)*a[ind[i]]+sum[j]){
                mx = abs(d)*a[ind[i]]+sum[j];
                mi = j;
            }
            d++;
        }
        vector<ll> b_;
        vector<pair<ll, ll>> c_;
        bool f = false;
        rep(j, 0, i){
            if(!f && j == mi){
                b_.push_back(a[ind[i]]);
                c_.push_back({j-ind[i], ind[i]});
                f = true;
                j--;
            }else{
                b_.push_back(b[j]);
                if(j < mi) c_.push_back(c[j]);
                else if(j >= mi) c_.push_back({c[j].first+1, c[j].second});
            }
        }

        swap(b, b_);
        swap(c, c_);
    }
    ll tmp = 0;
    rep(i, 0, n){
        tmp += b[i]*abs(c[i].first);
    }
    chmax(ans, tmp);



    cout << ans << endl;


    
    return 0;
}