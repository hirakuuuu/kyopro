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
初期解を現時点でスコアが最高になる値にするような貪欲法で決定
ランダムに選んだ1～10マスを変更してスコアが上がれば更新する山登り
*/


const int n = 30;
vector<int> b(3);
vector<vector<int>> l(n, vector<int>(n)), r(n, vector<int>(n)), a(n, vector<int>(n));

void init_a(){
    rep(i, 0, n){
        rep(j, 0, n){
            // a[i][j] = rand()%(r[i][j]-l[i][j]+1)+l[i][j];
            int max_score = 0, max_k = l[i][j];
            
            rep(k, l[i][j], r[i][j]+1){
                a[i][j] = k;
                vector<int> cnt(3);
                int sum_a = 0;
                rep(ii, 0, i+1){
                    sum_a = 0;
                    rep(jj, ii, i+1){
                        sum_a += a[jj][j];
                        rep(kk, 0, 3){
                            if(sum_a == b[kk]) cnt[kk]++;
                        }
                    }
                }
                rep(ii, 0, j+1){
                    sum_a = 0;
                    rep(jj, ii, j+1){
                        sum_a += a[i][jj];
                        rep(kk, 0, 3){
                            if(sum_a == b[kk]) cnt[kk]++;
                        }
                    }
                }
                if(max_score < b[0]*cnt[0]+b[1]*cnt[1]+b[2]*cnt[2]){
                    max_score = b[0]*cnt[0]+b[1]*cnt[1]+b[2]*cnt[2];
                    max_k = k;
                }
            }
            a[i][j] = max_k;
        }
    }
}

int get_score(vector<vector<int>> a, int num, vector<int> h, vector<int> w){
    int sum_a = 0;
    vector<int> cnt(3), checked_h(n), checked_w(n);
    rep(i, 0, num){
        if(checked_h[h[i]]) continue;
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[h[i]][k];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
        checked_h[h[i]] = 1;

        if(checked_w[w[i]]) continue;
        rep(j, 0, n){
            sum_a = 0;
            rep(k, j, n){
                sum_a += a[k][w[i]];
                rep(ii, 0, 3){
                    if(sum_a == b[ii]) cnt[ii]++;
                }
            }
        }
        checked_w[w[i]] = 1;
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

    rep(i, 0, 70000){
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