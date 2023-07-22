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
// https://atcoder.jp/contests/abc201/tasks/abc201_a

int main(){
    vector<int> a(3);
    rep(i, 0, 3) cin >> a[i];

    sort(a.begin(), a.end());
    do{
        if(a[1]-a[0] == a[2]-a[1]){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << "No" << endl;
    return 0;
}