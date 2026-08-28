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
    vector<ll> p = {1};
    rep(i, 1, 30) p.push_back(p.back()*2);
    vector<ll> ten(10);
    ten[0] = 1;
    rep(i, 1, 10) ten[i] = ten[i-1]*10;
    vector<ll> nums;
    auto f = [&](auto self, ll tmp) -> void {
        if(tmp > 0) nums.push_back(tmp);
        for(auto pp: p){
            ll len = to_string(pp).size();
            ll now = tmp*ten[len]+pp;
            if(now <= 1e9){
                self(self, now);
            }
        }
    };
    f(f, 0);
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    ll n; cin >> n;
    cout << nums[n-1] << endl;
    
    return 0;
}