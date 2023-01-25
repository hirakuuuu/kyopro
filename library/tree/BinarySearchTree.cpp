#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
const int MOD = 1000000007;
const int mod = 998244353;

/*
二分探索木は、各節点にキーを持ち、次に示す二分探索条件を常に満たすように構築される
 -xを二分探索木に属するある節点とする。yをxの左部分木に属する節点とすると、(yのキー) <= (xのキー)である
 -zをxの右部分木に属する節点とすると、(xのキー) <= (ｚのキー)である
*/

// ここから
// 各節点には、キー、親、左の子、右の子へのポインタを持たせる
struct node { int id, key, parent=-1, left=-1, right=-1; };

class BinarySearchTree {
    // 根のid
    int root;
    // 木
    vector<node> tree;
    // 挿入する位置
    int pos;

public:
    BinarySearchTree(ll n_ = 1): tree(n_){
        root = -1;
        pos = 0;
    };
    // 挿入
    void insert(int val){
        // pos番目の木のid, keyを代入
        tree[pos].id = pos;
        tree[pos].key = val;
        // root == NILであればposは根のidである
        if(root == -1){
            root = pos;
            pos++;
            return;
        }
        // 根の親 = NIL
        int y = tree[root].parent; 
        // 根
        int x = root;
        while(x != -1){
            y = x;
            if(tree[pos].key < tree[x].key) x = tree[x].left;
            else x = tree[x].right;
        }
        // zの親のidはyになる
        tree[pos].parent = y; 
        // zのkeyにあわせてyの右の子になるか、左の子になるかを決める
        if(tree[pos].key < tree[y].key) tree[y].left = pos; 
        else tree[y].right = pos;

        pos++;
    }

    // 探索
    int find(int z){
        // 値を取得
        int x = root;
        // xがNILになるか、zがkeyであるノードが見つかるまで、探索
        while(x != -1 and z != tree[x].key){
            // zの値によって次の行き先が決まる
            if(z < tree[x].key) x = tree[x].left;
            else x = tree[x].right;
        }
        // 値が見つかればそのid、見つからなければNILが変える
        return x;
    }

    // 削除
    void eliminate(int x){
        // xが２つの子を持つ場合
        if(tree[x].left > 0 and tree[x].right > 0){
            // xの次接点（中間順巡回でxの次に来るノード）を取得
            int y = tree[x].right;
            while(tree[y].left != -1) y = tree[y].left;
            // xのkeyを次接点のkeyに変更
            tree[x].key = tree[y].key;
            // 次接点を削除
            eliminate(y);
        // xが左の子のみを持つ場合
        }else if(tree[x].left > 0){
            // xの左の子を取得
            int y = tree[x].left;
            // xの親を取得
            int p = tree[x].parent;
            // xの左の子の親をxの親に変更
            tree[y].parent = p;
            // xの親の子のうち、xである方をxの左の子に変更
            if(tree[p].left == x) tree[p].left = y;
            if(tree[p].right == x) tree[p].right = y;
        // xが右の子のみを持つ場合
        }else if(tree[x].right > 0){
            // xの右の子を取得
            int y = tree[x].right;
            // xの親を取得
            int p = tree[x].parent;
            // xの右の子の親をxの親に変更
            tree[y].parent = p;
            // xの親の子のうち、xである方をxの右の子に変更
            if(tree[p].left == x) tree[p].left = y;
            if(tree[p].right == x) tree[p].right = y;
        // xが子を持たない場合
        }else{
            // xの親を取得
            int y = tree[x].parent;
            // xの親の子で、xである方をNILにする
            if(tree[y].left == x) tree[y].left = -1;
            if(tree[y].right == x) tree[y].right = -1;
        }
    }

    // 先行順巡回の出力
    void printPre(int r = 0){
        if(r == -1) return;
        cout << " " << tree[r].key;
        printPre(tree[r].left);
        printPre(tree[r].right);
    }

    // 中間順巡回の出力
    void printIn(int r = 0){
        if(r == -1) return;
        printIn(tree[r].left);
        cout << " " << tree[r].key;
        printIn(tree[r].right);
    }

};
// ここまで




int main(){
    int m; cin >> m;
    BinarySearchTree bst(m);

    
    while(m--){
        string s; cin >> s;
        if(s == "insert"){
            int val; cin >> val;
            bst.insert(val);
        }else if(s == "find"){
            int k; cin >> k;
            if(bst.find(k) == -1) cout << "no" << endl;
            else cout << "yes" << endl;
        }else if(s == "delete"){
            int k; cin >> k;
            bst.eliminate(bst.find(k));
        }else{
            bst.printIn();
            cout << endl;
            bst.printPre();
            cout << endl;
        }
    }
}