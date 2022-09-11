#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc055/tasks/agc055_a

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<char> abc = {'A', 'B', 'C'};
    vector<int> ans(3*n);

    int num = 1;

    do{
        int len = n;
        rep(i, 0, 3){
            int cnt = 0;
            rep(j, i*n, (i+1)*n){
                if(ans[j] == 0 and s[j] == abc[i]) cnt++;
            }
            len = min(len, cnt);
        }

        rep(i, 0, 3){
            int len_ = len, j = i*n;
            while(len_ > 0 and j < (i+1)*n){
                if(ans[j] == 0 and s[j] == abc[i]){
                    ans[j] = num;
                    len_--;
                }
                j++;
            }
        }
        num++;
    }while(next_permutation(abc.begin(), abc.end()));

    rep(i, 0, 3*n){
        cout << ans[i];
    }
    cout << endl;
    
    return 0;
}