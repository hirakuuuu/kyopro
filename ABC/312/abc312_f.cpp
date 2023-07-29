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
// https://atcoder.jp/contests/abc312/tasks/abc312_e

int main(){
    int n, m; cin >> n >> m;
    vector<vector<ll>> task(3);
    rep(i, 0, n){
        ll t, x; cin >> t >> x;
        task[t].push_back(x);
    }
    rep(i, 0, 3) sort(task[i].begin(), task[i].end());
    rep(i, 0, 3) reverse(task[i].begin(), task[i].end());

    vector<ll> ans0(task[0].size()+1);
    rep(i, 1, task[0].size()+1){
        ans0[i] = ans0[i-1]+task[0][i-1];
    }

    vector<ll> ans1(task[1].size()+task[2].size()+1);
    ll rest = 0, total = 0, pos1 = 0, pos2 = 0;
    rep(i, 1, task[1].size()+task[2].size()+1){
        if(rest > 0 && pos1 < task[1].size()){
            total += task[1][pos1];
            pos1++;
            rest--;
        }else if(pos2 < task[2].size()){
            rest += task[2][pos2];
            pos2++;
        }
        ans1[i] = total;
    }

    ll true_ans = 0;
    rep(i, 0, m+1){
        if(ans0.size() > i && ans1.size() > m-i){
            chmax(true_ans, ans0[i]+ans1[m-i]);
        }
    }

    cout << true_ans << endl;



    
    return 0;
}