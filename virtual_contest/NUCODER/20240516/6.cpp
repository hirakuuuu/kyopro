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

/*
DELETEの処理は今のAについて末尾を削除するだけなので、保存した状態を変えてはいけない.
*/

int main(){
    int q; cin >> q;
    unordered_map<int, int> tail; // ページ番号と末尾の対応
    vector<int> par = {0}, val = {-1};
    int pos = 0;
    while(q--){
        string s; cin >> s;
        assert(0 <= pos && pos < par.size());
        if(s == "ADD"){
            int x; cin >> x;
            val.push_back(x);
            par.push_back(pos);
            pos = par.size()-1;
        }else if(s == "DELETE"){
            pos = par[pos];
        }else if(s == "SAVE"){
            int y; cin >> y;
            tail[y] = pos;
        }else{
            int z; cin >> z;
            pos = tail[z];
        }
        cout << val[pos] << ' ';
    }
    cout << endl;

    
    return 0;
}