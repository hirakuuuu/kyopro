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
// https://atcoder.jp/contests/arc136/tasks/arc136_d

map<string, ll> memo;
map<string, int> cnt;
map<string, bool> seen;
ll dfs(string s){
    if(memo.find(s) != memo.end()) return memo[s];
    seen[s] = true;
    ll res = cnt[s];
    string t = s;
    rep(i, 0, 6){
        if(t[i] == '0') continue;
        t[i] = (char)t[i]-1;
        if(!seen[t]) res += dfs(t);
        t[i] = (char)t[i]+1;
    }
    return memo[s] = res;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<string> s(n);
    rep(i, 0, n){
        int b = a[i];
        rep(j, 0, 6){
            s[i] += '0'+b%10;
            b /= 10;
        }
        reverse(s[i].begin(), s[i].end());
        cnt[s[i]]++;
    }
    dfs("999999");
    cout << memo["999999"] << endl;
    ll ans = 0;
    rep(i, 0, n){
        string t;
        rep(j, 0, 6) t += '0'+('9'-s[i][j]);
        ans += memo[t];
    }

    cout << ans << endl;


    
    return 0;
}