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
    int n; cin >> n;
    string s; cin >> s;
    
    ll cnt = 0, sum = 0;
    rep(i, 0, n){
        if(s[i] == '1') cnt++, sum += i;
    }
    ll cnt_pre = 0, sum_pre = 0, ans = INF;
    rep(i, 0, n){
        if(s[i] == '1'){
            cnt--, sum -= i;
            ll tmp1 = ((ll)i*cnt_pre-sum_pre)-(cnt_pre*(cnt_pre+1)/2);
            ll tmp2 = (sum-(ll)i*cnt)-(cnt*(cnt+1)/2);
            chmin(ans, tmp1+tmp2);
            cnt_pre++, sum_pre += i;
        }
    }
    cout << ans << endl;
    
    return 0;
}