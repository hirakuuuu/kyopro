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
    int d, n; cin >> d >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    
    vector<int> ans;
    rep(i, 1, 10000001){
        int cnt = 0, j = i;
        while(j%100 == 0){
            cnt++;
            j /= 100;
        }
        if(cnt == d) ans.push_back(i);
    }
    cout << ans[n-1] << endl;
    return 0;
}