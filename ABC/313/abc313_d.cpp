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
// https://atcoder.jp/contests/abc313/tasks/abc313_d

/*
一気にやろうとするからダメ
部分的に考えてみる

k+1個の整数について1個ずらしで質問すると
- kが奇数なので、総和が分かる
- 後は各答えを使えばk+1個の整数も特定できる
残りの数字は、分かっているｋ個の数字を使うことで特定できる

*/

int main(){
    int n, k; cin >> n >> k;
    vector<int> s(k+1);
    rep(i, 0, k+1){
        cout << '?';
        rep(j, 0, k){
            cout << ' ' << (i+j)%(k+1)+1;
        }
        cout << endl;
        cin >> s[i];
    }
    int sum = 0;
    rep(i, 0, k+1) sum ^= s[i];
    vector<int> a(n);
    rep(i, 0, k+1){
        a[(i+k)%(k+1)] = sum^s[i];
    }
    rep(i, k+1, n){
        cout << "? " << i+1;
        rep(j, 0, k-1){
            cout << ' ' << j+1;
        }
        cout << endl;
        int tmp; cin >> tmp;
        a[i] = tmp^s[0]^a[k-1];
    }
    cout << '!';
    rep(i, 0, n) cout << ' ' << a[i];
    cout << endl;
}