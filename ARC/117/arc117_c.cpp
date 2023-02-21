#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define rrep(i, a, n) for(int i = a; i >= n; i--)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD_NUM = 1000000007;
const int mod_num = 998244353;
const int iinf = 1001001001;

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

// 問題
// https://atcoder.jp/contests/arc117/tasks/arc117_c


vector<ll> bf(400005), bg(400005);

void init(){
    rep(i, 1, 400005){
        int j = i;
        while(j%3 == 0){
            j /= 3;
            bf[i]++;
        }
        bg[i] = j%3;
    }
    bg[0] = 1;
    rep(i, 1, 400005) bf[i] += bf[i-1];
    rep(i, 1, 400005) bg[i] = (bg[i]*bg[i-1])%3;
}

ll nCr(ll n, ll r){
    if(bf[n] - bf[n-r] - bf[r] > 0) return 0;
    else{
        if(bg[n] == (bg[n-r]*bg[r])%3) return 1;
        else return 2;
    }
}

int main(){
    int n; cin >> n;
    string s; cin >> s;
    init();

    string c = "BWR";
    vector<int> tmp(n);
    rep(i, 0, n){
        rep(j, 0, 3){
            if(s[i] == c[j]){
                tmp[i] = j;
            }
        }
    }

    int ans = 0;
    if(n%2 == 0){
        rep(i, 0, n){
            ans += 3-(tmp[i]*nCr(n-1, i))%3;
            ans %= 3;
        }
    }else{
        rep(i, 0, n){
            ans += (tmp[i]*nCr(n-1, i))%3;
            ans %= 3;
        }
    }

    cout << c[ans] << endl;
    
    return 0;
}