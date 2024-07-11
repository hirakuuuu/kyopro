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
    rep(w, 1, s.size()){
        vector<string> ss;
        int l = 0;
        while(l < s.size()){
            if(l+w <= s.size()) ss.push_back(s.substr(l, w));
            else ss.push_back(s.substr(l, s.size()-l));
            l += w;
        }
        rep(c, 0, w){
            string tmp;
            for(auto sss: ss){
                if(sss.size() > c) tmp += sss[c];
            }
            if(tmp == t){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}