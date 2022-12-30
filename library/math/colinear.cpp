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

/*
同一直線の判定はdouble型を使ったらダメ
*/

long long px[305];
long long py[305];

bool colinear(int a, int b, int c) {
	long long val1 = (py[b] - py[a])*(px[c] - px[a]);
	long long val2 = (px[b] - px[a])*(py[c] - py[a]);
	return (val1 == val2);
}


int main(){
    
    return 0;
}