#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc045/tasks/arc045_b

int main(){
    int n, m; cin >> n >> m;
    vector<int> cnt(n+2);
    vector<int> s(m), t(m);
    rep(i, 0, m){
        cin >> s[i] >> t[i];
        cnt[s[i]]++;
        cnt[t[i]+1]--;
    }
    rep(i, 1, n+2) cnt[i] += cnt[i-1];

    vector<int> cnt_1(n+1);
    rep(i, 0, n) cnt_1[i+1] = cnt_1[i]+(cnt[i+1]==1);

    vector<int> ans;
    rep(i, 0, m){
        if(cnt_1[t[i]]-cnt_1[s[i]-1] == 0) ans.push_back(i+1); 
    }

    cout << ans.size() << endl;
    for(auto a: ans) cout << a << '\n';

    return 0;
}