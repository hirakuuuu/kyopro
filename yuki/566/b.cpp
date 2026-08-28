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


ll gcd(ll a, ll b){
    if(a%b == 0){
      return b;
    }else{
      return gcd(b, a%b);
    }
}

int main(){
    int n; cin >> n;
    vector<int> p(n);
    vector<int> rev(n);
    rep(i, 0, n){
        cin >> p[i]; p[i]--;
        rev[p[i]] = i;
    }

    vector<vector<int>> nums;
    vector<int> seen(n);
    rep(i, 0, n){
        if(seen[i]) continue;
        queue<int> que;
        que.push(i);
        seen[i] = 1;
        nums.push_back({});
        while(!que.empty()){
            int q = que.front(); que.pop();
            nums.back().push_back(q);
            if(seen[p[q]]) continue;
            que.push(p[q]);
            seen[p[q]] = 1;
        }
    }
    vector<int> cnt(n);
    for(auto vec: nums){
        if(vec.size() == 1) continue;
        sort(vec.begin(), vec.end());
        int g = vec[1]-vec[0];
        rep(i, 2, (int)vec.size()){
            g = gcd(g, vec[i]-vec[i-1]);
        }
        // cout << g << endl;
        for(int i = 1; i*i <= g; i++){
            if(g%i == 0){
                cnt[i] += (int)vec.size()-1;
                if(i != g/i) cnt[g/i] += (int)vec.size()-1;
            }
        }
    }

    rep(i, 1, n){
        cout << cnt[i] << endl;
    }
    return 0;
}