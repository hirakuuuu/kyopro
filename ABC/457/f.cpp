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
    int n; cin >> n;
    vector<int> d(n-1);
    rep(i, 0, n-1) cin >> d[i];

    int now = -1;
    int pos = 0;
    mint ans = 0;
    vector<int> p(n);
    while(pos < n-1){
        int nxt = pos;
        while(nxt < n-1 && d[pos] == d[nxt]) nxt++;
        if(nxt == n-1){
            if(d[pos] == 1 && (now == -1 || now == n-1 || now == n-2)){
                if(now == -1) ans *= 2;
            }else{
                ans = 0;
            }
            break;
        }
        if(now == -1){
            p[nxt-1] = 1;
            p[nxt-1+d[nxt-1]] = 1;
            now = nxt-1+d[nxt-1];
            ans *= 2;
        }else{
            if(now < nxt-1){
                ans = 0;
                break;
            }
            // nxt-1 <= now
            if(p[nxt-1]){
                if(nxt-1 != now){
                    ans = 0;
                }else{
                    p[now+d[nxt-1]] = 1;
                    now += d[nxt-1];
                }
            }else{
                if(abs(now-(nxt-1)) != d[nxt-1]){
                    ans = 0;
                }
            }
        }
        pos = nxt;
    }

    int cnt = 0;
    rep(i, 0, n){
        
    }
    
    return 0;
}