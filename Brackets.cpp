#include <bits/stdc++.h>
using namespace std;
struct node
{
    int open;
    int closed;
};
node tree[3 * 30005];
char arr[30005];
/*This function is used to build the 
Segment Tree*/
void build(int index, int start, int end)
{
    if (start == end)
    {
        if (arr[start] == '(')
        {
            tree[index].open = 1;
            tree[index].closed = 0;
        }
        else
        {
            tree[index].open = 0;
            tree[index].closed = 1;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * index + 1, start, mid);
        build(2 * index + 2, mid + 1, end);

        int change =
            min(tree[2 * index + 1].open, tree[2 * index + 2].closed);
        tree[index].open =
            tree[2 * index + 1].open + tree[2 * index + 2].open - change;
        tree[index].closed =
            tree[2 * index + 1].closed + tree[2 * index + 2].closed - change;
    }
}
/*This function is used to answer the queries
that are there*/
node query(int index, int start, int end, int l, int r)
{
    node result;

    if (start == l && end == r)
        return tree[index];

    int mid = (start + end) / 2;
    if (l > mid)
        return query(2 * index + 2, mid + 1, end, l, r);
    if (r <= mid)
        return query(2 * index + 1, start, mid, l, r);

    node left = query(2 * index + 1, start, mid, l, r);
    node right = query(2 * index + 2, mid + 1, end, l, r);

    int change =
        min(left.open, right.closed);
    result.open =
        left.open + right.open - change;
    result.closed =
        left.closed + right.closed - change;
    return result;
}
/*This function is used to update the value in
the Segment Tree*/
void update(int index, int start, int end, int idx, char value)
{
    if (start == end)
    {
        if (value == '(')
        {
            tree[index].open = 1;
            tree[index].closed = 0;
        }
        else
        {
            tree[index].open = 0;
            tree[index].closed = 1;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * index + 1, start, mid, idx, value);
        else
            update(2 * index + 2, mid + 1, end, idx, value);

        int change =
            min(tree[2 * index + 1].open, tree[2 * index + 2].closed);
        tree[index].open =
            tree[2 * index + 1].open + tree[2 * index + 2].open - change;
        tree[index].closed =
            tree[2 * index + 1].closed + tree[2 * index + 2].closed - change;
    }
}
int main()
{
    ios::sync_with_stdio(false);

    int n, q, val;
    for (int cc = 1; cc <= 10; ++cc)
    {
        cin >> n;
        cin >> arr;
        cin >> q;
        build(0, 0, n - 1);
        cout << "Test " << cc << ":\n";
        while (q--)
        {
            cin >> val;
            if (val)
            {
                arr[val - 1] = arr[val - 1] == '(' ? ')' : '(';
                update(0, 0, n - 1, val - 1, arr[val - 1]);
            }
            else
            {
                node result = query(0, 0, n - 1, 0, n - 1);
                if (result.open == 0 && result.closed == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}