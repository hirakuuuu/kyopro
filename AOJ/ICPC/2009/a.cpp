#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

int main(){
    while(true){
        int n, p; cin >> n >> p;

        if(n+p == 0) return 0;

        int i = 0, wan = p;
        vector<int> cnt(n);
        while(true){
            if(wan > 0){
                cnt[i]++;
                wan--;
                if(cnt[i] == p){
                    cout << i << endl;
                    break;
                }
            }else{
                wan = cnt[i];
                cnt[i] = 0;
            }
            i++;
            i %= n;
        }
    }
    
    return 0;
}