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
    random_device seed_gen;
    mt19937 engine(seed_gen());

    int n; cin >> n;
    vector<int> p(n*n);
    iota(p.begin(), p.end(), 1);
    vector<vector<int>> a(n, vector<int>(n));

    auto check = [&]() -> bool {
        set<int> s;
        rep(i, 0, n){
            int sum = 0;
            rep(j, 0, n){
                sum += a[i][j];
            }
            s.insert(sum);
        }
        rep(j, 0, n){
            int sum = 0;
            rep(i, 0, n){
                sum += a[i][j];
            }
            s.insert(sum);
        }
        return s.size() == 2*n;
    };

    while(true){
        shuffle(p.begin(), p.end(), engine);
        rep(i, 0, n){
            rep(j, 0, n){
                a[i][j] = p[i*n+j];
            }
        }
        if(check()) break;
    }
   
    // assert(check());
    rep(i, 0, n){
        rep(j, 0, n){
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    
    return 0;
}