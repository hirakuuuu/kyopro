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

int main(){
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> cnt_c(n+1);
    rep(i, 0, n-1){
        cnt_c[i+2] = cnt_c[i+1];
        if(s[i] == 'A' and s[i+1] == 'C'){
            cnt_c[i+2]++;
        }
    }
    while(q--){
        int l, r; cin >> l >> r;
        cout << cnt_c[r]-cnt_c[l] << endl;

    }
    
    return 0;
}