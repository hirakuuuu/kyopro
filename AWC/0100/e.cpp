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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> a(n);
    rep(i, 0, n){
        a[i].second = i;
        cin >> a[i].first;
    }
    sort(a.rbegin(), a.rend());
    vector<int> ans(n);
    ans[a[0].second] = 0;
    int cnt = 1, now = 0;
    rep(i, 1, n){
        if(a[i-1].first > a[i].first){
            now += cnt;
            cnt = 1;
        }else{
            cnt++;
        }
        ans[a[i].second] = now;
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}