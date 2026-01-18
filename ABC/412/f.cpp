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
constexpr int IINF = 1001001001;
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n, c; cin >> n >> c;
    c--;
    vector<int> a(n);
    vector<int> cnt(3005);
    mint sum = 1;
    rep(i, 0, n){
        cin >> a[i];
        sum += a[i];
        if(i == c) a[c]++;
        cnt[a[i]]++;
    }

    vector<int> s;
    rep(i, 1, 3002){
        if(cnt[i] > 0) s.push_back(i);
    }

    int m = (int)s.size();
    vector<mint> dp(m);
    mint cur = 0;
    mint ans = 0;
    rrep(i, m-1, 0){
        cur += s[i]-1;
        dp[i] += (sum-1)/cur;
        rep(j, i+1, m){
            mint tmp = cnt[s[j]]*(s[j]);
            dp[i] += (tmp/cur)*dp[j];
        }
        if(a[c] == s[i]){
            ans = dp[i];
            break;
        }
        cur -= s[i]-1;
        cur += cnt[s[i]]*s[i];
    }
    cout << ans.val() << endl;
    return 0;
}