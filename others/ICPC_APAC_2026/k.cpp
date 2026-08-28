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

/*
値の大きい方から当てはめていけばよい
*/

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> cnt(10);
        rep(i, 0, n){
            cnt[s[i]-'0']++;
        }

        int ans0 = 0;
        {
            ll ok = 0, ng = n;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(cnt[0]-mid >= 0 && cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]-mid >= mid){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            ans0 += ok;
        }

        int rest = ans0;
        cnt[0] -= rest;
        if(cnt[0] > rest){
            cnt[0] -= rest;
            rest = 0;
        }else{
            rest -= cnt[0];
            cnt[0] = 0;
        }

        rep(i, 2, 6){
            if(rest >= cnt[i]){
                rest -= cnt[i];
                cnt[i] = 0;
            }else{
                cnt[i] -= rest;
                rest = 0;
            }
        }
        if(rest > 0){
            assert(cnt[1] >= rest);
            cnt[1] -= rest;
            rest = 0;
        }
        int ans1 = 0;
        {
            ll ok = 0, ng = n;
            while(ng-ok > 1){
                ll mid = (ok+ng)/2;
                if(cnt[1]-mid*2 >= 0 && cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]-mid*2 >= mid){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            ans1 += ok;
        }
        cout << min(n/4, ans0+ans1) << endl;
    }
    
    return 0;
}