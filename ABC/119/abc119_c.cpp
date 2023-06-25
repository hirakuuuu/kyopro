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
// https://atcoder.jp/contests/abc119/tasks/abc119_c

int main(){
    int n; cin >> n;
    vector<int> a(3);
    rep(i, 0, 3) cin >> a[i];
    vector<int> l(n);
    rep(i, 0, n) cin >> l[i];

    int lim = 1, ans = 1001001001;
    rep(i, 0, n) lim *= 4;
    vector<int> sum(4), cnt(4);
    rep(i, 0, lim){
        rep(j, 0, 4) sum[j] = cnt[j] = 0;
        int tmp = i;
        rep(j, 0, n){
            sum[tmp%4] += l[j];
            cnt[tmp%4]++;
            tmp /= 4;
        }

        bool ng = false;
        rep(j, 0, 3){
            if(sum[j] == 0) ng = true;
        }
        if(ng) continue;

        int total = 0;
        rep(j, 0, 3) total += (cnt[j]-1)*10+abs(a[j]-sum[j]);
        chmin(ans, total);
    }

    cout << ans << endl;
    
    return 0;
}