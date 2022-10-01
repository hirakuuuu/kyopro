#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cm

int n, k, a[30];


int main(){
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];

    set<int> set_l_sum;
    int cnt_l = 0;
    rep(i, 0, 1<<15){
        cnt_l = 0;
        rep(j, 0, 15){
            if((i&(1<<j))) cnt_l += a[15+j];
        }
        set_l_sum.insert(cnt_l);
    }

    int cnt_f = 0;
    rep(i, 0, 1<<15){
        cnt_f = 0;
        rep(j, 0, 15){
            if((i&(1<<j))) cnt_f += a[j];
        }

        if(k-cnt_f == *set_l_sum.lower_bound(k-cnt_f)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}