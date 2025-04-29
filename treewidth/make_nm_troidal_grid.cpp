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
    
    for(int n = 3; n <= 18; n++){
        string outfilename = "./nm_troidal_grid/nm_troidal_grid_"+to_string(n)+".gr";
        ofstream writing_file(outfilename);
        int m = n+1;
        int N = n*m, M = n*m*2;
        writing_file << "p tw " << N << ' ' << M << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                writing_file << i*m+j+1 << ' ' << i*m+(j+1)%m+1 << endl;
                writing_file << i*m+j+1 << ' ' << ((i+1)%n)*m+j+1 << endl;
            }
        }


    }
    return 0;
}