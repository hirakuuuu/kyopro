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
// https://atcoder.jp/contests/arc162/tasks/arc162_c

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> p(n), a(n);
        p[0] = -1;
        rep(i, 1, n){
            cin >> p[i];
            p[i]--;
        }
        rep(i, 0, n) cin >> a[i];

        vector<int> b(n);
        vector<vector<int>> exist(n, vector<int>(k+1));
        rep(i, 0, n){
            for(int j = i; j != -1; j = p[j]){
                if(a[i] == -1) b[j]++;
                else if(a[i] <= k) exist[j][a[i]] = true;
            }
        }

        vector<int> cnt(n);
        rep(i, 0, n){
            rep(j, 0, k){
                if(!exist[i][j]) cnt[i]++;
            }
        }

        bool f = false;
        rep(i, 0, n){
            if(!exist[i][k] && cnt[i] == 0 && b[i] <= 1){
                f = true;
            }else if(!exist[i][k] && cnt[i] == 1 && b[i] == 1){
                f = true;
            }
        }

        if(f) cout << "Alice" << endl;
        else cout << "Bob" << endl;

    }
    
    return 0;
}