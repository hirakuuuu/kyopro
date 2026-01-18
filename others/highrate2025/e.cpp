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
    int h, w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h){
        cin >> s[i];
    }
    vector<vector<int>> seen(h, vector<int>(w));

    auto check = [&]() -> bool{
        queue<tuple<int, int, int>> que;
        int num = 0;
        rep(i, 0, h){
            rep(j, 0, w){
                seen[i][j] = 0;
                if(s[i][j] == 'B'){
                    seen[i][j] += 1<<num;
                    que.push({i, j, num++});
                }
            }
        }
        while(!que.empty()){
            auto [qr, qc, qn] = que.front(); que.pop();
            rep(k, 0, 4){
                int nr = qr+(k-1)%2, nc = qc+(k-2)%2;
                if(!inr(0, nr, h) || !inr(0, nc, w)) continue;
                if((seen[nr][nc]>>qn)&1) continue;
                if(s[nr][nc] != '.') continue;
                seen[nr][nc] += 1<<qn;
                que.push({nr, nc, qn});
            }
        }
        bool ok = true;
        rep(i, 0, h){
            rep(j, 0, w){
                if(s[i][j] == 'B'){
                    int tmp = 0;
                    rep(k, 0, 4){
                        int ni = i+(k-1)%2, nj = j+(k-2)%2;
                        if(!inr(0, ni, h) || !inr(0, nj, w)) continue;
                        if(seen[ni][nj] == 7) tmp++;
                    }
                    ok &= tmp>0;
                }
            }
        }
        return ok;
    };

    auto f = [&](auto self, int pr, int pc, int cnt) -> int {
        if(cnt == 3){
            return check();
        }
        if(pr == h) return 0;

        int nr = pr, nc = pc+1;
        if(nc == w){
            nr++;
            nc = 0;
        }

        if(s[pr][pc] == '#'){
            return self(self, nr, nc, cnt);
        }
        int res = 0;
        res += self(self, nr, nc, cnt);
        s[pr][pc] = 'B';
        res += self(self, nr, nc, cnt+1);
        s[pr][pc] = '.';
        return res;
    };
    cout << f(f, 0, 0, 0) << endl;

    return 0;
}