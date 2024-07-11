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
    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    
    vector<char> ans(n);
    if(a+b+c != 2){
        rep(i, 0, n){
            if(s[i] == "AB"){
                if(a == 0 && b == 0){ cout << "No" << endl; return 0; }
                if(a <= b){ a++, b--; ans[i] = 'A'; }
                else{ a--, b++; ans[i] = 'B'; }
            }else if(s[i] == "AC"){
                if(a == 0 && c == 0){ cout << "No" << endl; return 0; }
                if(a <= c){ a++, c--; ans[i] = 'A'; }
                else{ a--, c++; ans[i] = 'C'; }
            }else{
                if(b == 0 && c == 0){ cout << "No" << endl; return 0; }
                if(b <= c){ b++, c--; ans[i] = 'B'; }
                else{ b--, c++; ans[i] = 'C'; }
            }
        }
    }else{
        rep(i, 0, n){
            if(s[i] == "AB"){
                if(a == 0 && b == 0){ cout << "No" << endl; return 0; }
                if(a == b && i < n-1){
                    if(s[i+1][0] == 'A'){ a++, b--; ans[i] = 'A'; }
                    else{ a--, b++; ans[i] = 'B'; }
                }else{
                    if(a <= b){ a++, b--; ans[i] = 'A'; }
                    else{ a--, b++; ans[i] = 'B'; }
                }
            }else if(s[i] == "AC"){
                if(a == 0 && c == 0){ cout << "No" << endl; return 0; }
                if(a == c && i < n-1){
                    if(s[i+1][0] == 'A'){ a++, c--; ans[i] = 'A'; }
                    else{ a--, c++; ans[i] = 'C'; }
                }else{
                    if(a <= c){ a++, c--; ans[i] = 'A'; }
                    else{ a--, c++; ans[i] = 'C'; }
                }
            }else{
                if(b == 0 && c == 0){ cout << "No" << endl; return 0; }
                if(b == c && i < n-1){
                    if(s[i+1][1] == 'B'){ b++, c--; ans[i] = 'B'; }
                    else{ b--, c++; ans[i] = 'C'; }
                }else{
                    if(b <= c){ b++, c--; ans[i] = 'B'; }
                    else{ b--, c++; ans[i] = 'C'; }
                }
            }
        }
    }
    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << ans[i] << endl;
    }



    
    return 0;
}