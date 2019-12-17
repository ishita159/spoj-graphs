#include <bits/stdc++.h>
using namespace std;

// path to be checked is stored globally in string S 
string S;
// adjacency matrix of the graph from which we will check 
bool adj[10][10];

//  array to store the resulted path - way
char result[100005];

// we apply breadth first search to look if the string is present in the grapg in the given order
bool findthepath(string S, int v)
{
    result[0] = v + '0';
    for (int i = 1; S[i]; i++)
    {

        // first traverse the outer graph
        if (adj[v][S[i] - 'A'] || adj[S[i] -
                                      'A'][v])
        {
            v = S[i] - 'A';
        }

        // then traverse the inner graph
        else if (adj[v][S[i] - 'A' + 5] ||
                 adj[S[i] - 'A' + 5][v])
        {
            v = S[i] - 'A' + 5;
        }

        // if the condition failed to satisfy
        // return false
        else
            return false;

        result[i] = v + '0';
    }

    return true;
}
\
int main()
{
    // here we have used adjacency matrix to make
    // connections between the connected nodes
    adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] =
        adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] =
            adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] =
                adj[9][6] = adj[6][8] = adj[8][5] = true;

    //input the path to be checked 
    cin >> S;

    // Determine whether there is a walk  which realizes a given string S in graph , 
    //and if so then find the lexicographically least such walk. 
    //The only line of input contains one string S.
    // If there is no walk W which realizes S, then output -1 otherwise,
    //weou should output the least lexicographical walk W which realizes S.
    if (findthepath(S, S[0] - 'A') ||
        findthepath(S, S[0] - 'A' + 5))
    {
        cout << result;
    }
    else
    {
        cout << "-1";
    }
    return 0;
}
