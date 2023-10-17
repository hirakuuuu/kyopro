#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    int n; cin >> n;
    string s; cin >> s;
    set<pair<int, int>> pos;
    pos.insert({0, 0});
    int cx = 0, cy = 0;
    string d = "LDRU";
    rep(i, 0, n){
        rep(j, 0, 4){
            if(s[i] == d[j]){
                cx += (j-1)%2;
                cy += (j-2)%2;
                pos.insert({cx, cy});
            }
        }
    }

    if(pos.size() < n+1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}