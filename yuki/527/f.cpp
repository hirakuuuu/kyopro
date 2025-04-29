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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<ll> A(n), I(n), Q(n);
    int cnt_q = 0;
    rep(i, 0, n){
        if(s[i] == '?') cnt_q++;
    }
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        a--, b--;
        if(s[a] == 'o' || s[a] == '?'){
            if(s[b] == 'a') A[a]++;
            if(s[b] == 'i') I[a]++;
            if(s[b] == '?') Q[a]++;
        }
        if(s[b] == 'o' || s[b] == '?'){
            if(s[a] == 'a') A[b]++;
            if(s[a] == 'i') I[b]++;
            if(s[a] == '?') Q[b]++;
        }
    }

    mint ans = 0;
    rep(i, 0, n){
        // cout << A[i] << ' ' << I[i] << ' ' << Q[i] << endl;
        if(s[i] == 'o'){
            ans += mint(26).pow(cnt_q)*A[i]*I[i];
            if(cnt_q >= 1) ans += mint(26).pow(cnt_q-1)*A[i]*Q[i];
            if(cnt_q >= 1) ans += mint(26).pow(cnt_q-1)*Q[i]*I[i];
            if(cnt_q >= 2) ans += mint(26).pow(cnt_q-2)*Q[i]*(Q[i]-1);
        }else if(s[i] == '?'){
            if(cnt_q >= 1) ans += mint(26).pow(cnt_q-1)*A[i]*I[i];
            if(cnt_q >= 2) ans += mint(26).pow(cnt_q-2)*A[i]*Q[i];
            if(cnt_q >= 2) ans += mint(26).pow(cnt_q-2)*Q[i]*I[i];
            if(cnt_q >= 3) ans += mint(26).pow(cnt_q-3)*Q[i]*(Q[i]-1);
        }
    }
    cout << ans.val() << endl;
    return 0;
}