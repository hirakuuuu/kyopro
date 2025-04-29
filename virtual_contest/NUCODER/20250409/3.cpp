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
    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 0, 3) rep(j, 0, 3){
        cin >> c[i][j];
    }
    vector<pair<int, int>> p;
    rep(i, 0, 3) rep(j, 0, 3){
        p.push_back({i, j});
    }

    long double num = 0.0;
    long double sum = 0.0;
    do{
        vector<vector<int>> row(3);
        vector<vector<int>> col(3);
        vector<int> naname1, naname2;
        rep(i, 0, 9){
            row[p[i].first].push_back(c[p[i].first][p[i].second]);
            col[p[i].second].push_back(c[p[i].first][p[i].second]);
            if(p[i].first == p[i].second){
                naname1.push_back(c[p[i].first][p[i].second]);
            }
            if(p[i].first+p[i].second == 2){
                naname2.push_back(c[p[i].first][p[i].second]);
            }
        }

        bool gakkari = false;
        rep(i, 0, 3){
            if(row[i][0] == row[i][1] && row[i][1] != row[i][2]) gakkari = true;
            if(col[i][0] == col[i][1] && col[i][1] != col[i][2]) gakkari = true;
        }
        if(naname1[0] == naname1[1] && naname1[1] != naname1[2]) gakkari = true;
        if(naname2[0] == naname2[1] && naname2[1] != naname2[2]) gakkari = true;
        if(!gakkari) num += 1.0;
        sum += 1.0;
    }while(next_permutation(p.begin(), p.end()));

    cout << setprecision(20) << num/sum << endl;
    return 0;
}
