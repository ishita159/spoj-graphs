#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, degree;
    cin >> nodes;
    int sum = 0;
    for(int i = 0; i < nodes; i++)
    {
        cin >> degree;
        sum += degree;
    }
    if (sum > 2 * (nodes - 1))
    {
        cout << "No";
    }
    else
        cout << "Yes";


    return 0;
}