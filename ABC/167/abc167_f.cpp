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
// https://atcoder.jp/contests/abc167/tasks/abc167_f

int main(){
    int n; cin >> n;
    vector<string> s(n);
    vector<int> min_s(n), sum_s(n);
    priority_queue<pair<int, int>> que, que2;
    rep(i, 0, n){
        cin >> s[i];
        rep(j, 0, s[i].size()){
            if(s[i][j] == '(') sum_s[i]++;
            else sum_s[i]--;
            chmin(min_s[i], sum_s[i]);
        }

        if(sum_s[i] >= 0) que.push({min_s[i], sum_s[i]});
        else que2.push({sum_s[i]-min_s[i], sum_s[i]});
    }

    int total = 0;
    while(!que.empty()){
        pair<int, int> q = que.top(); que.pop();
        if(total+q.first < 0){
            cout << "No" << endl;
            return 0;
        }
        total += q.second;
    }
    while(!que2.empty()){
        pair<int, int> q = que2.top(); que2.pop();
        if(total-q.first+q.second < 0){
            cout << "No" << endl;
            return 0;
        }
        total += q.second;
    }

    if(total == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}