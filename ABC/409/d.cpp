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
    int t; cin >> t;

    auto f = [&](string &s, int pos) -> string{
        while(pos < (int)s.size()-1 && s[pos] >= s[pos+1]){
            swap(s[pos], s[pos+1]);
            pos++;
        }
        return s;
    };
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        
        int p = -1;
        rep(i, 0, n-1){
            if(s[i] > s[i+1]){
                p = i;
                break;
            }
        }
        if(p != -1){
            cout << f(s, p) << endl;
        }else{
            cout << s << endl;
        }

    }
    return 0;
}