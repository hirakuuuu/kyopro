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
// https://atcoder.jp/contests/abc248/tasks/abc248_e

long long px[305];
long long py[305];

bool colinear(int a, int b, int c) {
	long long val1 = (py[b] - py[a])*(px[c] - px[a]);
	long long val2 = (px[b] - px[a])*(py[c] - py[a]);
	return (val1 == val2);
}


int main(){
    int n, k; cin >> n >> k;
    rep(i, 0, n) cin >> px[i] >> py[i];

    if(k == 1){
        cout << "Infinity" << endl;
        return 0;
    }

    set<vector<int>> s;

    rep(i, 0, n){
        rep(j, i+1, n){
            vector<int> list;
            rep(l, 0, n){
                if(l == i or l == j) list.push_back(l);
                else if(colinear(i, j, l)) list.push_back(l);
            }
            if(list.size() >= k) s.insert(list);
        }
    }

    cout << s.size() << endl;



    return 0;
}