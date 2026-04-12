#include <iostream>
using namespace std;

char tree[26][2]; // [³ëµå][0=left, 1=right]

void preorder(char cur);
void inorder(char cur);
void postorder(char cur);

int main() {
    int N;
    cin >> N;

    while (N--) {
        char p, l, r;
        cin >> p >> l >> r;

        tree[p - 'A'][0] = l;
        tree[p - 'A'][1] = r;
    }

    preorder('A');  cout << "\n";
    inorder('A');   cout << "\n";
    postorder('A'); cout << "\n";
}

void preorder(char cur) {
    if (cur == '.') return;

    cout << cur;
    preorder(tree[cur - 'A'][0]);
    preorder(tree[cur - 'A'][1]);
}

void inorder(char cur) {
    if (cur == '.') return;

    inorder(tree[cur - 'A'][0]);
    cout << cur;
    inorder(tree[cur - 'A'][1]);
}

void postorder(char cur) {
    if (cur == '.') return;

    postorder(tree[cur - 'A'][0]);
    postorder(tree[cur - 'A'][1]);
    cout << cur;
}