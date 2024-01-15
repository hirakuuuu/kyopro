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
    int H, W, n, h, w; cin >> H >> W >> n >> h >> w;
    vector<vector<int>> a(H, vector<int>(W));
    set<int> all_s;
    vector<int> all_cnt(n);
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> a[i][j];
            a[i][j]--;
            all_s.insert(a[i][j]);
            all_cnt[a[i][j]]++;
        }
    }

    rep(i, 0, H-h+1){
        set<int> s = all_s;
        vector<int> cnt = all_cnt;
        rep(j, i, i+h){
            rep(k, 0, w){
                cnt[a[j][k]]--;
                if(cnt[a[j][k]] == 0) s.erase(a[j][k]);
            }
        }

        cout << s.size();
        rep(j, w, W){
            rep(k, i, i+h){
                cnt[a[k][j-w]]++;
                s.insert(a[k][j-w]);
            }
            rep(k, i, i+h){
                cnt[a[k][j]]--;
                if(cnt[a[k][j]] == 0) s.erase(a[k][j]);
            }
            cout << ' ' << s.size();
        }
        cout << endl;
    }
    
    return 0;
}