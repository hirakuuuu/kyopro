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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll power(ll a, ll b, ll m=MOD){
    ll res = 1;
    while(b > 0){
        if(b%2 == 1) res = res*a%m;
        a = a*a%m;
        b /= 2;
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }
    vector<vector<int>> g(400000);
    rep(i, 0, n){
        g[2*x[i]].push_back(2*y[i]+1);
        g[2*y[i]+1].push_back(2*x[i]);
    }
    vector<bool> seen(400000);
    ll sum = 0;
    rep(i, 0, 400000){
        if(seen[i]) continue;
        vector<ll> cnt(2);
        queue<int> que;
        seen[i] = true;
        que.push(i);
        cnt[i%2]++;
        while(!que.empty()){
            int q = que.front(); que.pop();
            for(auto nq: g[q]){
                if(seen[nq]) continue;
                cnt[nq%2]++;
                seen[nq] = true;
                que.push(nq);
            }
        }
        sum += cnt[0]*cnt[1];
    }
    cout << sum-(ll)n << endl;

    
    return 0;
}