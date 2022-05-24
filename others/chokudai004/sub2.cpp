#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/chokudai004/tasks/chokudai004_a

/*
初期解ランダム、ランダムに選んだ1～10マスを変更してスコアが上がれば更新する山登り
*/

const int n = 30;
vector<int> b(3);
vector<vector<int>> l(n, vector<int>(n)), r(n, vector<int>(n)), a(n, vector<int>(n));

void init_a(){
    rep(i, 0, n){
        rep(j, 0, n){
            a[i][j] = rand()%(r[i][j]-l[i][j]+1)+l[i][j];
        }
    }
}

int get_score(vector<vector<int>> a, int num, vector<int> h, vector<int> w){
    int sum_a = 0;
    vector<int> cnt(3);
    rep(i, 0, num){
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[h[i]][k];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[k][w[i]];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
    }

    return b[0]*cnt[0]+b[1]*cnt[1]+b[2]*cnt[2];
}

int get_total(){
    int sum_a = 0;
    vector<int> cnt(3);
    rep(i, 0, n){
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[i][k];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
    }
    rep(i, 0, n){
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[k][i];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
    }
    return b[0]*cnt[0]+b[1]*cnt[1]+b[2]*cnt[2];
}



int main(){
    int N; cin >> N;
    rep(i, 0, 3) cin >> b[i];
    rep(i, 0, n){
        rep(j, 0, n) cin >> l[i][j];
    }
    rep(i, 0, n){
        rep(j, 0, n) cin >> r[i][j];
    }

    init_a();
    vector<vector<int>> cp_a;

    rep(i, 0, 67500){
        int num = rand()%10+1;
        vector<int> h(num), w(num);
        rep(j, 0, num) h[j] = rand()%n, w[j] = rand()%n;
        cp_a = a;
        rep(j, 0, num) cp_a[h[j]][w[j]] = rand()%(r[h[j]][w[j]]-l[h[j]][w[j]]+1)+l[h[j]][w[j]];
        if(get_score(a, num, h, w) < get_score(cp_a, num, h, w)){
            a = cp_a;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    //cout << get_total() << endl;
    return 0;
}