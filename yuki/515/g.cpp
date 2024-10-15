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
    char alpha; cin >> alpha;

    map<pair<char, char>, bool> used;
    auto query = [&](char alpha, char beta) -> string {
        assert(!used[make_pair(alpha, beta)]);
        used[{alpha, beta}] = true;
        cout << "? " << alpha << beta << endl;
        string op, res; cin >> op >> res;
        assert(res != "LOSE");
        if(op == "?"){
            used[{res[0], res[1]}] = true;
        }
        return res;
    };

    string res = query(alpha, alpha);
    while(res != "WIN"){
        res = query(res[1], alpha);
    }


    
    
    return 0;
}