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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<pair<char, int>> a;
    a.push_back({s[0], 1});
    rep(i, 1, n){
        if(a.back().first == s[i]){
            a.back().second++;
        }else{
            a.push_back({s[i], 1});
        }
    }

    int cnt = 0;
    int m = (int)a.size();
    rep(i, 0, m){
        auto [num, len] = a[i];
        if(num == '1'){
            cnt++;
            if(cnt == k) swap(a[i], a[i-1]);
        }
    }
    rep(i, 0, m){
        rep(j, 0, a[i].second){
            cout << a[i].first;
        }
    }
    cout << endl;
    
    return 0;
}