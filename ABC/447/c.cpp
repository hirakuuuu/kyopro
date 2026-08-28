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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    string sa, st;
    rep(i, 0, n){
        if(s[i] != 'A') sa += s[i];
    }
    rep(i, 0, m){
        if(t[i] != 'A') st += t[i];
    }
    if(sa != st){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<char, int>> cs, ct;
    s = "B"+s;
    t = "B"+t;
    for(int i = 0; i < n+1; ){
        int j = i+1;
        while(j < n+1 && s[j] == 'A') j++;
        cs.push_back({s[i], j-i-1});
        i = j;
    }
    for(int i = 0; i < m+1; ){
        int j = i+1;
        while(j < m+1 && t[j] == 'A') j++;
        ct.push_back({t[i], j-i-1});
        i = j;
    }
    assert(cs.size() == ct.size());
    int ans = 0;
    rep(i, 0, cs.size()){
        ans += abs(cs[i].second-ct[i].second);
    }
    cout << ans << endl;
    return 0;
}