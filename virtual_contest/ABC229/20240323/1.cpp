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
    vector<string> s(2);
    rep(i, 0, 2) cin >> s[i];
    rep(_, 0, 2){
        if(s[0] == ".#" && s[1] == "#."){
            cout << "No" << endl;
            return 0;
        }
        swap(s[0], s[1]);
    }
    cout << "Yes" << endl;
    
    return 0;
}