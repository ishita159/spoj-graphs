#include <bits/stdc++.h>
using namespace std;

#define lld long long int
int const N = 200005;
vector<lld> adj[N];
lld visited[N] = {0};
lld flag[N] = {0};

void dfs(int x)
{
    visited[x] = 1;
    for (lld i = 0; i < adj[x].size(); i++)
    {
        if (visited[adj[x][i]] == 0)
        {
            dfs(adj[x][i]);
            if (flag[adj[x][i]] == 1)
            {
                flag[x] = 1;
            }
        }
    }
}
int main()
{
    lld n, k, u, v, cnt = 0;
    cin >> n >> k;
    if (k == 1)
    {
        //if there is only one bus terminal then the buses will have to start and end on the same node
        //hence if will form a cylce and the number of crowded cities will be one less than the number of nodes
        //therefore we don't need to perform any further calculations
        cout << n - 1 << endl;
        return 0;
    }
    for (lld i = 0; i < n - 1; i++)
    {

        cin >> u >> v;
        //Each vector in adj represents a point in a graph.
        //Adding v to adj[v] and v to gadj[u] establishes a connection(vertice, graph edge, or path) between the points.
        //Because we are adding complementary points, this vertice can be used bidirectionally,
        // in other words there is a path from u to v and a path from v to u.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (lld i = 0; i < k; i++)
    {
        cin >> u;
        //all those nodes which are the bus terminals are set to 1 in the flag array
        flag[u] = 1;
        v = u;
    }
    //choose the last node entered which has a bus terminal and perform a depth first traversal
    //and mark the nodes visited from that node to the last node having a bus termial i.e. having flag set to 1
    //this process will set all the nodes in the flag array which are crowded and can be visited (only once) by following the above path 
    dfs(v);
    for (lld i = 0; i <= n; i++)
    {
        //count the number of crowded cities i.e. having flag set
        if (flag[i] == 1)
            cnt++;
    }
    cout << cnt;
    return 0;
}