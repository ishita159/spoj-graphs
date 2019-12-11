#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t, edges, i, city1, city2, count;
    cin >> t;
    while (t--)
    {
        cin >> edges;
        long long int arr[10001];
        memset(arr, 0, sizeof(arr));
        for (i = 0; i < edges; i++)
        {
            cin >> city1 >> city2;
            arr[city1] = 1;
            arr[city2] = 1;
        }
        count = 0;
        for (i = 1; i <= 10001; i++)
        {
            if (arr[i] == 1)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}