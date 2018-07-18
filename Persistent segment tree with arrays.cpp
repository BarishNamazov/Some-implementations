/*
 Another implementation of the Persistent Segment Tree I wrote while learning this data structure
 Works slightly slower than "Persistent segment tree with arrays, faster and simpler.cpp"
 Below code is the solution for the problem: https://www.e-olymp.com/en/problems/2955
*/
#include <bits/stdc++.h>

using namespace std;

const int maxx = 100005;
const int lg5 = 18;

int n, q, arr[maxx];
string type; int iq, jq, xq;

int root[maxx], id = 0;

int nxt = 0;
struct node {
    int mid, l, r, val;
} tree[2 * maxx * lg5];

int build(int l, int r) {
    if (l == r) {
        tree[++nxt] = node{r, l, r, arr[l]};
        return nxt;
    } int id = ++nxt;
    int mid = (l + r) >> 1;
    tree[id] = node{mid, build(l, mid), build(mid + 1, r), arr[mid]};
    return id;
}

int update(int v, int i, int val) {
    if (tree[v].l == tree[v].r) {
        tree[++nxt] = node{tree[v].r, tree[v].l, tree[v].r, val};
        return nxt;
    } int id = ++nxt;
    int mid = tree[v].mid, l = tree[v].l, r = tree[v].r;
    if (i <= mid) {
        l = update(l, i, val);
    } else {
        r = update(r, i, val);
    }
    tree[id] = node{tree[v].mid, l, r, val};
    return id;
}

int query(int v, int i) {
    if (tree[v].l == tree[v].r) {
        return tree[v].val;
    }
    if (i <= tree[v].mid) {
        return query(tree[v].l, i);
    } else {
        return query(tree[v].r, i);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    root[++id] = build(1, n);
    cin >> q;
    while (q --) {
        cin >> type;
        if (type[0] == 'c') {
            cin >> iq >> jq >> xq;
            root[++id] = update(root[iq], jq, xq);
        } else {
            cin >> iq >> jq;
            cout << query(root[iq], jq) << endl;
        }
    }
    return 0;
}
