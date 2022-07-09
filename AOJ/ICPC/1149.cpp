#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

// 問題
// https://onlinejudge.u-aizu.ac.jp/problems/1149

int area(pii p1, pii p2){
    return (p2.first-p1.first)*(p2.second-p1.second);
}

int main(){
    while(true){
        int n, w, d; cin >> n >> w >> d;
        if(n*n+w*w+d*d == 0) break;
        vector<vector<pii>> p(n+1, vector<pii>(2));
        p[0] = {{0, 0}, {d, w}};

        rep(i, 0, n){
            int j, s; cin >> j >> s;
            vector<pii> np = p[j-1];
            rep(k, j-1, i){
                p[k] = p[k+1];
            }

            vector<int> dist = {np[1].second-np[0].second, np[1].first-np[0].first};
            s %= 2*dist[0]+2*dist[1];


            rep(k, 0, 4){
                if(s < dist[k%2]){
                    vector<pii> c1(2), c2(2);
                    if(k == 0){
                        c1 = {np[0], {np[1].first, np[0].second+s}};
                        c2 = {{np[0].first, np[0].second+s}, np[1]};
                    }else if(k == 1){
                        c1 = {np[0], {np[0].first+s, np[1].second}};
                        c2 = {{np[0].first+s, np[0].second}, np[1]};
                    }else if(k == 2){
                        c1 = {np[0], {np[1].first, np[0].second+dist[0]-s}};
                        c2 = {{np[0].first, np[0].second+dist[0]-s}, np[1]};
                    }else{
                        c1 = {np[0], {np[0].first+dist[1]-s, np[1].second}};
                        c2 = {{np[0].first+dist[1]-s, np[0].second}, np[1]};
                    }
                    if(area(c1[0], c1[1]) > area(c2[0], c2[1])) swap(c1, c2);
                    p[i] = c1;
                    p[i+1] = c2;
                    break;
                }else{
                    s -= dist[k%2];
                }
            }
        }
        vector<int> areas(n+1);
        rep(i, 0, n+1){
            areas[i] = area(p[i][0], p[i][1]);
        }
        sort(areas.begin(), areas.end());
        rep(i, 0, n+1){
            if(i > 0) cout << ' ';
            cout << areas[i];
        }
        cout << endl;
    }
    return 0;
}