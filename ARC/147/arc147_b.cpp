#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
// 問題
// https://atcoder.jp/contests/arc147/tasks/arc147_b


int p[405];
vector<pair<char,int>> ans;
void f(char c,int i){
    ans.emplace_back(c,i+1);
    swap(p[i],p[i+1+c-'A']);
}

int main(){
    int n; cin >> n;

    rep(i, 0, n) cin >> p[i];
    // 前に悪いインデックスを集める
    rep(i, 0, n){
        rep(j, 0, n-2){
            if(p[j]%2 != p[j+2]%2 and p[j]%2 != j%2) f('B', j);
        }
    }
    // 悪いインデックス同士を入れ替える
    rep(i, 0, n-1){
        if(p[i]%2 != p[i+1]%2 and p[i]%2 == i%2) f('A',i);
    }
    // Bでバブルソート
    rep(i, 0, n){
        rep(j, 0, n-2){
            if(p[j] > p[j+2]) f('B', j);
        }
    }
    cout << ans.size() << endl;
    for(auto x:ans) cout << x.first << ' ' << x.second << endl;




    
    return 0;
}