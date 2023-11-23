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
// https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_c

int main(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    rep(i, 0, n-1){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n, -1);
    c[0] = 0;
    queue<int> que;
    que.push(0);
    vector<int> cnt(2);
    while(!que.empty()){
        int q = que.front(); que.pop();
        cnt[c[q]]++;
        for(auto nq: g[q]){
            if(c[nq] != -1) continue;
            c[nq] = 1-c[q];
            que.push(nq);
        }
    }


    vector<int> p(n), l = {3, 1, 2};
    if(cnt[0] < (n+2)/3){
        rep(i, 0, n){
            int tmp = 0;
            if(c[i]){
                if(l[1] <= n) tmp = 1;
                else if(l[2] <= n) tmp = 2;
            }
            p[i] = l[tmp];
            l[tmp] += 3;
        }
    }else if(cnt[1] < (n+1)/3){
        rep(i, 0, n){
            int tmp = 0;
            if(!c[i]){
                if(l[1] <= n) tmp = 1;
                else if(l[2] <= n) tmp = 2;
            }
            p[i] = l[tmp];
            l[tmp] += 3;
        }
    }else{
        rep(i, 0, n){
            int tmp = 0;
            if(!c[i] && l[1] <= n) tmp = 1;
            if(c[i] && l[2] <= n) tmp = 2;
            p[i] = l[tmp];
            l[tmp] += 3;
        }
    }

    rep(i, 0, n){
        cout << p[i] << ' ';
    }
    cout << endl;


    return 0;
}