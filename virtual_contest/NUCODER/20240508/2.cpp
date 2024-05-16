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
    string s, t; cin >> s >> t;
    string ans;
    rep(i, 0, s.size()-t.size()+1){
        string u = s.substr(i, t.size());
        bool ok = true;
        rep(j, 0, t.size()){
            if(u[j] == '?' || u[j] == t[j]) continue;
            ok = false;
            break;
        }
        if(ok){
            string tmp;
            rep(j, 0, s.size()){
                if(j < i || i+t.size() <= j){
                    if(s[j] == '?') tmp += 'a';
                    else tmp += s[j];
                }else{
                    tmp += t[j-i];
                }
            }
            if(ans == "") ans = tmp;
            else chmin(ans, tmp);
        }
    }
    if(ans == "") cout << "UNRESTORABLE" << endl;
    else cout << ans << endl;


    return 0;
}