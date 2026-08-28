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
    vector<int> a(n);
    vector<int> acc(250005);
    rep(i, 0, n){
        cin >> a[i];
        acc[0]++;
        acc[a[i]]--;
    }
    rep(i, 1, 250005) acc[i] += acc[i-1];

    vector<int> ans;
    rep(i, 0, 250000){
        ans.push_back(acc[i]%10);
        acc[i+1] += acc[i]/10;
    }
    while(ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    for(auto aa: ans) cout << aa;
    cout << endl;
    
    return 0;
}