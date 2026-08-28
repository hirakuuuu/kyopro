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
        vector<int> a(2*n);
        rep(i, 0, 2*n){
            cin >> a[i]; a[i]--;
        }
        vector<int> c;
        set<int> odd, even;
        bool is_odd = true;
        for(int i = 0; i < 2*n;){
            if(is_odd){
                int j = i;
                while(j < 2*n && !odd.count(a[j])){
                    odd.insert(a[j]);
                    j++;
                }
                i = j;
            }else{
                int j = i;
                while(j < 2*n && !even.count(a[j])){
                    even.insert(a[j]);
                    j++;
                }
                i = j;
            }
            is_odd = !is_odd;
            if(i >= 2*n) break;
            c.push_back(i);
        }
        cout << c.size() << endl;
        for(auto cc: c){
            cout << cc << ' ';
        }
        cout << endl;
    }
    
    return 0;
}