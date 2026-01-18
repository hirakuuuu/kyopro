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
    int n; cin >> n; 
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
    }

    vector<pair<pair<int, int>, set<int>>> s;
    for(int i = 0; i < n; ){
        int j = i+1;
        s.push_back({{i, i+1}, set<int>()});
        s.back().second.insert(a[i]);
        while(j < n){
            if(s.back().second.count(a[j])) j++;
            else break;
        }
        s.back().first.second = j;
        i = j;
    }

    cout << s.size() << endl;
    rep(k, 2, n+1){
        
    }
    
    return 0;
}