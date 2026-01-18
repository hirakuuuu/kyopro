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
    string s; cin >> s;
    int n = (int)s.size();

    ll m = 0;
    bool find_3 = false;
    m = 0;
    rep(i, 0, n){
        if(!find_3 && s[i] == '3'){
            s[i] = '2';
            find_3 = true;
        }else if(find_3){
            s[i] = '9';
        }
        m += s[i]-'0';
        m %= 3;
    }

    if(m == 0){
        rrep(i, n-1, 0){
            if(s[i] != '0'){
                s[i] = s[i]-1;
                if(s[i] == '3') s[i] = s[i]-1;
                break;
            }else{
                s[i] = '9';
            }
        }
    }
    cout << s << endl;




    return 0;
}