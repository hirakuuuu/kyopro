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
    int q; cin >> q;
    int sum = 0, mi = 0;
    vector<pair<char, int>> s;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            if(c == '(') sum++;
            else sum--;
            chmin(mi, sum);
            s.push_back({c, mi});
        }else{
            char c = s.back().first;
            if(c == ')') sum++;
            else sum--;
            s.pop_back();
            if(s.empty()) mi = 0;
            else mi = s.back().second;
        }
        if(mi >= 0 && sum == 0){
            cout << "Yes" << '\n';
        }else{
            cout << "No" << '\n';
        }
    }
    return 0;
}