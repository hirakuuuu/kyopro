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
    int n; cin >> n;
    vector<int> l(n), r(n);
    rep(i, 0, n) cin >> l[i] >> r[i];
    vector<int> ans(n);
    int start = 0;
    while(start < n){
        int last = start+1, mi = l[start], mx = r[start];
        while(last < n && max(mi, l[last]) <= min(mx, r[last])){
            chmax(mi, l[last]);
            chmin(mx, r[last]);
            last++;
        }
        if(last == n){
            if(start == 0){
                rep(i, start, n){
                    ans[i] = mi;
                }
            }else if(mx < ans[start-1]){
                rep(i, start, n){
                    ans[i] = mx;
                }
            }else{
                rep(i, start, n){
                    ans[i] = mi;
                }
            }
        }else{
            if(start == 0){
                if(mx < l[last]){
                    rep(i, start, last){
                        ans[i] = mx;
                    }
                }else{
                    rep(i, start, last){
                        ans[i] = mi;
                    }
                }
            }else{
                if(mx <= ans[start-1] && mx <= l[last]){
                    rep(i, start, last){
                        ans[i] = mx;
                    }
                }else{
                    rep(i, start, last){
                        ans[i] = mi;
                    }
                }
            }
        }
        start = last;
    }
    // rep(i, 0, n){
    //     cout << ans[i] << ' ';
    // }
    rrep(i, n-1, 0){
        // 辞書順で最小になるように戻していく
        if(i > 0 && ans[i-1] <= ans[i]){
            ans[i] = max(ans[i-1], l[i]);
        }
        if(i < n-1 && ans[i+1] <= ans[i]){
            ans[i] = max(ans[i+1], l[i]);
        }
    }
    rep(i, 0, n){
        // 辞書順で最小になるように戻していく
        if(i > 0 && ans[i-1] <= ans[i]){
            ans[i] = max(ans[i-1], l[i]);
        }
        if(i < n-1 && ans[i+1] <= ans[i]){
            ans[i] = max(ans[i+1], l[i]);
        }
    }
    rep(i, 0, n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}