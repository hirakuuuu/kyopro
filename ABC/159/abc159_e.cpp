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
// https://atcoder.jp/contests/abc159/tasks/abc159_e

int main(){
    int h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i, 0, h){
        cin >> s[i];
    }

    int ans = (h-1)*(w-1);
    rep(i, 0, (1<<(h-1))){
        vector<int> index(h);
        rep(j, 1, h){
            if((i&(1<<(j-1)))) index[j] = index[j-1]+1;
            else index[j] = index[j-1];
        }
        int res = index[h-1];

        vector<int> cnt(index[h-1]+1);
        rep(j, 0, w){
            vector<int> cnt_ = cnt;
            rep(l, 0, h){
                if(s[l][j] == '1') cnt[index[l]]++;
            }
            bool f = false;
            rep(l, 0, index[h-1]+1){
                if(cnt[l] > k) f = true;
            }
            if(f){
                res++;
                rep(l, 0, index[h-1]+1){
                    cnt[l] -= cnt_[l];
                    if(cnt[l] > k) res = IINF;
                }
            }
        }
        chmin(ans, res);
    }

    cout << ans << endl;
    
    return 0;
}