#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc002/tasks/arc002_2

bool is_uru(int y){
    return (y%400 == 0 or (y%100 !=0 and y%4 == 0));
}

int main(){
    string s; cin >> s;
    int y = 0, m = 0, d = 0;
    rep(i, 0, 4){
        y *= 10;
        y += s[i]-'0';
    }
    rep(i, 5, 7){
        m *= 10;
        m += s[i]-'0';
    }
    rep(i, 8, 10){
        d *= 10;
        d += s[i]-'0';
    }

    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days_u = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(is_uru(y)){
        rep(k, d, days_u[m]+1){
            if(y%(m*k) == 0){
                printf("%04d/%02d/%02d\n", y, m, k);
                return 0;
            }
        }
        m++;
        rep(j, m, 13){
            rep(k, 1, days_u[j]+1){
                if(y%(j*k) == 0){
                    printf("%04d/%02d/%02d\n", y, j, k);
                    return 0;
                }
            }
        }
    }else{
        rep(k, d, days[m]+1){
            if(y%(m*k) == 0){
                printf("%04d/%02d/%02d\n", y, m, k);
                return 0;
            }
        }
        m++;
        rep(j, m, 13){
            rep(k, 1, days[j]+1){
                if(y%(j*k) == 0){
                    printf("%04d/%02d/%02d\n", y, j, k);
                    return 0;
                }
            }
        }
    }
    y++;
    while(true){
        if(is_uru(y)){
            rep(j, 1, 13){
                rep(k, 1, days_u[j]+1){
                    if(y%(j*k) == 0){
                        printf("%04d/%02d/%02d\n", y, j, k);
                        return 0;
                    }
                }
            }
        }else{
            rep(j, 1, 13){
                rep(k, 1, days[j]+1){
                    if(y%(j*k) == 0){
                        printf("%04d/%02d/%02d\n", y, j, k);
                        return 0;
                    }
                }
            }
        }
        y++;
    }
    
    return 0;
}