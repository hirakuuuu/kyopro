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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(j, 0, h){
        cin >> s[j];
        for(int i = 0; i+5 < w; ){
            if(s[j].substr(i, 6) == "yiwiy9"){
                s[j][i+4] = 'Y';
                i += 6;
            }else if(s[j].substr(i, 6) == "9yiwiy"){
                s[j][i+1] = 'Y';
                i += 6;
            }else{
                i++;
            }
        }
        cout << s[j] << endl;
    }
    
    return 0;
}