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
    ll n; cin >> n;

    unordered_map<int, int> cnt;
    for(int x = 1; x*x <= n; x++){
        for(int y = x+1; x*x+y*y <= n; y++){
            cnt[x*x+y*y]++;
        }
    }
    vector<int> a;
    for(auto [key, val]: cnt){
        if(val == 1) a.push_back(key);
    }
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for(auto aa: a){
        cout << aa << ' ';
    }
    cout << endl;
    
    return 0;
}