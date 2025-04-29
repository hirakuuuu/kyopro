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
    while(t--){
        string s; cin >> s;
        int n = s.size();
        int pm = 1;
        rep(i, 0, n){
            if(s[i] == '?'){
                if(i == n-1){
                    // 数字にしなければならない
                    if(pm == -1) s[i] = '1';
                    else s[i] = '9';
                }else{
                    if(pm == -1){
                        if(s[i-1] == '-' || s[i+1] == '-' || s[i+1] == '+') s[i] = '1';
                        else s[i] = '+', pm = 1;
                    }else{
                        s[i] = '9';
                    }
                }
            }else if(s[i] == '+'){
                pm = 1;
            }else if(s[i] == '-'){
                pm = -1;
            }
        }
        cout << s << endl;
    }
    return 0;
}