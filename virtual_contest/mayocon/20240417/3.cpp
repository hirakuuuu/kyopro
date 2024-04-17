#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

vector<pair<char, int>> encode(const string& str) {
    int n = (int)str.size();
    vector<pair<char, int>> ret;
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}

int main(){
    string s, t; cin >> s >> t;
    vector<pair<char, int>> ps = encode(s);
    vector<pair<char, int>> pt = encode(t);
    if(ps.size() != pt.size()){
        cout << "No" << endl;
        return 0;
    }
    bool f = true;
    rep(i, 0, ps.size()){
        if(ps[i].first != pt[i].first){
            f = false;
        }else{
            if(pt[i].second < ps[i].second){
                f = false;
            }else if(pt[i].second > 1 && ps[i].second == 1){
                f = false;
            }
        }
    }
    if(!f) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}