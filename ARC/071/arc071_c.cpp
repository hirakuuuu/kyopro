#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc071/tasks/arc071_c

int main(){
    string s, t; cin >> s >> t;
    int q; cin >> q;
    vector<int> sum_s(s.size()+1), sum_t(t.size()+1);
    rep(i, 1, s.size()+1){
        sum_s[i] = sum_s[i-1]+(s[i-1]-'A')+1;
    }
    rep(i, 1, t.size()+1){
        sum_t[i] = sum_t[i-1]+(t[i-1]-'A')+1;
    }
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--, c--;
        if((sum_s[b]-sum_s[a])%3 == (sum_t[d]-sum_t[c])%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}