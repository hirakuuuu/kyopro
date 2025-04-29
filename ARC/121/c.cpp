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
constexpr ll INF = 1e18;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n), rev(n);
        rep(i, 0, n){
            cin >> p[i];
            p[i]--;
            rev[p[i]] = i;
        }

        // n が 2 の場合は１回操作するかどうか
        if(n == 2){
            if(p[0] == 1){
                cout << 1 << endl;
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
                cout << endl;
            }
            continue;
        }

        // n = 3 の場合を全探索
        map<vector<int>, vector<int>> memo;
        memo[{0, 1, 2}] = {};
        memo[{1, 0, 2}] = {0};
        memo[{2, 0, 1}] = {0, 1};
        memo[{2, 1, 0}] = {0, 1, 0};
        memo[{1, 2, 0}] = {0, 1, 0, 1};
        memo[{0, 2, 1}] = {0, 1, 0, 1, 0};

        vector<int> ans;
        auto move = [&](int pos) -> void {
            assert(inr(0, pos, n-1));
            assert(ans.size()%2 == pos%2);
            ans.push_back(pos);
            swap(p[pos], p[pos+1]);
            swap(rev[p[pos]], rev[p[pos+1]]);
        };
        rep(i, 0, n-3){
            if(rev[i]%2 == 1-ans.size()%2){
                // 前に持っていく
                while(i < rev[i]){
                    move(rev[i]-1);
                }
            }else{
                // 自分を含めないかつ，まだ触っていない二つを適当に入れ替える
                if(rev[i]+2 < n-1){
                    move(rev[i]+2);
                }else if(rev[i] == n-3){
                    move(n-3);
                    move(n-2);
                    move(n-3);
                }else if(rev[i] == n-2){
                    move(n-4);
                }else if(rev[i] == n-1){
                    move(n-3);
                }
                // 前に持っていく
                while(i < rev[i]){
                    move(rev[i]-1);
                }
            }
        }
        // 残り n-3, n-2, n-1 をそろえる
        vector<int> cur(3);
        rep(i, n-3, n){
            cur[i-(n-3)] = p[i]-(n-3);
        }
        if(n%2 == 1){
            if(ans.size()%2 == 1){
                move(n-2);
                swap(cur[1], cur[2]);
            }
        }else{
            if(ans.size()%2 == 0){
                move(n-2);
                swap(cur[1], cur[2]);
            }
        }
        for(auto act: memo[cur]){
            ans.push_back(act+(n-3));
        }

        cout << ans.size() << endl;
        for(auto act: ans){
            cout << act+1 << ' ';
        }
        cout << endl;
    }
    
    return 0;
}