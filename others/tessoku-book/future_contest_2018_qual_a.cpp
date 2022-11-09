#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/future_contest_2018_qual_a

// 時間計測用
const int TIME_LIMIT = 5900;

const int n = 100;

int randint(int l, int r){
    return rand()%(r-l+1)+l;
}

struct SumTable {
    vector<vector<int>> a;
    vector<vector<int>> b;
    vector<int> x;
    vector<int> y;
    vector<int> h;
    int best_score;

    SumTable(vector<vector<int>> a_, vector<vector<int>> b_):a(a_), b(b_){
        get_init();
        best_score = calc_score();
    };

    void get_init(){
        rep(i, 0, 1000){
            x.push_back(rand()%n);
            y.push_back(rand()%n);
            h.push_back(1);
            b[y[i]][x[i]]++;
        }
    }

    int calc_score(){
        int score = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                score += abs(a[i][j]-b[i][j]);
            }
        }
        return 200000000-score;
    }

    void print_queri(){
        printf("%d\n", 1000);
        rep(i, 0, 1000){
            printf("%d %d %d\n", x[i], y[i], h[i]);
        }
    }

    void change_queri(ll rest){
        int t = rand()%1000;
        int old_x = x[t];
        int old_y = y[t];
        int old_h = h[t];
        int new_x = x[t]+randint(-1, 1);
        int new_y = y[t]+randint(-1, 1);
        int new_h = h[t]+randint(-14, 14);
        if(new_x < 0 or n <= new_x) return;
        if(new_y < 0 or n <= new_y) return;
        if(new_h < 1 or n+1 <= new_h) return;
        //printf("%d %d %d\n", new_x, new_y, new_h);

        rep(i, 0, n){
            rep(j, 0, n){
                int cur_num = max(0, old_h-abs(i-old_x)-abs(j-old_y));
                int new_num = max(0, new_h-abs(i-new_x)-abs(j-new_y));
                b[j][i] -= cur_num;
                b[j][i] += new_num;
            }
        }
        int cur_score = calc_score();
        int score_fluc = cur_score-best_score;

        // double T = 100.0-100.00*(double)rest/TIME_LIMIT;
        // double probability = exp(min(0.0, (double)score_fluc/T));
        // double criterion = 1.0*rand()/RAND_MAX;

        if(score_fluc > 0){
            best_score = cur_score;
            x[t] = new_x;
            y[t] = new_y;
            h[t] = new_h;
        }else{
            rep(i, 0, n){
                rep(j, 0, n){
                    int cur_num = max(0, old_h-abs(i-old_x)-abs(j-old_y));
                    int new_num = max(0, new_h-abs(i-new_x)-abs(j-new_y));
                    b[j][i] += cur_num;
                    b[j][i] -= new_num;
                }
            }
        }
    }
  
  	void print_score(){
      printf("score: %d\n", calc_score());
    }
};

int main(){
    // 時間計測用
    auto start_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
        }
    }

    SumTable st(a, b);

    while(true){
        // 時間いっぱい回す
        auto now_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        if(now_time-start_time > TIME_LIMIT) break;
        st.change_queri(now_time-start_time);
    }
  	//st.print_score();
    st.print_queri();

    
    return 0;
}