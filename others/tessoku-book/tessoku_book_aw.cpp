#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_aw

// 盤面の状態を表す構造体
struct State {
    int score;
    int x[29];
    char lastMove;
    int lastPos;
};

// sort関数の順序を決める（スコアが大きい方が「大きい」とする）
bool operator>(const State& a1, const State& a2){
    return (a1.score > a2.score);
}

// 必要な変数・配列
struct BeamSearch {
    const int WIDTH = 12000;
    const int N = 20;
    int t; 
    vector<int> p, q, r;
    vector<int> numState;
    vector<vector<State>> Beam;
    string answer;

    BeamSearch(int t_, vector<int> p_, vector<int> q_, vector<int> r_): t(t_), p(p_), q(q_), r(r_){
        numState.resize(t+1);
        Beam.resize(t+1);
        rep(i, 0, t+1){
            Beam[i].resize(WIDTH);
        }
    };

    void solve(){
        // ０手目の状態を設定
        numState[0] = 1;
        Beam[0][0].score = 0;
        rep(i, 1, N+1) Beam[0][0].x[i] = 0;

        // ビームサーチ
        rep(i, 1, t+1){
            vector<State> candidate;
            rep(j, 0, numState[i-1]){
                // 操作A
                State sousaA = Beam[i-1][j];
                sousaA.lastMove = 'A';
                sousaA.lastPos = j;
                sousaA.x[p[i]]++;
                sousaA.x[q[i]]++;
                sousaA.x[r[i]]++;
                rep(k, 1, N+1){
                    if(sousaA.x[k] == 0) sousaA.score++;
                }

                // 操作B
                State sousaB = Beam[i-1][j];
                sousaB.lastMove = 'B';
                sousaB.lastPos = j;
                sousaB.x[p[i]]--;
                sousaB.x[q[i]]--;
                sousaB.x[r[i]]--;
                rep(k, 1, N+1){
                    if(sousaB.x[k] == 0) sousaB.score++;
                }

                candidate.push_back(sousaA);
                candidate.push_back(sousaB);
            }
            
            // ソートしてBeam[i]の結果を計算する
            sort(candidate.begin(), candidate.end(), greater<State>());
            numState[i] = min(WIDTH, (int)candidate.size());
            rep(j, 0, numState[i]) Beam[i][j] = candidate[j];
        }
    }

    void make_ans(){
        int cur = 0;
        for(int i = t; i > 0; i--){
            answer += Beam[i][cur].lastMove;
            cur = Beam[i][cur].lastPos;
        }
        reverse(answer.begin(), answer.end());
    }

    void print_ans(){
        for(auto a: answer){
            cout << a << endl;
        }
    }
};

int main(){
    int t; cin >> t;
    vector<int> p(t+1), q(t+1), r(t+1);
    rep(i, 1, t+1){
        cin >> p[i] >> q[i] >> r[i];
    }

    BeamSearch bs(t, p, q, r);
    bs.solve();
    bs.make_ans();
    bs.print_ans();
    
    return 0;
}