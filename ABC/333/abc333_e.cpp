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
// https://atcoder.jp/contests/abc333/tasks/abc333_e

int main(){
    int n; cin >> n;
    vector<int> t(n), x(n);
    rep(i, 0, n) cin >> t[i] >> x[i];
    vector<int> cnt(n+1);
    rep(i, 0, n){
        if(t[i] == 1){
            cnt[x[i]]++;
        }else if(t[i] == 2){
            if(cnt[x[i]] > 0){
                cnt[x[i]]--;
            }else{
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vector<int> ans;
    fill(cnt.begin(), cnt.end(), 0);
    int mx = 0, k = 0;
    rrep(i, n-1, 0){
        if(t[i] == 1){
            if(cnt[x[i]] > 0){
                cnt[x[i]]--;
                ans.push_back(1);
                k--;
            }else{
                ans.push_back(0);
            }
        }else if(t[i] == 2){
            cnt[x[i]]++;
            k++;
        }
        chmax(mx, k);
    }

    cout << mx << endl;
    reverse(ans.begin(), ans.end());
    for(auto aa: ans){
        cout << aa << ' ';
    }
    cout << endl;
    
    return 0;
}