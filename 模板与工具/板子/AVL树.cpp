#include <bits/stdc++.h>
#define int long long
using namespace std;

// 平衡搜索二叉树
// 平衡性：任意节点左右子树高度差不超过1
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int head, idx;
struct Node
{
    int cnt, key, size;
    int left, right, height;
} tr[N];
int removeMostleft(int i, int mostleft);
void up(int i)
{
    auto l = tr[tr[i].left], r = tr[tr[i].right];
    tr[i].size = l.size + r.size + tr[i].cnt;
    tr[i].height = max(r.height, l.height) + 1;
}
int leftRotate(int i)
{
    auto r = tr[i].right;
    tr[i].right = tr[r].left;
    tr[r].left = i;
    up(i);
    up(r);
    return r;
}
int rightRotate(int i)
{
    auto l = tr[i].left;
    tr[i].left = tr[l].right;
    tr[l].right = i;
    up(i);
    up(l);
    return l;
}
int maintain(int i)
{
    auto lh = tr[tr[i].left].height, rh = tr[tr[i].right].height;
    auto &l = tr[tr[i].left], &r = tr[tr[i].right];
    if (lh - rh > 1)
    {
        if (tr[l.left].height >= tr[l.right].height)
        {
            i = rightRotate(i);
        }
        else
        {
            tr[i].left = leftRotate(tr[i].left);
            i = rightRotate(i);
        }
    }
    else if (rh - lh > 1)
    {
        if (tr[r.right].height >= tr[r.left].height)
        {
            i = leftRotate(i);
        }
        else
        {
            tr[i].right = rightRotate(tr[i].right);
            i = leftRotate(i);
        }
    }
    return i;
}
int add(int i, int num)
{
    auto &it = tr[i];
    if (i == 0)
    {
        tr[++idx].key = num;
        tr[idx].cnt = tr[idx].size = tr[idx].height = 1;
        return idx;
    }
    if (it.key == num)
        it.cnt++;
    else if (it.key > num)
        it.left = add(it.left, num);
    else
        it.right = add(it.right, num);
    up(i);
    return maintain(i);
}
int remove(int i, int num)
{
    auto &it = tr[i];
    if (it.key < num)
        it.right = remove(it.right, num);
    else if (it.key > num)
        it.left = remove(it.left, num);
    else
    {
        if (it.cnt > 1)
        {
            it.cnt--;
        }
        else
        {
            if (it.left == 0 && it.right == 0)
                return 0;
            else if (it.left != 0 && it.right == 0)
                i = it.left;
            else if (it.right != 0 && it.left == 0)
                i = it.right;
            else
            {
                int mostleft = it.right;
                while (tr[mostleft].left != 0)
                {
                    mostleft = tr[mostleft].left;
                }
                it.right = removeMostleft(it.right, mostleft);
                tr[mostleft].left = tr[i].left;
                tr[mostleft].right = tr[i].right;
                i = mostleft;
            }
        }
    }
    up(i);
    return maintain(i);
}
int removeMostleft(int i, int mostleft)
{
    if (i == mostleft)
        return tr[i].right;
    else
    {
        tr[i].left = removeMostleft(tr[i].left, mostleft);
        up(i);
        return maintain(i);
    }
}
int small(int i, int num)
{
    if (i == 0)
        return 0;
    auto &it = tr[i];
    if (it.key >= num)
        return small(it.left, num);
    else
        return tr[it.left].size + it.cnt + small(it.right, num);
}
int Rank(int i, int x)
{
    auto &it = tr[i];
    if (tr[it.left].size >= x)
        return Rank(it.left, x);
    else if (tr[it.left].size + it.cnt < x)
        return Rank(it.right, x - tr[it.left].size - it.cnt);
    return it.key;
}
int pre(int i, int num)
{
    auto &it = tr[i];
    if (i == 0)
        return -INF;
    if (it.key >= num)
        return pre(it.left, num);
    else
        return max(it.key, pre(it.right, num));
}
int post(int i, int num)
{
    auto &it = tr[i];
    if (i == 0)
        return INF;
    if (it.key <= num)
        return post(it.right, num);
    else
        return min(it.key, post(it.left, num));
}
signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            head = add(head, x);
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            if (small(head, x) != small(head, x + 1))
                head = remove(head, x);
        }
        else if (op == 3)
        {
            int x;
            cin >> x;
            cout << small(head, x) + 1 << endl;
        }
        else if (op == 4)
        {
            int x;
            cin >> x;
            cout << Rank(head, x) << endl;
        }
        else if (op == 5)
        {
            int x;
            cin >> x;
            cout << pre(head, x) << endl;
        }
        else
        {
            int x;
            cin >> x;
            cout << post(head, x) << endl;
        }
    }
    return 0;
}