#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

vector<int> gdp, is_gdp(300005, 1);

int main(){
    rep(i, 6, 300005){
        if(i%7 == 1 or i%7 == 6){
            if(is_gdp[i]){
                gdp.push_back(i);
                for(int j = i; j < 300005; j += i){
                    is_gdp[j] = 0;
                }
            }
        }
    }


    while(true){
        int n; cin >> n;
        if(n == 1) break;
        cout << n <<  ":";
        for(auto p: gdp){
            if(n%p == 0){
                cout << " " << p;
            }
        }
        cout << endl;
    }
    
    return 0;
}