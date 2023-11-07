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
// https://atcoder.jp/contests/abc157/tasks/abc157_e

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<set<int>> a(26);
    rep(i, 0, n){
        a[s[i]-'a'].insert(i);
    }

    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int i; cin >> i; i--;
            char c; cin >> c;
            a[s[i]-'a'].erase(i);
            s[i] = c;
            a[s[i]-'a'].insert(i);
        }else if(t == 2){
            int l, r; cin >> l >> r;
            l--, r--;
            int cnt = 0;
            rep(i, 0, 26){
                auto itr_l = a[i].lower_bound(l);
                if(itr_l == a[i].end()) continue;
                if(*itr_l <= r) cnt++;
            }
            cout << cnt << endl;
        }
    }
    
    return 0;
}