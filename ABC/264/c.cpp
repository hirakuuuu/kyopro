#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/abc264/tasks/abc264_c

int main(){
    int h1, w1; cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i, 0, h1){
        rep(j, 0, w1){
            cin >> a[i][j];
        }
    }
    int h2, w2; cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i, 0, h2){
        rep(j, 0, w2){
            cin >> b[i][j];
        }
    }

    vector<vector<int>> combination(11);

    rep(i, 0, 1<<10){
        int cnt = 0, dir = i;
        rep(j, 0, 10){
            cnt += dir%2;
            dir /= 2;
        }
        combination[cnt].push_back(i);
    }

    int num_h = h1-h2, num_w = w1-w2;
    
    for(auto bit_h: combination[num_h]){
        for(auto bit_w: combination[num_w]){
            vector<vector<int>> a_;
            rep(i, 0, h1){
                if(bit_h&(1<<i)) continue;
                vector<int> aa;
                rep(j, 0, w1){
                    if(bit_w&(1<<j)) continue;
                    aa.push_back(a[i][j]);
                }
                a_.push_back(aa);
            }
            // rep(i, 0, h2){
            //     rep(j, 0, w2){
            //         cout << a_[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            if(a_ == b){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout << "No" << endl;


    return 0;
}