#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> a(n);
    rep(i, 0, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int mx = 0;
    vector<int> ans = {-1};
    rrep(i, n-1, n-k){
        mx += a[i].first;
        ans.push_back(a[i].second);
    }
    ans.push_back(n);
    sort(ans.begin(), ans.end());
    cout << mx << endl;
    rep(i, 0, k-1){
        cout << ans[i+1]-ans[i] << ' ';
    }
    cout << n-1-ans[k-1] << endl;
    return 0;
}