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
    string s, t; cin >> s >> t;
    string atcoder = "atcoder";
    rep(i, 0, s.size()){
        if(s[i] != t[i]){
            bool ok = false;
            rep(j, 0, 7){
                if((s[i] == '@' && t[i] == atcoder[j]) || (t[i] == '@' && s[i] == atcoder[j])) ok = true;
            }
            if(!ok){
                cout << "You will lose" << endl;
                return 0;
            }
        }
    }
    cout << "You can win" << endl;
    
    
    return 0;
}