#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://atcoder.jp/contests/arc149/tasks/arc149_b

int la[300005], lb[300005];

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<int> a_(n), b_(n);
    vector<int> ap(n), bp(n), used(n);
    rep(i, 0, n){
        cin >> a[i];
        ap[a[i]-1] = i;
    }
    rep(i, 0, n){
        cin >> b[i];
        bp[b[i]-1] = i;
    }

    rep(i, 0, n){
        a_[i] = a[bp[i]];
    }
    rep(i, 0, n){
        b_[i] = b[ap[i]];
    }

    int len_a = 0, len_b = 0;

    rep(i, 0, n){
        int pos = lower_bound(la, la+len_a+1, a_[i])-la;
        la[pos] = a_[i];
        if(pos > len_a) len_a++;
    }

    rep(i, 0, n){
        int pos = lower_bound(lb, lb+len_b+1, b_[i])-lb;
        lb[pos] = b_[i];
        if(pos > len_b) len_b++;
    }




    cout << n+max(len_a, len_b) << endl;




    
    return 0;
}