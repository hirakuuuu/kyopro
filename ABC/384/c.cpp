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
    vector<int> a(5);
    rep(i, 0, 5) cin >> a[i];


    vector<pair<int, string>> s(31);
    rep(i, 1, 32){
        rep(j, 0, 5){
            if(i>>j&1){
                s[i-1].first -= a[j];
                s[i-1].second += (char)('A'+j);
            }
        }
    }
    sort(s.begin(), s.end());
    rep(i, 0, 31){
        cout << s[i].second << endl;
    }
    
    return 0;
}