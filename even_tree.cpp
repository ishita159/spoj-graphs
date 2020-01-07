#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> al[105];
bool visit[105];
int n, m;
int ans;
//traverse the tree using dfs
// the dfs function should return the number of vertices in the subtree of which the current node is the root
int dfs(int node)
{
    visit[node] = true;
    int num_vertex = 0;
    for (int i = 0; i < al[node].size(); i++)
    {
        if (!visit[al[node][i]])
        {
            int num_nodes = dfs(al[node][i]);
            if (num_nodes % 2 == 0)
                ans++;
            else
                num_vertex += num_nodes;
        }
    }
    // If a node gets in return an even number of vertices from one of it child then
    //the edge from that node to its child should be removed
    //if the number is odd 
    //add it to the number of vertices that the subtree will have if the current node is the root of it.
    return num_vertex + 1;
}

int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        al[x].push_back(y);
        al[y].push_back(x);
    }
   //root node starts from 1
   
   dfs(1);
   cout << ans;
   return 0;
}