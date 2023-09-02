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
// https://atcoder.jp/contests/arc144/tasks/arc144_c

int main(){
    int n, k; cin >> n >> k;
    if(2*k > n){
        cout << -1 << endl;
        return 0;
    }

    int p = 0;
    vector<int> a;
    while(n-p >= 4*k){
        for(int i = p; i < p+k; i++){
            a.push_back(i+k);
        }
        for(int i = p+k; i < p+2*k; i++){
            a.push_back(i-k);
        }
        p += 2*k;
    }

    if(n-p <= 3*k){
        for(int i = p; i < n-k; i++){
            a.push_back(i+k);
        }
        for(int i = n-k; i < n; i++){
            a.push_back(i-(n-k)+p);
        }
    } else {
        for(int i = p; i < p+k; i++){
            a.push_back(i+k);
        }
        for(int i = p+k; i < n-2*k; i++){
            a.push_back(i-k);
        }
        for(int i = n-2*k; i < n-k; i++){
            a.push_back(i+k);
        }
        for(int i = n-k; i < p+3*k; i++){
            a.push_back(i-2*k);
        }
        for(int i = p+3*k; i < n; i++){
            a.push_back(i-k);
        }
    }

    for(auto aa: a){
        cout << aa+1 << ' ';
    }
    cout << endl;


    return 0;
}