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
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    string s, t; cin >> s >> t;
    int n = (int)s.size();
    vector<int> p, q;
    rep(i, 0, n){
        if(s[i] != t[i]){
            if(s[i] > t[i]) p.push_back(i);
            else q.push_back(i);
        }
    }
    reverse(q.begin(), q.end());
    vector<string> ans;
    for(auto pp: p){
        s[pp] = t[pp];
        ans.push_back(s);
    }
    for(auto qq: q){
        s[qq] = t[qq];
        ans.push_back(s);
    }
    cout << ans.size() << endl;
    for(auto a: ans){
        cout << a << endl;
    }
    
    return 0;
}