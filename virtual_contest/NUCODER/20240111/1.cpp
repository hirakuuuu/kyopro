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
    int n, q; cin >> n >> q;
    vector<int> l(n, -1), r(n, -1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            x--, y--;
            r[x] = y;
            l[y] = x;
        }else if(t == 2){
            int x, y; cin >> x >> y;
            x--, y--;
            r[x] = -1;
            l[y] = -1;
        }else if(t == 3){
            int x; cin >> x;
            x--;
            while(l[x] != -1) x = l[x];
            vector<int> train;
            while(r[x] != -1){
                train.push_back(x);
                x = r[x];
            }
            train.push_back(x);
            cout << train.size();
            for(auto tt: train) cout << ' ' << tt+1;
            cout << endl;
        }
    }

    
    return 0;
}