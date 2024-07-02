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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];

    int ans = (h-1)+(w-1);
    rep(i, 0, 1<<(h-1)){
        vector<int> st(h);
        rep(j, 0, h-1){
            if((i>>j)&1) st[j+1] = st[j]+1;
            else st[j+1] = st[j];
        }
        vector<int> cnt(h);
        bool ok = true;
        int tmp = st[h-1];
        rep(j, 0, w){
            rep(l, 0, h) cnt[st[l]] += s[l][j]-'0';
            bool f = false;
            rep(l, 0, h){
                if(cnt[st[l]] > k) f = true;
            }
            if(f){
                tmp++;
                rep(l, 0, h) cnt[st[l]] = 0;
                rep(l, 0, h) cnt[st[l]] += s[l][j]-'0';
                rep(l, 0, h){
                    if(cnt[st[l]] > k) ok = false;
                }
            }
        }
        if(ok) chmin(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}