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
const int TIME_LIMIT = 980;

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
        order = greedy_best();
        // best_cost = calc_cost();
        // best_order = order;
    }

   // 貪欲法で初期解を求める
    vector<int> greedy_best(){
        vector<int> root(n+1), seen(n);
        seen[0] = 1;
        rep(i, 1, n){
            double dist = pow(10, 9);
            int best_j = 0;
            rep(j, 0, n){
                if(seen[j]) continue;
                if(dist > calc_dist(root[i-1], j)){
                    dist = calc_dist(root[i-1], j);
                    best_j = j;
                }
            }
            root[i] = best_j;
            seen[best_j] = 1;
        }
        return root;
    }

    // 2点間の距離
    double calc_dist(int i, int j){
        i %= n, j %= n;
        return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }

    // 距離の計算
    double calc_cost(){
        double res = 0;
        rep(i, 0, n){
            res += calc_dist(order[i], order[i+1]);
        }
        return res;
    }

    // 1.1カ所変えるべきかどうか
    void queri1(int l, int r){
        if(l == r) return;
        if(l > r) swap(l, r);
        // 今
        double dist1 = calc_dist(order[l-1], order[l])+calc_dist(order[l], order[l+1])+calc_dist(order[r-1], order[r])+calc_dist(order[r], order[r+1]);
        if(r-l == 1) dist1 -= calc_dist(order[l], order[r])*2;
        // 変えた場合
        double dist2 = calc_dist(order[l-1], order[r])+calc_dist(order[r], order[l+1])+calc_dist(order[r-1], order[l])+calc_dist(order[l], order[r+1]);
        
        if(dist1 > dist2){
            swap(order[l], order[r]);
        }
    }

    // 2-opt法
    void two_opt(){
        // 入れ替える区間の長さを取得
        int l = rand()%(n-2)+1, r = rand()%(n-l-1)+1+l;
        double dist1 = calc_dist(order[l-1], order[l])+calc_dist(order[r], order[r+1]);
        double dist2 = calc_dist(order[l-1], order[r])+calc_dist(order[l], order[r+1]);
        if(dist1 > dist2){
            reverse(order.begin()+l, order.begin()+r+1);
        }
    }

    // 焼き鈍し導入
    void two_opt_2(ll rest){
        // 入れ替える区間の長さを取得
        int l = rand()%(n-2)+1, r = rand()%(n-l-1)+1+l;
        double dist1 = calc_dist(order[l-1], order[l])+calc_dist(order[r], order[r+1]);
        double dist2 = calc_dist(order[l-1], order[r])+calc_dist(order[l], order[r+1]);

        double T = 30.00-30.00*(double)rest/TIME_LIMIT;
        double probability = exp(min(0.0, (dist1-dist2)/T));
        double criterion = 1.0*rand()/RAND_MAX;
        if(criterion < probability) reverse(order.begin()+l, order.begin()+r+1);
    }

    // 出力
    void print_ans() {
        rep(i, 0, n+1){
            cout << order[i]+1 << endl; 
        }
    }

    void print_score() {
        cout << 1000000/calc_cost() << endl;
    }

    bool check_ans(){
        vector<int> cnt(n+1);
        rep(i, 0, n){
            cnt[order[i]]++;
            if(cnt[order[i]] >= 2) return false;
        }
        return true;
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
        ts.two_opt_2(now_time-start_time);
    }
    ts.print_ans();
    
    return 0;
}