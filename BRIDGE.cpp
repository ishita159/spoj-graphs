#include <bits/stdc++.h>
using namespace std;
/*Standard LIS function*/
int LIS(int arr[], int size)
{
    int lis[size];
    memset(lis, 0, size);

    for (int i = 0; i < size; ++i)
        lis[i] = 1;
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
    int ans = lis[0];
    for (int i = 1; i < size; ++i)
        if (lis[i] > ans)
            ans = lis[i];
    return ans;
}
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int A[n], B[n];
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &B[i]);

        vector<pair<int, int> > v;

        /*Here the concept is to sort the 2nd array i.e according to the 
      end points, so while making pair b[i] comes before a[i]*/

        for (int i = 0; i < n; ++i)
            v.push_back(make_pair(B[i], A[i]));

        sort(v.begin(), v.end());

        for (int i = 0; i < n; ++i)
            B[i] = v[i].second;

        printf("%d\n", LIS(B, n));
    }
    return 0;
}

