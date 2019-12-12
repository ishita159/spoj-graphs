
#include <bits/stdc++.h>
using namespace std;
vector<int> val;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> val(n);
    //to make the adjacency list
    vector<pair<int, int> > e[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    //update the list according to the corresponding values
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //array is starting from 0 hence decrement u and v
        u--;
        v--;
        e[u].push_back(make_pair(val[v], v));
        e[v].push_back(make_pair(val[u], u));
    }

    for (int i = 0; i < n; i++)
    {
        //if size of that section of the list is less than the given kth position then return negative value
        if (e[i].size() < k)
        {
            cout << -1 << endl;
        }
        //else sort the elements corresponding to the element in the list 
        else
        {
            sort(e[i].begin(), e[i].end());
            int n = e[i].size();
            //(n-k) -> array is sorted in asscending order hence check position from last
            cout << e[i][n - k].second + 1 << endl;
        }
    }
    return 0;
}
