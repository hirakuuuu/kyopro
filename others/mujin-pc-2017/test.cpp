#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define inr(l, x, r) (l <= x && x < r)
#define ll long long
#define ld long double

// using mint = modint1000000007;
// using mint = modint998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 9e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int n; cin >> n;
    vector<string> a(n);
    rep(i, 0, n){
        rep(j, 0, n){
            a[i].push_back('.');
        }
    }
    auto make_board = [&](int bit) -> vector<string> {
        vector<string> b(n);
        rep(i, 0, n){
            rep(j, 0, n){
                int len = i*n+j;
                if((bit>>len)&1) b[i].push_back('#');
                else b[i].push_back('.');
            }
        }
        return b;
    };
    rep(bit, 0, 1<<(n*n)){
        a = make_board(bit);
        int row = -1, col = -1;
        rep(i, 0, n){
            rep(j, 0, n){
                if(a[i][j] == '#'){
                    row = i;
                    col = j;
                    break;
                }
            }
            if(row != -1) break;
        }
        if(row == -1) continue;
        int ans = IINF;
        rep(i, 0, n){
            int tmp = 0;
            vector<string> b = a;
            // i 行目を全部黒にできるかどうか
            // → i 列目に黒のマスが存在すれば可能
            int l = -1;
            rep(j, 0, n){
                if(a[j][i] == '#'){
                    l = j;
                    break;
                }
            }
            if(l == -1){
                tmp++;
                l = col;
                // (row, i) を行う
                rep(j, 0, n) b[j][i] = a[row][i];
            }

            // i 行目を全部黒にする
            rep(j, 0, n){
                if(a[i][j] == '#') continue;
                string b_ = b[i];
                rep(k, 0, n) b[k][j] = b_[k];
                tmp++;
            }
            // 白が存在する列の数だけ操作が必要
            rep(j, 0, n){
                rep(k, 0, n){
                    if(b[k][j] == '.'){
                        tmp++;
                        break;
                    }
                }
            }
            chmin(ans, tmp);
        }
        // if(ans == IINF) cout << -1 << endl;
        // else cout << ans << endl;

        // 全探索
        queue<vector<string>> que;
        map<vector<string>, int> cnt;
        cnt[a] = 0;
        que.push(a);
        while(!que.empty()){
            vector<string> q = que.front(); que.pop();
            rep(i, 0, n){
                rep(j, 0, n){
                    vector<string> nq = q;
                    rep(k, 0, n){
                        nq[k][j] = q[i][k];
                    }
                    if(cnt.find(nq) != cnt.end()) continue;
                    cnt[nq] = cnt[q]+1;
                    que.push(nq);
                }
            }
        }
        vector<string> end = make_board((1<<(n*n))-1);
        int correct_ans = IINF;
        if(cnt.find(end) != cnt.end()) correct_ans = cnt[end];
        if(correct_ans != ans){
            cout << correct_ans << ' ' << ans << endl;
            rep(i, 0, n){
                rep(j, 0, n){
                    cout << a[i][j];
                }
                cout << endl;
            }
            // return 0;

        }

        
    }
    return 0;
}