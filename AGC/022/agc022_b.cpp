#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/agc022/tasks/agc022_b

int main(){
    int n; cin >> n;
    if(n == 3) printf("%d %d %d\n", 2, 5, 63);
    else if(n == 4) printf("%d %d %d %d\n", 2, 5, 20, 63);
    else if(n == 5) printf("%d %d %d %d %d\n", 2, 5, 20, 30, 63);
    else{
        vector<bool> used(30001);
        int cnt = 0, total = 0, last;
        rep(i, 1, 30001){
            if(i%6 == 0 or i%6 == 2 or i%6 == 3 or i%6 == 4){
                used[i] =true;
                cnt++;
                total += i;
                total %= 6;
            }
            if(cnt == n){
                last = i;
                break;
            }
        }

        int add_mod = 0;
        if(total == 2) used[8] = false;
        else if(total == 3) used[9] = false;
        else if(total == 5){
            used[9] = false;
            add_mod = 4;
        }

        if(total != 0){
            rep(i, last, 30001){
                if(!used[i] and i%6 == add_mod){
                    used[i] = true;
                    break;
                }
            }
        }

        rep(i, 1, 30001){
            if(used[i]) cout << i << " ";
        }
        cout << endl;
    }

    
    return 0;
}