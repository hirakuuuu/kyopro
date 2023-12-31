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

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int main(){
    vector<int> dist(1<<16, IINF);
    string start = "1101001111001011";
    // string start = "1101001111001011";
    // string start = "000000000000000000";
    int start_int = 0;
    rep(i, 0, 16){
        start_int += (1<<i)*(start[i]-'0');
    }
    dist[start_int] = 0;
    queue<int> que;
    que.push(start_int);
    while(!que.empty()){
        int q = que.front(); que.pop();
        int tmp = q;
        rep(i, 0, 16){
            int cop = tmp;
            cop ^= (1<<i);
            rep(j, 0, 4){
                int cx = i/4, cy = i%4;
                int nx = cx+dx[j], ny = cy+dy[j];
                if(nx < 0 || 4 <= nx || ny < 0 || 4 <= ny) continue;
                cop ^= (1<<(nx*4+ny));
            }
            if(dist[cop] != IINF) continue;
            que.push(cop);
            dist[cop] = dist[q]+1;
        }
    }

    int ans = dist[(1<<16)-1];
    cout << ans << endl;


    
    return 0;
}