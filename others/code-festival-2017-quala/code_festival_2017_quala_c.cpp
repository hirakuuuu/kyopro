#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c

/*
(h/2)*(w/2)個の4個の同じ文字の組みが必要
hが奇数かつｗが偶数なら全部偶数
hが偶数かつｗが奇数なら全部偶数
hが奇数かつｗが奇数なら1つ奇数であとは偶数
*/

int main(){
    int h, w; cin >> h >> w;
    vector<string> a(h);
    vector<int> cnt(26);
    rep(i, 0, h){
        cin >> a[i];
        rep(j, 0, w){
            cnt[a[i][j]-'a']++;
        }
    }

    int cnt_s = 0, cnt_a = 0;

    rep(i, 0, 26){
        cnt_s += cnt[i]/4;
        cnt_a += cnt[i]%2;
    }

    if(h%2 == 0 or w%2 == 0){
        if(cnt_s >= (h/2)*(w/2) and cnt_a == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(cnt_s >= (h/2)*(w/2) and cnt_a == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    
    return 0;
}