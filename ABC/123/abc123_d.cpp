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
// https://atcoder.jp/contests/abc123/tasks/abc123_d

int main(){
    ll x, y, z, k; cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, 0, x) cin >> a[i];
    rep(i, 0, y) cin >> b[i];
    rep(i, 0, z) cin >> c[i];

    priority_queue<ll> que;
    rep(i, 0, x){
        rep(j, 0, y){
            que.push(-(a[i]+b[j]));
            if(que.size() > k) que.pop();
        }
    }

    vector<ll> d;
    while(!que.empty()){
        d.push_back(-que.top());
        que.pop();
    }

    priority_queue<ll> ans;
    rep(i, 0, z){
        for(auto dd: d){
            ans.push(-(dd+c[i]));
            if(ans.size() > k) ans.pop();
        }
    }

    vector<ll> re_ans;
    while(!ans.empty()){
        re_ans.push_back(-ans.top());
        ans.pop();
    }
    reverse(re_ans.begin(), re_ans.end());

    for(auto r: re_ans) cout << r << endl;



    return 0;
}