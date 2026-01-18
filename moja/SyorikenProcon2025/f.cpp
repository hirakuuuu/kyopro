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
    ll n, x; cin >> n >> x;
    vector<vector<ll>> s(n);
    rep(i, 0, n){
        int k; cin >> k;
        s[i].reserve(k);
        rep(j, 0, k){
            ll ss; cin >> ss; 
            s[i].push_back(ss);
        }
    }

    vector<ll> nums;
    auto f = [&](auto self, int pos, ll tmp) -> void {
        if(pos == n){
            nums.push_back(tmp);
            return;
        }
        rep(j, 0, s[pos].size()){
            tmp += s[pos][j];
            self(self, pos+1, tmp);
            tmp -= s[pos][j];
        }
        return;
    };
    f(f, 0, 0);
    sort(nums.begin(), nums.end());
    cout << nums.end()-lower_bound(nums.begin(), nums.end(), x) << endl;
    return 0;
}