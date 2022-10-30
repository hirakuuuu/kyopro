#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;


int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    map<int, int> A, B;

    rep(i, 0, n){
        cin >> a[i];
        A[a[i]]++;
    }
    rep(i, 0, n){
        cin >> b[i];
        B[b[i]]++;
    }

    if(A != B){
        cout << "No" << endl;
        return 0;
    }

    if(A.size() != n){
        cout << "Yes" << endl;
        return 0;
    }

    int ta = 0, tb = 0;
    rep(i, 0, n){
        rep(j, i+1, n){
            if(a[i] > a[j]) ta++;
            if(b[i] > b[j]) tb++;
        }
    }

    if(ta%2 == tb%2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
  
}