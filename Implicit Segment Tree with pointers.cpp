/*
 Implicit (Dynamic) Segment Tree written with pointers
 Below code determines the maximum number in range with update queries,
 can be modified easily to solve other problems as well
*/
#include <bits/stdc++.h>

using namespace std;

const int maxx = 100005;

struct node {
    int val;
    node *l, *r;
    node(int v, node* L, node* R):
        val(v), l(L), r(R) {};
};
typedef node* pnode;
int getval(pnode &x) {
    return (x == NULL ? 0 : x -> val);
}
void update(pnode &root, int l, int r, int pos, int x) {
    if (root == NULL) {
        root = new node(0, NULL, NULL);
    }
    if (l == r) {
        root -> val = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        update(root -> l, l, mid, pos, x);
    } else {
        update(root -> r, mid + 1, r, pos, x);
    }
    root -> val = max(getval(root -> l), getval(root -> r));
}
int query(pnode &root, int l, int r, int i, int j) {
    if (root == NULL || i > r || j < l) {
        return 0;
    }
    if (i <= l && r <= j) {
        return root -> val;
    }
    int mid = (l + r) >> 1;
    return max(query(root -> l, l, mid, i, j), query(root -> r, mid + 1, r, i, j));
}

pnode roots[maxx];
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    return 0;
}
