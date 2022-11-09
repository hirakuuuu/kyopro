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

struct SumTable {
    vector<vector<int>> cur;
    vector<vector<int>> goal;
    vector<vector<int>> queri;
    int best_score;
    int max_goal;

    SumTable(vector<vector<int>> a,  int max_a):goal(a), max_goal(max_a){
        cur = get_init();
        best_score = calc_score(cur);
    };

    vector<vector<int>> get_init(){
        vector<vector<int>> b_init(n, vector<int>(n));
        rep(k, 0, 1000){
            bool not_over = true;
            vector<int> new_q = {rand()%n, rand()%n, rand()%n+1};
            rep(i, 0, n){
                rep(j, 0, n){
                    int add_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                    not_over &= (b_init[i][j]+add_num <= goal[i][j]);
                }
            }

            if(not_over){
                queri.push_back(new_q);
                rep(i, 0, n){
                    rep(j, 0, n){
                        int add_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                        b_init[i][j] += add_num;
                    }
                }
            }
        }
        return b_init;
    }

    int calc_score(vector<vector<int>> b){
        int score = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                score += abs(goal[i][j]-b[i][j]);
            }
        }
        return 200000000-score;
    }

    void print_queri(){
        printf("%d\n", (int)queri.size());
        for(auto &q: queri){
            printf("%d %d %d\n", q[0], q[1], q[2]);
        }
    }

    void change_queri(){
        int q_num = rand()%queri.size();
        vector<int> cur_q = queri[q_num];
        vector<int> new_q = {rand()%n, rand()%n, rand()%n+1};
        int score_fluc = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                int cur_num = max(0, cur_q[2]-abs(i-cur_q[0])+abs(j-cur_q[1]));
                int new_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                int add_num = new_num-cur_num;
                if(goal[i][j] >= cur[i][j]){
                    if(cur[i][j]+add_num <= goal[i][j]){
                        score_fluc += add_num;
                    }else{
                        score_fluc += 2*goal[i][j]-2*cur[i][j]-add_num;
                    }
                }else{
                    if(cur[i][j]+add_num <= goal[i][j]){
                        score_fluc -= 2*goal[i][j]-2*cur[i][j]-add_num;
                    }else{
                        score_fluc -= add_num;
                    }
                }
            }
        }

        if(score_fluc > 0){
            queri[q_num] = new_q;
            rep(i, 0, n){
                rep(j, 0, n){
                    int cur_num = max(0, cur_q[2]-abs(i-cur_q[0])+abs(j-cur_q[1]));
                    int new_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                    cur[i][j] += new_num-cur_num;
                }
            }
        }
    }

    void add_queri(){
        if(queri.size() == 1000) return;

        vector<int> new_q = {rand()%n, rand()%n, rand()%n+1};
        int score_fluc = 0;
        rep(i, 0, n){
            rep(j, 0, n){
                int add_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                if(goal[i][j] >= cur[i][j]){
                    if(cur[i][j]+add_num <= goal[i][j]){
                        score_fluc += add_num;
                    }else{
                        score_fluc += 2*goal[i][j]-2*cur[i][j]-add_num;
                    }
                }else{
                    score_fluc -= add_num; 
                }
            }
        }

        if(score_fluc > 0){
            queri.push_back(new_q);
            rep(i, 0, n){
                rep(j, 0, n){
                    int add_num = max(0, new_q[2]-abs(i-new_q[0])+abs(j-new_q[1]));
                    cur[i][j] += add_num;
                }
            }
        }
    }
  
  	void print_score(){
      printf("initial score: %d\n", best_score);
      printf("now score: %d\n", calc_score(cur));
    }
};

int main(){
    // 時間計測用
    auto start_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();

    vector<vector<int>> a(n, vector<int>(n));
    int max_a = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> a[i][j];
            max_a = max(max_a, a[i][j]);
        }
    }

    SumTable st(a, max_a);
    int cnt = 0;

    while(true){
        // 時間いっぱい回す
        auto now_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        if(now_time-start_time > TIME_LIMIT) break;
        if(rand()%10 == 0) st.add_queri();
        else st.change_queri();
        cnt++;
    }
  
  	// st.print_score();
    st.print_queri();

    
    return 0;
}