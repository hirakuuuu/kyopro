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
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i] >> b[i];
    }

    vector<int> t;
    map<int, vector<int>> A;
    rep(i, 0, n){
        t.emplace_back(b[i]);
        A[b[i]].push_back(a[i]);
    }

    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    vector<int> lis(n+1, IINF);
    lis[0] = -1;
    int ans = 1;
    map<int, int> mp;
    for(auto pb: t){
        mp.clear();
        for(auto pa: A[pb]){
            int len = lower_bound(lis.begin(), lis.end(), pa)-lis.begin();
            chmax(ans, len);
            if(mp.count(len)) chmin(mp[len], pa);
            else mp[len] = pa;
        }
        for(auto [key, val]: mp){
            lis[key] = val;
        }
    }
    cout << ans << endl;
    

    return 0;
}