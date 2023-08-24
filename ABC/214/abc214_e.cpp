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
// https://atcoder.jp/contests/abc214/tasks/abc214_e

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<int, vector<int>> g;
        set<int> s;
        rep(i, 0, n){
            int l, r; cin >> l >> r;
            g[l].push_back(r);
            s.insert(l);
        }
        s.insert(1000000007);

        int i = *s.begin();
        priority_queue<int, vector<int>, greater<int>> que;
        bool f = true;
        while(i <= 1000000000){
            for(auto nq: g[i]){
                que.push(nq);
            }

            int q = que.top(); que.pop();

            if(que.empty()){
                i = *s.lower_bound(i+1);
            }else{
                if(que.top() <= i){
                    f = false;
                    break;
                }else{
                    i++;
                }
            }
        }

        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }    
    
    return 0;
}