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

int bitLength(int num) {
    int length = 0;
    while (num > 0) {
        num >>= 1;
        length++;
    }
    return length;
}

int main(){
    ll k, a, b; cin >> k >> a >> b;

    // // k が偶数のとき，2 で割れるだけ割って，奇数とする
    // int cnt_2 = 0;
    // while(k%2 == 0){
    //     k /= 2;
    //     cnt_2++;
    // }

    int mx_pc = __popcount(k);
    ll ans = mx_pc*a+bitLength(k)*b;

    queue<pair<int, int>> que;
    vector<vector<ll>> seen(mx_pc+1, vector<ll>(k, -1));
    seen[1][1%k] = 1;
    que.push({1, 1%k});
    while(!que.empty()){
        auto [pc, r] = que.front(); que.pop();
        if(seen[pc][(r*2)%k] != -1) continue;
        seen[pc][(r*2)%k] = seen[pc][r]+1;
        que.push({pc, (r*2)%k});
        if(pc+1 < mx_pc){
            if(seen[pc+1][(r*2+1)%k] != -1) continue;
            seen[pc+1][(r*2+1)%k] = seen[pc][r]+1;
            que.push({pc+1, (r*2+1)%k});
        } 
    }

    rep(i, 1, mx_pc){
        if(seen[i][0] == -1) continue;
        chmin(ans, a*i+seen[i][0]*b);
    }
    cout << ans << endl;



    
    return 0;
}