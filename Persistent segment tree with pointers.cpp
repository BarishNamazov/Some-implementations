#include <bits/stdc++.h>

using namespace std;

const int maxx = 100005;

int n, q, arr[maxx];
string type; int iq, jq, xq;

struct node {
    int val;
    node *l, *r;
    node (int v, node* L, node* R):
        val(v), l(L), r(R) {};
};
typedef node* pnode;
#define pnew new node(0, NULL, NULL)
pnode root[maxx]; int nxt = 0;

int get_val(pnode v) {
    return (v == NULL ? 0 : v -> val);
}

void build(pnode &v, int l, int r) {
    if (v == NULL) v = pnew;
    if (l == r) {
        v -> val = arr[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(v -> l, l, mid);
    build(v -> r, mid + 1, r);
    v -> val = get_val(v -> l) + get_val(v -> r);
}

void update(pnode &prev, pnode &v, int l, int r, int i, int val) {
    if (i < l || i > r) {
        return;
    }
    if (v == NULL) v = pnew;
    if (l == r) {
        v -> val = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        v -> r = prev -> r;
        update(prev -> l, v -> l, l, mid, i, val);
    } else {
        v -> l = prev -> l;
        update(prev -> r, v -> r, mid + 1, r, i, val);
    }
    v -> val = get_val(v -> l) + get_val(v -> r);
}

int query(pnode &v, int l, int r, int i) {
    if (i > r || i < l) {
        return 0;
    }
    if (l == r) {
        return v -> val;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        return query(v -> l, l, mid, i);
    } else {
        return query(v -> r, mid + 1, r, i);
    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(root[++nxt], 1, n);
    cin >> q;
    while (q --) {
        cin >> type;
        if (type[0] == 'c') {
            cin >> iq >> jq >> xq;
            update(root[iq], root[++nxt], 1, n, jq, xq);
        } else {
            cin >> iq >> jq;
            cout << query(root[iq], 1, n, jq) << endl;
        }
    }
    return 0;
}
