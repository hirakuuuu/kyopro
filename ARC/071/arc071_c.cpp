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
    vector<int> cnt_as(1e5+5), cnt_at(1e5+5);
    rep(i, 0, s.size()){
        cnt_as[i+1] += cnt_as[i];
        if(s[i] == 'A') cnt_as[i+1]++; 
    }
    rep(i, 0, t.size()){
        cnt_at[i+1] += cnt_at[i];
        if(t[i] == 'A') cnt_at[i+1]++; 
    }
    int q; cin >> q;
    while(q--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int as = cnt_as[b]-cnt_as[a-1];
        int num_s = as+(b-a+1-as)*2;
        int at = cnt_at[d]-cnt_at[c-1];
        int num_t = at+(d-c+1-at)*2;
        if(num_s%3 == num_t%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}