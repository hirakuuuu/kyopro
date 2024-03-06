#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
// constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
constexpr int IINF = 1001001001;
constexpr ll INF = 1LL<<60;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// 

int main(){
    vector<vector<int>> a(4, vector<int>(4));
    int v = 0;
    rep(i, 0, 4){
        rep(j, 0, 4){
            cin >> a[i][j];
            if(a[i][j]) v += (1<<(i*4+j));
        }
    }
    int ans = 0;
    rep(i, 1, 1<<16){
        if((v&i) != v) continue;
        int cnt = 0, pos = -1;
        rep(j, 0, 16){
            if((i>>j)&1){
                if(pos == -1) pos = j;
                cnt++;
            }
        }

        queue<int> que;
        que.push(pos);
        vector<bool> seen(16);
        seen[pos] = true;
        while(!que.empty()){
            int q = que.front(); que.pop();
            rep(j, 0, 4){
                int ni = (q/4)+(j-1)%2, nj = (q%4)+(j-2)%2;
                if(ni < 0 || 4 <= ni || nj < 0 || 4 <= nj) continue;
                int nxt = ni*4+nj;
                if(seen[nxt]) continue;
                if((i>>nxt)&1){
                    seen[nxt] = true;
                    que.push(nxt);
                }
            }
        }
        int cnt_seen = 0;
        rep(j, 0, 16) cnt_seen += seen[j];
        if(cnt != cnt_seen) continue;

        int cnt_out = 0;
        rep(j, 1, 3){
            rep(k, 1, 3){
                bool ok = ((i>>(j*4+k))&1);
                pos = j*4+k;
                que.push(pos);
                seen.assign(16, false);
                seen[pos] = true;
                while(!que.empty()){
                    int q = que.front(); que.pop();
                    rep(l, 0, 4){
                        int ni = (q/4)+(l-1)%2, nj = (q%4)+(l-2)%2;
                        if(ni < 0 || 4 <= ni || nj < 0 || 4 <= nj) continue;
                        int nxt = ni*4+nj;
                        if(seen[nxt]) continue;
                        if(!((i>>nxt)&1)){
                            if(ni == 0 || ni == 3 || nj == 0 || nj == 3) ok = true;
                            seen[nxt] = true;
                            que.push(nxt);
                        }
                    }
                }
                if(ok) cnt_out++;
            }
        }
        if(cnt_out != 4) continue;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}