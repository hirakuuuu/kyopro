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
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<int> ans(n+1, IINF);
    vector<int> cnt(n+1);
    rep(k, 1, min(1000, n+1)){
        ans[k] = 0;
        for(int l = 0; l < n; ){
            int r = l;
            int kind = 0;
            while(r < n){
                if(cnt[a[r]] == 0 && kind == k) break;
                if(cnt[a[r]] == 0) kind++;
                cnt[a[r]]++;
                r++;
            }
            ans[k]++;
            rep(i, l, r) cnt[a[i]]--;
            kind = 0;
            l = r;
        }
    }

    int mi = 1000;
    rrep(i, 101, 1){
        int ok = 0, ng = n+1;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            int tmp = 0;
            for(int l = 0; l < n; ){
                int r = l;
                int kind = 0;
                while(r < n){
                    if(cnt[a[r]] == 0 && kind == mid) break;
                    if(cnt[a[r]] == 0) kind++;
                    cnt[a[r]]++;
                    r++;
                }
                tmp++;
                rep(j, l, r) cnt[a[j]]--;
                kind = 0;
                l = r;
            }
            if(tmp >= i) ok = mid;
            else ng = mid;
        }
        // cout << i << ' ' << ok << endl;
        rep(j, mi, ok+1) ans[j] = i;
        mi = ok+1;
    }

    rep(k, 1, n+1){
        cout << ans[k] << endl;
    }
    return 0;
}
