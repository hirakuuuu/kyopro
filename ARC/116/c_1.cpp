#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL)
#define endl '\n'

#define int long long

const int MOD = 998244353;
const int INF = 1e9;
const int SIZE = 300001;



int n, m;

int fact[SIZE];
int invf[SIZE];
int minFactor[SIZE];

int pow(int a, int e) {
    int r = 1, b = a % MOD;
    while (e > 0) {
        if (e & 1)
            r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

int inv(int x) {
    return pow(x, MOD-2);
}

int comb(int n, int r) {
    return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
}



int32_t main() {
    fastio;

    cin >> n >> m;

    fact[0] = 1;
    for (int i=1; i<SIZE; i++) fact[i] = fact[i-1] * i % MOD;
    invf[SIZE-1] = inv(fact[SIZE-1]);
    for (int i=SIZE-2; i>=0; i--) invf[i] = invf[i+1] * (i+1) % MOD;

    

    for (int i=2; i<=m; i++)
    minFactor[i] = i;
  
    for (int i=2; i*i<=m; i++)
        if (minFactor[i] == i)
            for (int j=i*i; j<=m; j+=i)
                if (minFactor[j] == j)
                    minFactor[j] = i;


    int ans = 1;

    for (int i=2; i<=m; i++) {
        int num = i;
        map<int,int> mp;

        while (num > 1) {
            mp[minFactor[num]]++;
            num /= minFactor[num];
        }

        int val = 1;
        for (auto it=mp.begin(); it != mp.end(); it++) {
            val = val * comb(n-1 + it->second,  it->second) % MOD;            
        }
        ans = (ans + val) % MOD;
    }

    cout << ans;
}