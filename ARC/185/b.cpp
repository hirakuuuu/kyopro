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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        rep(i, 0, n) cin >> a[i];
        vector<ll> acc(n+1);
        rep(i, 0, n) acc[i+1] = acc[i]+a[i];
        
        // [0, i) を mean にできる
        ll mean = 0, sum_a = 0;
        deque<pair<ll, ll>> que;
        rep(i, 0, n){
            // cout << i << ' ' << mean << endl;
            if(a[i] == mean) continue;
            if(a[i] < mean){
                que.push_back({a[i], mean});
            }else{
                while(!que.empty() && a[i] > mean){
                    auto [cur, goal] = que.front(); que.pop_front();
                    if(goal-cur <= a[i]-mean){
                        a[i] -= (goal-cur);
                    }else{
                        que.push_front({cur+(a[i]-mean), goal});
                        a[i] = mean;
                    }
                }
                if(que.empty()){
                    // 残りの a[i] を割り振る
                    mean = (acc[i+1]+i)/(i+1);
                }
            }
        }
        if(que.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}