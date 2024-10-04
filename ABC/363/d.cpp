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
    ll n; cin >> n;
    if(n <= 10){
        cout << n-1 << endl;
        return 0;
    }else if(n <= 19){
        n -= 10;
        cout << n << n << endl;
        return 0;
    }
    n -= 20;
    ll tmp = 9*10;
    int len = 2;
    while(true){
        if(n < tmp){
            string s;
            rep(i, 0, len){
                s += '0'+n%10;
                n /= 10;
            }
            if(s.back() == '9') s.back() = '1';
            else s.back() = s.back()+1;
            string t = s;
            reverse(s.begin(), s.end());
            cout << s << t.substr(1, len-1) << endl;
            return 0;
        }else if(n < 2*tmp){
            n -= tmp;
            string s;
            rep(i, 0, len){
                s += '0'+n%10;
                n /= 10;
            }
            if(s.back() == '9') s.back() = '1';
            else s.back() = s.back()+1;
            string t = s;
            reverse(s.begin(), s.end());
            cout << s << t << endl;
            return 0;
        }else{
            n -= 2*tmp;
            tmp *= 10;
            len++;
        }
    }
    return 0;
}