#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<string> abc = {"ABC", "BCA", "CAB"};
    stack<char> S, T;
    rep(i, 0, n){
        S.push(s[i]);
        if(S.size() >= 3){
            string tmp;
            rep(_, 0, 3){
                tmp += S.top(); S.pop();
            }
            reverse(tmp.begin(), tmp.end());
            bool ok = false;
            rep(j, 0, 3){
                if(abc[j] == tmp) ok = true;
            }
            if(ok) continue;
            rep(j, 0, 3){
                S.push(tmp[j]);
            }
        }
    }
    rep(i, 0, n){
        T.push(t[i]);
        if(T.size() >= 3){
            string tmp;
            rep(_, 0, 3){
                tmp += T.top(); T.pop();
            }
            reverse(tmp.begin(), tmp.end());
            bool ok = false;
            rep(j, 0, 3){
                if(abc[j] == tmp) ok = true;
            }
            if(ok) continue;
            rep(j, 0, 3){
                T.push(tmp[j]);
            }
        }
    }

    string fs, ft;
    while(!S.empty()){
        fs += S.top(); S.pop();
    }
    while(!T.empty()){
        ft += T.top(); T.pop();
    }
    if(fs == ft) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}