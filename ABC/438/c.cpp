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
    rep(i, 0, n) cin >> a[i];
    vector<pair<int, int>> rlc;
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[j] == a[i]){
            j++;
        }
        if((j-i)%4 != 0){
            rlc.emplace_back(a[i], (j-i)%4);
        }
        i = j;
    }

    vector<pair<int, int>> stc;
    for(auto [num, len]: rlc){
        if(stc.empty() || stc.back().first != num){
            stc.emplace_back(num, len);
        }else{
            stc.back().second += len;
            stc.back().second %= 4;
            if(stc.back().second == 0) stc.pop_back();
        }
    }

    int ans = 0;
    for(auto [num, len]: stc) ans += len;
    cout << ans << endl;

    
    return 0;
}