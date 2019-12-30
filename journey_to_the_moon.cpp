#include <iostream>
#include <list>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <cmath>

#define MAX 100000

using namespace std;

list<int> *ad;
int *visited;
int vertices;

void DFS(int u)
{
    visited[u] = 1;
    //increment vertices because each time this fucntion executes
    //it means that there is a vertext connected to that vertex 
    //hence it helps in determining a chain of connected veritces because all connected vertices(astronauts) 
    //belong to the same country
    vertices++;

    list<int>::iterator it;

    for (it = ad[u].begin(); it != ad[u].end(); it++)
    {
        if (visited[*it] == 0)
        {
            //setting visited as 1 will also ensure that in the main faunction while calculating the
            visited[*it] = 1;
            //perform a dfs for that node also to get to all the connectd nodes (to get people from the same country)
            DFS(*it);
        }
    }
}

int main()
{
    int i, m, u, v, numComponents = 0;
    //numComponents will store the number of countries
    long long int n;
    int eachC[MAX];
    //get the Astronauts and the number of pairs avaliable (people from the same country)
    cin >> n >> m;
    //if n ==1 then no pair can be formed hence we will retrun 0
    if (n == 1)
    {
        cout << "0\n";
        return 0;
    }

    //we will store the astronaut's IDs as the vertices
    //To compute how many different countries are there we will calculate how many different connected components are present
    // in the graph where the vertices are represented by the astronaut's IDs
    //and theastronauts from the same country form one connected component

    list<int> ad[n];

    list<int>::iterator it;
 
    //create the adjacency list
    for (i = 0; i < m; i++)
    {
        cin >> u >> v;

        ad[u].push_back(v);
        ad[v].push_back(u);
    }

    int visited[n];
    //set all the visited nodes as 0 initially
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    //we apply Depth First Search to calculate how many different connected components are present

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            vertices = 0;
            DFS(i);
            //we use array eachC[] to store number of people who belong to the same country
            eachC[numComponents] = vertices;
            numComponents++;
        }
    }
    //the total no of ways of pairing the astronauts will be nC2 if we dont consider the  same country constraint
    long long int totalWays = n * (n - 1) / 2;
    long long int sameWays = 0;
    //to calculate the rudendent methods we calculate the total pairs people for the same city can form
    //we keep on adding that value to the variable "sameWays" for each country
    for (i = 0; i < numComponents; i++)
    {
        sameWays = sameWays + (eachC[i] * (eachC[i] - 1) / 2);
    }
    //after we have found the total sum of all the pairs of the same country, we will subtract it from the totalWays 
    //to get the no of pairs we came form by combining astronauts not belongning to the same country
    cout << (totalWays - sameWays) << endl;
    return 0;
}