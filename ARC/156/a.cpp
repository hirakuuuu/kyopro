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
        int n; cin >> n;
        string s; cin >> s;
        
        int cnt = 0;
        rep(i, 0, n) cnt += s[i]-'0';
        if(cnt%2 == 1){
            cout << -1 << endl;
        }else{
            if(cnt >= 4 || cnt == 0){
                cout << cnt/2 << endl;
            }else{
                int adj = -1;
                rep(i, 0, n-1){
                    if(s[i] == '1' && s[i+1] == '1') adj = i;
                }
                if(adj == -1){
                    cout << 1 << endl;
                }else{
                    if(n == 3) cout << -1 << endl;
                    else if(n == 4 && adj == 1) cout << 3 << endl;
                    else cout << 2 << endl;
                }
            }
        }
    }
    
    return 0;
}