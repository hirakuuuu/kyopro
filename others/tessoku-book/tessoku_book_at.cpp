#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_at

// 時間計測用
const int TIME_LIMIT = 950;

struct travel_salesman {
    // 都市の数
    int n;
    // 都市の位置
    vector<int> x, y;
    // 現在の訪れる順番
    vector<int> order;
    // 最も小さいスコア
    double best_cost;
    // 最も良い訪れる順番
    vector<int> best_order;

    // コンストラクタ
    travel_salesman(int n_, vector<int> x_, vector<int> y_): n(n_), x(x_), y(y_){
        order.resize(n);
        iota(order.begin(), order.end(), 0);
        best_cost = calc_cost();
        best_order = order;
    }

    // 2点間の距離
    double calc_dist(int i, int j){
        return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }

    // 距離の計算
    double calc_cost(){
        double res = 0;
        rep(i, 0, n+1){
            res += calc_dist(order[i%n], order[(i+1)%n]);
        }
        return res;
    }

    // 1.1カ所変えるべきかどうか
    void swap(int i, int j){
        swap(order[i], order[j]);
        double cur_cost = calc_cost();
        if(best_cost > cur_cost){
            best_cost = cur_cost;
            best_order = order;
        }else{
            swap(order[i], order[j]);
        }
    }

    // 出力
    void print_ans() {
        rep(i, 0, n+1){
            cout << order[i%n]+1 << endl; 
        }
    }
};

int main(){
    // 時間計測用
    auto start_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    int n; cin >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    travel_salesman ts(n, x, y);


    while(true){
        // 時間いっぱい回す
        auto now_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        if(now_time-start_time > TIME_LIMIT) break;
        int l = rand()%n;
        int r = rand()%n;
        ts.swap(l, r);
    }
    ts.print_ans();
    return 0;
}