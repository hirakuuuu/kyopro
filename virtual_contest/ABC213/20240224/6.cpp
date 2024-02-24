#include <bits/stdc++.h>
#include <atcoder/string>
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
    vector<int> sa = atcoder::suffix_array(s);
    vector<int> lcp = atcoder::lcp_array(s, sa);

    vector<ll> ans(n);
    rep(i, 0, n) ans[i] += n-i;
    stack<pair<int, int>> stc;
    ll tot = 0;
    rep(i, 1, n){
        int x = lcp[i-1];
        int cnt = 1;
        while(!stc.empty()){
            if(stc.top().first < x) break;
            auto q = stc.top(); stc.pop();
            tot -= 1LL*q.first*q.second;
            cnt += 1LL*q.second;
        }
        tot += 1LL*cnt*x;
        stc.push({x, cnt});
        ans[sa[i]] += tot;
    }
    tot = 0;
    while(!stc.empty()) stc.pop();
    rrep(i, n-1, 1){
        int x = lcp[i-1];
        int cnt = 1;
        while(!stc.empty()){
            if(stc.top().first < x) break;
            auto q = stc.top(); stc.pop();
            tot -= 1LL*q.first*q.second;
            cnt += 1LL*q.second;
        }
        tot += 1LL*cnt*x;
        stc.push({x, cnt});
        ans[sa[i-1]] += tot;
    }
    rep(i, 0, n){
        cout << ans[i] << endl;
    }

    return 0;
}