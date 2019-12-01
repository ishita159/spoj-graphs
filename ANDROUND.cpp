#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define pb push_back
#define endl '\n'
#define pii pair<int, int>
#define lc 2 * x + 1
#define rc 2 * x + 2
#define all(v) v.begin(), v.end()
ll poww(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
using namespace std;

ll int a[20005], ans[20005], tree[100005];

void build(int l, int r, int x)
{

    if (l == r)
    {
        tree[x] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, lc);
    build(mid + 1, r, rc);
    tree[x] = tree[lc] & tree[rc];
}

ll query(int ql, int qr, int l, int r, int x)
{

    if (l > r || ql > r || l > qr)
        return 8589934591;
    if (ql <= l && qr >= r)
        return tree[x];
    int mid = (l + r) / 2;
    ll ans;
    ans = query(ql, qr, l, mid, lc);
    ans &= query(ql, qr, mid + 1, r, rc);
    return ans;
}

int main()
{
    fast;
    //freopen("input.txt", "r+", stdin);
    //freopen("output.txt", "w+", stdout);

    ll int t, i, j, k, n;

    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (!i)
                j = a[i];
            else
                j &= a[i];
        }
        build(0, n - 1, 0);
        for (i = 0; i < n; ++i)
        {
            if (k > n / 2)
                ans[i] = j;
            else
            {
                if (i + k >= n)
                {
                    ans[i] = query(i, n - 1, 0, n - 1, 0);
                    ans[i] &= query(0, (i + k) % n, 0, n - 1, 0);
                }
                else
                    ans[i] = query(i, (i + k), 0, n - 1, 0);
                if (i - k < 0)
                {
                    ans[i] &= query(0, i, 0, n - 1, 0);
                    ans[i] &= query(n - k + i, n - 1, 0, n - 1, 0);
                }
                else
                    ans[i] &= query(i - k, i, 0, n - 1, 0);
            }
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}