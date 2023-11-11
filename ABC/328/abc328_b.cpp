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
// https://atcoder.jp/contests/abc328/tasks/abc328_b

int main(){

    int n; cin >> n;
    int ans = 0;
    rep(i, 1, n+1){
        int d; cin >> d;
        rep(j, 1, d+1){
            set<int> s;
            int i_ = i;
            while(i_){
                s.insert(i_%10);
                i_ /= 10;
            }
            int j_ = j;
            while(j_){
                s.insert(j_%10);
                j_ /= 10;
            }

            if(s.size() == 1) ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}