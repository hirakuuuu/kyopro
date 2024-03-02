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
// https://atcoder.jp/contests/abc342/tasks/abc342_d

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    map<ll, ll> cnt;
    rep(i, 0, n) cnt[a[i]]++;
    
    ll ans = cnt[0]*(n-cnt[0])+cnt[0]*(cnt[0]-1)/2;
    for(ll i = 1; i <= 200000; i++){
        vector<ll> y;
        for(ll j = 1; j*j <= i; j++){
            if(i%j == 0){
                y.push_back(j);
                if(j != i/j) y.push_back(i/j);
            }
        }
        sort(y.begin(), y.end());
        set<ll> ys;
        for(auto y1: y){
            for(auto y2: y){
                if(max(y1*y2, (i*i)/(y1*y2)) > 200000 || y1*y2 == (i*i)/(y1*y2)) continue;
                ys.insert(min(y1*y2, (i*i)/(y1*y2)));
            }
        }
        for(auto yy: ys){
            ans += cnt[yy]*cnt[(i*i)/yy];
        }
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans << endl;


    return 0;
}