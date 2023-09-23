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
// https://atcoder.jp/contests/abc321/tasks/abc321_b

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n-1);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end());

    int sum = 0;
    rep(i, 0, n-2) sum += a[i];
    if(sum >= x){
        cout << 0 << endl;
        return 0;
    }
    sum -= a[0];
    if(a[0] <= x-sum && x-sum <= a[n-2]){
        cout << x-sum << endl;
        return 0;
    }

    sum += a[n-2];
    if(sum >= x){
        cout << a[n-2] << endl;
        return 0;
    }

    cout << -1 << endl;
    
    return 0;
}