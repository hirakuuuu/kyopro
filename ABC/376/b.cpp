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
    int n, q; cin >> n >> q;
    int l = 0, r = 1, cnt = 0;
    while(q--){
        char h; cin >> h;
        int t; cin >> t; t--;
        int tmp = IINF;
        if(h == 'L'){
            int start = l, goal = t;
            if(start > goal) swap(start, goal);
            if(inr(start, r, goal)) chmin(tmp, (start-goal+n)%n);
            else chmin(tmp, (goal-start)%n);
            l = t;
        }else{
            int start = r, goal = t;
            if(start > goal) swap(start, goal);
            if(inr(start, l, goal)) chmin(tmp, (start-goal+n)%n);
            else chmin(tmp, (goal-start)%n);
            r = t;
        }
        cnt += tmp;
    }
    cout << cnt << endl;
    
    return 0;
}