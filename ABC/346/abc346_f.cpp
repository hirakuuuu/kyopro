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
// https://atcoder.jp/contests/abc346/tasks/abc346_f

int main(){
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    int m = (int)s.size();
    vector<vector<ll>> cnt(26, vector<ll>(m+1));
    // cnt[0][s[0]-'a']++;
    rep(i, 1, m+1){
        rep(j, 0, 26){
            cnt[j][i] = cnt[j][i-1];
            if(j == s[i-1]-'a') cnt[j][i]++;
        }
    }
    rep(i, 0, t.size()){
        if(cnt[t[i]-'a'][m] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ok = 0, ng = (1e18)/t.size()+1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        // g(t, mid) が sの部分列になりうるかを判定
        int pos = 0;
        ll len = 0;
        rep(i, 0, t.size()){
            int tmp = t[i]-'a';
            if(cnt[tmp][m]-cnt[tmp][pos] >= mid){
                auto itr = lower_bound(cnt[tmp].begin(), cnt[tmp].end(), mid+cnt[tmp][pos]);
                int npos = itr-cnt[tmp].begin();
                pos = npos;
                if(pos == m){
                    len++;
                    pos = 0;
                }
            }else{
                ll rest = mid - (cnt[tmp][m]-cnt[tmp][pos]);
                len++;
                pos = 0;
                if(rest%cnt[tmp][m] == 0){
                    len += (rest/cnt[tmp][m])-1;
                    rest = cnt[tmp][m];
                }else{
                    len += (rest)/cnt[tmp][m];
                    rest %= cnt[tmp][m];
                }
                auto itr = lower_bound(cnt[tmp].begin(), cnt[tmp].end(), rest);
                int npos = itr-cnt[tmp].begin();
                pos = npos;
                if(pos == m){
                    len++;
                    pos = 0;
                }
            }
        }
        // cout << mid << ' ' << len << ' ' << pos << endl;
        if(pos > 0){
            len++;
        }

        if(len <= n) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    
    return 0;
}