#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/discovery2016-qual/tasks/discovery_2016_qual_b

vector<vector<vector<int>>> cnt(2, vector<vector<int>>(100005));

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    cnt[0][a[0]].push_back(0);
    cnt[1][a[0]].push_back(n);
    rep(i, 1, n){
        cnt[0][a[i]].push_back(i);
        cnt[1][a[i]].push_back(i);
    }

    int ans = 1001001001;
    
    rep(j, 0, 2){
        int tmp = 1;
        int pos = -1;
        rep(i, 1, 100005){
            if((int)cnt[j][i].size() == 0) continue;
            if(pos == -1){
                pos = *cnt[j][i].rbegin();
            }else{
                auto itr = lower_bound(cnt[j][i].begin(), cnt[j][i].end(), pos);
                if(itr == cnt[j][i].begin()){
                    pos = *cnt[j][i].rbegin();
                }else{
                    tmp++;
                    --itr;
                    pos = *itr;
                }
            }
        }
        chmin(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}