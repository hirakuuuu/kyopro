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

/*
英小文字のみからなる -> 文字種が26種類
できるだけ辞書順で速い文字を追加していくのが最適（ただし、残りの文字数が足りなくなるのはNG）
*/

int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> p(26);
    rep(i, 0, n){
        p[s[i]-'a'].push_back(i);
    }

    string ans;
    int tmp = 0;
    rep(i, 0, k){
        rep(j, 0, 26){
            auto itr = lower_bound(p[j].begin(), p[j].end(), tmp);
            if(itr == p[j].end()) continue;
            if(n-*itr < k-i) continue;
            tmp = (*itr)+1;
            ans += (char)('a'+j);
            break;
        }
    }
    cout << ans << endl;
    
    return 0;
}