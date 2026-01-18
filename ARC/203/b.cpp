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
        vector<int> a(n), b(n);
        int sum_a = 0, sum_b = 0;
        rep(i, 0, n){
            cin >> a[i];
            sum_a += a[i];
        }
        rep(i, 0, n){
            cin >> b[i];
            sum_b += b[i];
        }

        if(a == b){
            cout << "Yes" << endl;
            continue; 
        }

        if(sum_a != sum_b){
            cout << "No" << endl;
        }else{
            if(sum_a == 1){
                if(a[0] == 1 || a[n-1] == 1 || b[0] == 1 || b[n-1] == 1){
                    cout << "No" << endl;
                }else{
                    cout << "Yes" << endl;
                }
            }else{
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}