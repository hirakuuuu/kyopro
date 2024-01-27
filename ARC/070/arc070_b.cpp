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
// https://atcoder.jp/contests/abc056/tasks/arc070_b

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n+1);
    rep(i, 1, n+1) cin >> a[i];
    sort(a.begin(), a.end());
    
    vector<vector<bool>> ldp(n+2, vector<bool>(k+1));
    vector<vector<bool>> rdp(n+2, vector<bool>(k+1));
    ldp[0][0] = true;
    rep(i, 1, n+1){
        if(a[i] >= k){
            ldp[i] = ldp[i-1];
        }else{
            rep(j, 0, k+1){
                ldp[i][j] = ldp[i-1][j];
                if(j >= a[i]) ldp[i][j] = ldp[i][j]||ldp[i-1][j-a[i]];
            }
        }
    }
    rdp[n+1][0] = true;
    rrep(i, n, 1){
        if(a[i] >= k){
            rdp[i] = rdp[i+1];
        }else{
            rep(j, 0, k+1){
                rdp[i][j] = rdp[i+1][j];
                if(j >= a[i]) rdp[i][j] = rdp[i][j]||rdp[i+1][j-a[i]];
            }
        }
    }

    int ans = 0;
    rep(i, 1, n+1){
        if(a[i] >= k) continue;
        // ldp[i-1]とrdp[i+1] から k-a[i] <= s < k が作れるか
        int cnt = 0;
        bool need = false;
        rep(j, k-a[i], k) cnt += rdp[i+1][j];
        rep(j, 0, k){
            if(ldp[i-1][j]){
                if(cnt) need = true;
            }
            if(k-j-1 >= 0) cnt -= rdp[i+1][k-j-1];
            if(k-a[i]-j-1 >= 0) cnt += rdp[i+1][k-a[i]-j-1];
        }
        if(!need) ans++;
    }
    cout << ans << endl;


    return 0;
}