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
// 

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<int, int>> lr(n);
        map<int, vector<int>> r;
        rep(i, 0, n){
            cin >> lr[i].first >> lr[i].second;
            r[lr[i].first].push_back(lr[i].second);
        }
        sort(lr.begin(), lr.end());
        priority_queue<int, vector<int>, greater<int>> que;
        que.push(lr[0].second);
        int p = lr[0].first;
        bool ok = true;
        rep(i, 1, n){
            if(lr[i].first != lr[i-1].first){
                while(!que.empty() && p < lr[i].first){
                    int q = que.top(); que.pop();
                    if(q < p){
                        ok = false;
                    }
                    p++;
                }
                if(que.empty()) p = lr[i].first;
            }
            que.push(lr[i].second);
        }
        while(!que.empty()){
            int q = que.top(); que.pop();
            if(q < p){
                ok = false;
            }
            p++;
        }
        if(ok) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    
    return 0;
}