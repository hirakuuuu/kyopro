#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc149/tasks/arc149_c

vector<vector<int>> a(1001, vector<int>(1001));

int main(){
    int n; cin >> n;
    vector<bool> used(n*n+1);
    if(n == 3){
        printf("%d %d %d\n", 3, 6, 9);
        printf("%d %d %d\n", 7, 8, 1);
        printf("%d %d %d\n", 2, 4, 5);
    }else if(n == 4){
        printf("%d %d %d %d\n", 15, 11, 16, 12);
        printf("%d %d %d %d\n", 13, 3, 6, 9);
        printf("%d %d %d %d\n", 14, 7, 8, 1);
        printf("%d %d %d %d\n", 4, 2, 10, 5);
    }else{
        if(n == 5){
            a[3][1] = 1; a[4][1] = 14;
            used[1] = true; used[14] = true;
            a[3][2] = 3; a[4][2] = 6;
            used[3] = true; used[6] = true;
            a[3][3] = 5; a[4][3] = 10;
            used[5] = true; used[10] = true;
            a[2][4] = 11; a[3][4] = 4;
            used[11] = true; used[4] = true;
            a[2][5] = 9; a[3][5] = 12;
            used[9] = true; used[12] = true;

            vector<int> pos = {n*(n/2+1)+n/2+1, 0};
            rep(i, 1, n*n+1){
                if(used[i]) continue;
                a[pos[i%2]/n+1][pos[i%2]%n+1] = i;
                pos[i%2]++;
            }
        }else{
            if(n%2){
                int val = 3;
                rep(i, 1, n+1){
                    if(i <= n/2+1){
                        a[n/2+1][i] = val; used[val] = true;
                        a[n/2+2][i] = val+3; used[val+3] = true;
                    }else{
                        a[n/2][i] = val; used[val] = true;
                        a[n/2+1][i] = val+3; used[val+3] = true;
                    }
                    val += 6;
                }

                vector<int> pos = {n*(n/2+1)+n/2+1, 0};
                rep(i, 1, n*n+1){
                    if(used[i]) continue;
                    a[pos[i%2]/n+1][pos[i%2]%n+1] = i;
                    pos[i%2]++;
                }
            }else{
                int val = 3;
                rep(i, 1, n+1){
                    a[n/2][i] = val; used[val] = true;
                    a[n/2+1][i] = val+3; used[val+3] = true;
                    val += 6;
                }
                vector<int> pos = {n*(n/2+1), 0};
                rep(i, 1, n*n+1){
                    if(used[i]) continue;
                    a[pos[i%2]/n+1][pos[i%2]%n+1] = i;
                    pos[i%2]++;
                }
            }
        }

        rep(i, 1, n+1){
            rep(j, 1, n+1){
                if(j >= 2) cout << ' ';
                cout << a[i][j];
            }
            cout << endl;
        }
    }





    
    return 0;
}