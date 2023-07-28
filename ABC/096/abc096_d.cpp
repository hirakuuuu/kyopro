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
// https://atcoder.jp/contests/abc096/tasks/abc096_d

// 0ならば素数, 0でないなら最小の素因数
vector<int> erat(100005);
void init_e(){
    rep(i, 2, sqrt(100005)){
        if(erat[i] == 0){
            for(int j = i*i; j <= 100005; j += i){
                if(erat[j] == 0) erat[j] = i;
            }
        }
    }
}

int main(){
    init_e();
    int n; cin >> n;
    vector<int> ans;
    for(int i = 2; i <= 55555 && ans.size() < n; i += 5){
        if(erat[i] == 0) ans.push_back(i);
    }

    for(auto a: ans){
        cout << a << ' ';
    }
    cout << endl;


    
    return 0;
}