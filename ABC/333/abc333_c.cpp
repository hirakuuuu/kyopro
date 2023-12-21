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
// https://atcoder.jp/contests/abc333/tasks/abc333_c

int main(){
    int k; cin >> k;
    vector<ll> lep = {1};
    rep(i, 1, 16){
        lep.push_back(lep[i-1]*10+1);
    }
    vector<ll> lep_sum;
    rep(i, 0, 16){
        rep(j, 0, 16){
            rep(l, 0, 16){
                lep_sum.push_back(lep[i]+lep[j]+lep[l]);
            }
        }
    }

    sort(lep_sum.begin(), lep_sum.end());
    lep_sum.erase(unique(lep_sum.begin(), lep_sum.end()), lep_sum.end());
    cout << lep_sum[k-1] << endl;
    
    return 0;
}