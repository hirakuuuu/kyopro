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


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];
        vector<int> cnt(n+1);
        rep(i, 0, n) cnt[a[i]]++;
        int cnt_one = 0, ans = 0;
        rep(i, 0, n+1){
            if(cnt[i] == 0){
                ans = i;
                break;
            }else if(cnt[i] == 1){
                if(cnt_one == 1){
                    ans = i;
                    break;
                }
                cnt_one++;
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}