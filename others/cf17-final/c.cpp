#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/cf17-final/tasks/cf17_final_c

int main(){
    int n; cin >> n;
    vector<int> d(n), cnt(13);
    bool f = false;
    rep(i, 0, n){
        cin >> d[i];
        cnt[d[i]]++;
    }

    if(cnt[0]) f = true;
    rep(i, 1, 12){
        if(cnt[i] >= 3) f = true;
    }
    if(cnt[12] >= 2) f = true;

    if(f){
        cout << 0 << endl;
        return 0;
    }

    vector<int> exist(24), rest;
    exist[0] = 1;
    rep(i, 1, 12){
        if(cnt[i] >= 2){
            exist[i] = 1;
            exist[24-i] = 1;
        }else if(cnt[i] == 1){
            rest.push_back(i);
        }
    }
    if(cnt[12]) exist[12] = 1;

    int ans = 0, m = rest.size();
    rep(i, 0, 1<<m){
        vector<int> bit(m), exist_ = exist;
        int dir = i;
        rep(j, 0, m){
            bit[j] = dir%2;
            dir /= 2;
        }

        rep(j, 0, m){
            if(bit[j]) exist_[24-rest[j]]++;
            else exist_[rest[j]]++;
        }

        int s = 24, s_ = 1;

        rep(j, 1, 25){
            if(exist_[j%24] == 0) s_++;
            else{
                s = min(s, s_);
                s_ = 1;
            }
        }

        ans = max(ans, s);


    }
    cout << ans << endl;


    
    return 0;
}