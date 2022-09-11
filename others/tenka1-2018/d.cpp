#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tenka1-2018/tasks/tenka1_2018_d

vector<int> f(100005);
void init_f(int n){
    int i = 2;
    while(i*(i-1)/2 <= n){
        f[i*(i-1)/2] = i;
        i++;
    }
}

int main(){
    int n; cin >> n;
    init_f(n);

    if(f[n]){
        cout << "Yes" << endl;
        cout << f[n] << endl;
        vector<vector<int>> ans(f[n]);
        int l = 1;
        rep(i, 0, f[n]){
            rep(j, i+1, f[n]){
                ans[i].push_back(l);
                ans[j].push_back(l);
                l++;
            }
        }

        rep(i, 0, f[n]){
            cout << f[n]-1;
            rep(j, 0, f[n]-1){
                cout << " " << ans[i][j];
            }
            cout << endl;
        }


    }else{
        cout << "No" << endl;
    }


    
    return 0;
}