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
    string s, t; cin >> s >> t;

    rep(_, 0, 2) s += '#';
    rep(_, 0, 2) t += '#';

    map<string, int> memo;
    queue<string> que;
    memo[s] = 0;
    que.push(s);
    while(!que.empty()){
        string tmp = que.front(); que.pop();
        int d = memo[tmp];
        int l = -1;
        rep(i, 0, n+1){
            if(tmp[i] == '#'){
                l = i;
                break;
            }
        }

        rep(i, 0, n+1){
            if(tmp[i] == '#' || tmp[i+1] == '#') continue;
            swap(tmp[i], tmp[l]), swap(tmp[i+1], tmp[l+1]);
            if(memo.find(tmp) == memo.end()){
                memo[tmp] = d+1;
                que.push(tmp);
            }
            swap(tmp[i], tmp[l]), swap(tmp[i+1], tmp[l+1]);
        }
    }
    
    if(memo.find(t) == memo.end()) cout << -1 << endl;
    else cout << memo[t] << endl;
    return 0;
}