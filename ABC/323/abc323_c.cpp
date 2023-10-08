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
// https://atcoder.jp/contests/abc323/tasks/abc323_c

int main(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    rep(i, 0, m) cin >> a[i];
    vector<string> s(n);
    vector<int> score(n);
    rep(i, 0, n){
        cin >> s[i];
        score[i] = i+1;
        rep(j, 0, m){
            if(s[i][j] == 'o') score[i] += a[j];
        }
    }
    vector<int> ans(n);
    rep(i, 0, n){
        int max_score = 0;
        rep(j, 0, n){
            if(i == j) continue;
            chmax(max_score, score[j]);
        }

        if(score[i] > max_score) continue;

        priority_queue<int> que;
        rep(j, 0, m){
            if(s[i][j] == 'x') que.push(a[j]);
        }

        int tmp = score[i];
        while(!que.empty()){
            int q = que.top(); que.pop();
            ans[i]++;
            tmp += q;
            if(tmp > max_score) break;
        }
    }

    rep(i, 0, n){
        cout << ans[i] << endl;

    }




    
    return 0;
}