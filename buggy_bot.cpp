
#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
const long long int MAX = 1000005;
set<int> v[MAX], temp[MAX], ans;
int pos[MAX], ix[MAX], iy[MAX], ee[MAX];

int main()
{   // n -> nodes, m -> edges, k -> instructions
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    //we have used an array of set to stroe the edges because the graph won't contain multiple edges — (xi,yi) != (-xj, yj) for each i != j
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        //the is an edge from x to the value stored at x i.e. y    x----y
        v[x].insert(y);
    }
    // arrays ix[] and iy[] is used to store the instructions
    // i denotes the ith second
    // they are used to represent that for each ith second there is an instruction to go from node ix[i] to iy[i];
    for (int i = 0; i < k; i++)
    {
        cin >> ix[i] >> iy[i];
    }


    int cp = 1; //we have set cp to 1 because the path we have to traverse in the graph will start from node valued 1
    pos[0] = 1;

    for (int i = 0; i < k; i++)
    {
        // cp will store the value of the node from where the next instruction should start
        if (cp == ix[i])
            cp = iy[i];
        // after execution of the ith instruction pos[] will store what should be the value of the node where it will finally end up
        pos[i + 1] = cp;
    }

    for (int i = 1; i <= n; i++)
    {
        ee[i] = i;
    }
    // currently the set, ans will store the final value to the node wich we will reach after execution of all the instructions 
    ans.insert(pos[k]);
    for (int i = k - 1; i >= -1; i--)
    {
        int cnode = pos[i + 1];
        //range based loop to run the loop for just that particular value 
        // in this case it will run for each valid node which can be a final node
        for (int j : v[cnode])
        {
            //insert the node having an edge from cnode to the set ans
            ans.insert(ee[j]);
            //it is a blackward process where we are storing the final node of each edge as index and begining node as the value at that index
            temp[j].insert(cnode);
        }

        //empty the set
        v[cnode].clear();

        if (i >= 0)
        {
            //value at index pointed by the value of the first node ith instruction
            //is changed to the value at index pointed by the value of the destination node of the ith instruction
            ee[ix[i]] = ee[iy[i]];
            //if there is a vlaue stored at temp[ix[i]] then insert the value of the beginning node of the ith instructioon at the jth index of v set of edegs
            //this gives us the active graph after completion of the major loop
            for (int j : temp[ix[i]])
            {
                v[j].insert(ix[i]);
            }
            //now clear the value at that index in temp set for new value to replace it
            temp[ix[i]].clear();
        }
    }
    //the set ans now after the termination of the above statements stores only the nodes that can be the final nodes 
    //size of ans set gives us the number of final nodes we can get after the traversal ends
    cout << ans.size() << endl;
    // store all the elements of the set answer in a vector array to be able to sort them all
    vector<int> tmp(ans.begin(), ans.end());
    //sort the vector array and print the elements
     sort(tmp.begin(), tmp.end());
    for (int i : tmp)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
