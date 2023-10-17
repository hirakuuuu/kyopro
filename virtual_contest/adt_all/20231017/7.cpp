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

vector<vector<int>> h;
vector<int> cur;
void dfs(int sum, int d){
    if(d == 0){
        h.push_back(cur);
        return;
    }
    rep(i, 1, sum-d+2){
        cur.push_back(i);
        dfs(sum-i, d-1);
        cur.pop_back();
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<string> s(n), t(m);
    int s_size = 0;
    rep(i, 0, n){
        cin >> s[i];
        s_size += s[i].size();
    }
    map<string, bool> exist;
    rep(i, 0, m){
        cin >> t[i];
        exist[t[i]] = true;
    }
    dfs(16-s_size, n-1);
    vector<int> ind(n);
    vector<string> ans;
    iota(ind.begin(), ind.end(), 0);
    do{
        for(auto hh: h){
            string tmp = s[ind[0]];
            rep(i, 1, n){
                rep(_, 0, hh[i-1]) tmp += '_';
                tmp += s[ind[i]];
            }
            if(!exist[tmp] && tmp.size() >= 3){
                cout << tmp << endl;
                return 0;
            }
        }
    }while(next_permutation(ind.begin(), ind.end()));
    cout << -1 << endl;
    return 0;
}