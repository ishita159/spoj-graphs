#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
int go_immediately_to[110], dist[110];
bool vis[110];
bool isValid(int node)
{
    if (node < 1 || node > 100 || vis[node])
        return false;
    else
        return true;
}
int BFS(int source)
{
    memset(vis, 0, sizeof(vis));
    while (!q.empty())
        q.pop();

    vis[source] = 1;
    q.push(source);
    dist[source] = 0;
    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
        {
            int next_node = go_immediately_to[current_node + i];
            if (isValid(next_node))
            {
                q.push(next_node);
                vis[next_node] = 1;
                dist[next_node] = dist[current_node] + 1;
            }
        }
    }
    if (!vis[100])
        return -1;
    else
        return dist[100];
}
int main()
{
    int i, j, cs, t, u, v;
    cin >> t;
    for (cs = 1; cs <= t; cs++)
    {
        cin >> n;

        for (i = 1; i <= 100; i++)
            go_immediately_to[i] = i;

        //For a snake starting at square i and finishing at j, we can consider that there is no node with index i in the graph.
        //Because reaching node i is equivalent to reaching node j since the snake at node i will immediately take us down to node .
        // The same analogy goes for ladders too.
        //we will keep an array go_immediately_to[] and initialize it like this
        //    if(no snake or ladder starts at node i)
        //       go_immediately_to[i] = i.
        //   else
         //      j = ending node of the snake or the ladder starting at node i.
         //      go_immediately_to[i] = j.

        for (i = 1; i <= n; i++)
        {
            cin >> u >> v;
            go_immediately_to[u] = v;
        }

        cin >> m;

        for (i = 1; i <= m; i++)
        {
            cin >> u >> v;
            go_immediately_to[u] = v;
        }

        //we will now run a standard Breadth First Search(BFS).
        //Whenever we reach a node i, we will consider that we have reached the node go_immediately_to[i] 
        //and then continue with the BFS as usual.

        cout << BFS(1) << endl;
    }
}