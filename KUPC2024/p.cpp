#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main(){
    int n, m; cin >> n >> m;
    vector<ll> a(m);
    unordered_map<ll, int> cnt;
    mint sum_a = 0;
    rep(i, 0, m){
        cin >> a[i];
        sum_a += a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());

    // \sum\sum (ai-aj)^2 
    mint sum1 = 0;
    sum1 -= sum_a.pow(2)*2;
    rep(i, 0, m){
        sum1 += mint(a[i]).pow(2)*2*m;
    }
    sum1 /= 2;

    // \sum\sum (n-(ai-aj))^2 
    mint sum2 = 0;
    sum2 += sum1*2;
    sum2 += mint(m).pow(2)*mint(n).pow(2);
    
    mint acc = 0;
    rep(i, 0, m){
        acc += a[i];
        mint tmp = a[i]*(i+1)-acc;
        sum2 -= mint(2)*n*tmp*2;
    }
    // a[i] == a[j] となるペアの分だけ引く
    // mint two = mint(2).inv();
    for(auto [key, val]: cnt){
        sum2 -= mint(n).pow(2)*val*val;
    }
    sum2 /= 2;

    // cout << sum1.val() << ' ' << sum2.val() << endl;

    mint intersect = (sum1+sum2)/2/mint(n).pow(2);

    mint ans = (m+1)+intersect;

    cout << ans.val() << endl;
    return 0;
}