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

bool is_palindrome(string s){
    int n = (int)s.size();
    rep(i, 0, n){
        if(s[i] == s[n-1-i]) continue;
        return false;
    }
    return true;
}

int main(){
    int T; cin >> T;
    while(T--){
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        string sr = s;
        reverse(sr.begin(), sr.end());

        if(k <= n){
            // s' の文字が決まる
            string t(k, '*');
            rrep(i, k-1, 0) t[i] = s[k-1-i];
            string st = s+t;
            string ts = t+s;
            if(is_palindrome(st) && is_palindrome(ts)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }else{
            ll q = (k-n)/(n*2), r = (k-n)%(n*2);
            if(q%2 == 0){
                string t(r, '*');
                string srs = sr+s;
                rep(i, 0, r) t[i] = srs[2*n-1-i];
                string st = t+srs;
                if(is_palindrome(st) && is_palindrome(t)) cout << "Yes" << endl;
                else cout << "No" << endl;
            }else{
                string t(r, '*');
                string srs = sr+s;
                rrep(i, r-1, 0) t[i] = srs[r-1-i];
                string st = srs+t;
                if(is_palindrome(st) && is_palindrome(t)) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        }
    }
    
    return 0;
}