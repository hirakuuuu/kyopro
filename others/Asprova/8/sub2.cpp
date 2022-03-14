#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
いったんどれから始めるのが良いのかっていうのを知りたい
次に掛ける製品の選び方を変えなければならない
*/


// フッククラス
struct hook {
    int s = -1, c = -1;
    bool used = false;
    
};


int main(){
    // 入力
    int s, c, H, a, b; cin >> s >> c >> H >> a >> b;
    // 各製品の生産台数
    vector<vector<int>> N(s, vector<int>(c));
    // Nの合計
    int sumN = 0;
    rep(i, 0, s){
        rep(j, 0, c){
            cin >> N[i][j];
            sumN = N[i][j];
        }
    }

    // 各製品ごとのフックにかけれるハンガーの限界
    vector<int> k(s);
    rep(i, 0, s) cin >> k[i];

    // 各製品、色ごとに空ける必要のある時間
    vector<vector<int>> A(s, vector<int>(s)), B(c, vector<int>(c));
    rep(i, 0, s){
        rep(j, 0, s){
            cin >> A[i][j];
        }
    }
    rep(i, 0, c){
        rep(j, 0, c){
            cin >> B[i][j];
        }
    }


    // 答えの配列
    vector<pii> ans;
    // 暫定的な最高スコア
    int M = 0;
    // どの製品から始めるかを全て試す
    rep(i, 0, s){
        rep(j, 0, c){
            // 配列の長さ
            int l = 0;
            // ハンガーの取り付け回数と取り外し回数の和
            int x = 0;
            // 次に取り付けるべき製品、色、次に来るフック
            int ns = i, nc = j, nh = 0, time = 0, nns = i, nnc = j;
            // 間隔を空けなければならない時の時間
            int breakf = 0;
            // 待っている時間
            int waitf = 0;
            // フックの配列
            vector<hook> line(H);
            // 処理を記録する配列
            vector<pii> process;
            // ハンガーの限界個数
            vector<int> cpk = k;
            // 生産台数
            vector<vector<int>> cpN = N;
            // l <= 10^6という制限があったので
            while(l <= 1000000){
                // 待たなければならない場合
                if(breakf){
                    // 今始点にいるフックが使われていた場合
                    if(line[nh].used){
                        // 使えるハンガーを1増やす
                        cpk[line[nh].s]++;
                        // 使われていない状態にする
                        line[nh].used = false;
                        // 次にどの製品をつるすべきか
                        time = nns = nnc = H+1;
                        rep(ss, 0, s){
                            if(cpk[ss] == 0) continue;
                            rep(cc, 0, c){
                                if(cpN[ss][cc] == 0) continue;
                                if(time > max(A[ns][ss], B[nc][cc])){
                                    time = max(A[ns][ss], B[nc][cc]);
                                    nns = ss, nnc = cc;
                                }
                            }
                        }
                        breakf = max(0, time-waitf);
                        // つるせるようになったか
                        if(breakf == 0){
                            // ns, ncを更新
                            ns = nns, nc = nnc;
                            continue;
                        }
                        // -1の処理を記録
                        process.push_back({-1, -1});
                        l++;
                        x++;
                    // フックが使われていなかった場合
                    }else{
                        // 次にどの製品をつるすべきか
                        time = nns = nnc = H+1;
                        rep(ss, 0, s){
                            if(cpk[ss] == 0) continue;
                            rep(cc, 0, c){
                                if(cpN[ss][cc] == 0) continue;
                                if(time > max(A[ns][ss], B[nc][cc])){
                                    time = max(A[ns][ss], B[nc][cc]);
                                    nns = ss, nnc = cc;
                                }
                            }
                        }
                        // つるすために待たなければならない時間
                        breakf = max(0, time-waitf);
                        // つるせるようになったか
                        if(breakf == 0){
                            // ns, ncを更新
                            ns = nns, nc = nnc;
                            continue;
                        }
                        // -2の処理を記録
                        process.push_back({-2, -2});
                        l++;
                    }
                    // 待っている時間を進める
                    waitf++;
                // 待ち時間で無い場合
                }else{
                    // フックが使われていたら外して、使えるハンガーを1増やす
                    if(line[nh].used) cpk[line[nh].s]++;
                    // 使われていなかったら、今から使うので
                    else line[nh].used = true;
                    // つるす処理を記録
                    process.push_back({ns, nc});
                    l++;
                    x++;
                    // つるす製品の台数を１減らす
                    cpN[ns][nc]--;
                    // つるせるハンガーの数を１減らす
                    cpk[ns]--;
                    // フックにかかっている製品を更新
                    line[nh].s = ns;
                    line[nh].c = nc;
                    // つるすべき製品がなかったら処理は終了
                    bool f = true;
                    rep(ss, 0, s){
                        rep(cc, 0, c){
                            if(cpN[ss][cc]) f = false;
                        }
                    }
                    if(f) break;

                    // 次にどの製品をつるすべきか
                    time = nns = nnc = H+1;
                    rep(ss, 0, s){
                        if(cpk[ss] == 0) continue;
                        rep(cc, 0, c){
                            if(cpN[ss][cc] == 0) continue;
                            if(time > max(A[ns][ss], B[nc][cc])){
                                time = max(A[ns][ss], B[nc][cc]);
                                nns = ss, nnc = cc;
                            }
                        }
                    }
                    // 開けるべき間隔を更新
                    breakf = time;
                    if(breakf == 0){
                        ns = nns, nc = nnc;
                    }
                    // 待ち時間
                    waitf = 0;
                }
                // フックを進める
                nh = (nh+1)%H;
            }
            // より得点の高い処理に置き換える
            if(M < 10000000 - a*x - b*(l-sumN)){
                M = 10000000 - a*x - b*(l-sumN);
                ans = process;
            }
        }
    }

    // 処理の長さを出力
    cout << ans.size() << endl;
    // 処理の出力
    for(auto aa: ans){
        if(aa.first == -1){
            cout << -1 << endl;
        }else if(aa.first == -2){
            cout << -2 << endl;
        }else printf("%d %d\n", aa.first+1, aa.second+1);
    }
}