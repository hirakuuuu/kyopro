#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/7/ALDS1_7_C

根節点、左部分木、右部分木の順で節点の番号を出力する。これを木の先行順巡回 (preorder tree walk) と呼ぶ
左部分木、根節点、右部分木の順で節点の番号を出力する。これを木の中間順巡回 (inorder tree walk) と呼ぶ
左部分木、右部分木、根節点の順で節点の番号を出力する。これを木の後行順巡回 (postorder tree walk) と呼ぶ
*/

struct node { int id, left, right, parent=-1; };
vector<node> tree(26);

// 先行順巡回（根→左→右）
vector<int> pre_tw;
void set_pre_tw(int s){
    pre_tw.push_back(s);
    if(tree[s].left != -1) set_pre_tw(tree[s].left);
    if(tree[s].right != -1) set_pre_tw(tree[s].right);
}

// 中間順巡回（左→根→右）
vector<int> ino_tw;
void set_ino_tw(int s){
    if(tree[s].left != -1) set_ino_tw(tree[s].left);
    ino_tw.push_back(s);
    if(tree[s].right != -1) set_ino_tw(tree[s].right);
}

// 後行順巡回（左→右→根）
vector<int> pos_tw;
void set_pos_tw(int s){
    if(tree[s].left != -1) set_pos_tw(tree[s].left);
    if(tree[s].right != -1) set_pos_tw(tree[s].right);
    pos_tw.push_back(s);
}

int main(){
    int n; cin >> n;
    rep(i, 0, n){
        int j; cin >> j;
        tree[j].id = j;
        cin >> tree[j].left >> tree[j].right;
        int l = tree[j].left, r = tree[j].right;
        if(l != -1) tree[l].parent = j;
        if(r != -1) tree[r].parent = j;
    }

    rep(i, 0, n){
        if(tree[i].parent == -1){
            set_pre_tw(i);
            set_ino_tw(i);
            set_pos_tw(i);
            cout << "Preorder" << endl;
            rep(j, 0, n){
                cout << " " << pre_tw[j];
            }
            cout << endl;

            cout << "Inorder" << endl;
            rep(j, 0, n){
                cout << " " << ino_tw[j];
            }
            cout << endl;

            cout << "Postorder" << endl;
            rep(j, 0, n){
                cout << " " << pos_tw[j];
            }
            cout << endl;
        }
    }
}