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
初期解ランダム、ランダムに選んだ1マスを変更してスコアが上がれば更新する山登り
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

int get_score(vector<vector<int>> a, int h, int w){
    int sum_a = 0;
    vector<int> cnt(3);

    rep(i, 0, n){
        sum_a = 0;
        rep(j, i, n){
            sum_a += a[h][j];
            rep(ii, 0, 3){
                if(sum_a == b[ii]) cnt[ii]++;
            }
        }
    }
    rep(i, 0, n){
        sum_a = 0;
        rep(j, i, n){
            sum_a += a[j][w];
            rep(ii, 0, 3){
                if(sum_a == b[ii]) cnt[ii]++;
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

    rep(i, 0, 25000){
        int h = rand()%n, w = rand()%n;
        while(l[h][w] == r[h][w]) h = rand()%n, w = rand()%n;
        cp_a = a;
        while(cp_a[h][w] == a[h][w]) cp_a[h][w] = rand()%(r[h][w]-l[h][w]+1)+l[h][w];
        if(get_score(a, h, w) < get_score(cp_a, h, w)){
            a = cp_a;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    
    return 0;
}