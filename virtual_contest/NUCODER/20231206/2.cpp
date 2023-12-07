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
    int n; cin >> n;
    vector<vector<pair<int, int>>> a(n);
    rep(i, 0, n){
        int A; cin >> A;
        rep(j, 0, A){
            int x, y; cin >> x >> y;
            x--;
            a[i].push_back({x, y});
        }
    }

    int ans = 0;
    rep(i, 0, 1<<n){
        vector<vector<int>> cnt(n, vector<int>(2));
        int sum = 0;
        rep(j, 0, n){
            if((i>>j)&1){
                sum++;
                for(auto aa: a[j]){
                    cnt[aa.first][aa.second]++;
                }
            }
        }

        bool f = true;
        rep(j, 0, n){
            if(cnt[j][0] && cnt[j][1]) f = false;
            if(cnt[j][0] && (i>>j)&1) f = false;
            if(cnt[j][1] && !((i>>j)&1)) f = false;
        }
        if(f){
            chmax(ans, sum);
        }
    }
    cout << ans << endl;


    
    return 0;
}