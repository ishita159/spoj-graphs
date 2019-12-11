#include <iostream>
using namespace std;
int main()
{
    int nodes, edges, max_connected_components;
    cin >> nodes >> edges >> max_connected_components;
    int x, y;
    for (int i = 0; i < edges; i++)
        cin >> x >> y;
    if (edges - (nodes - max_connected_components) >= 0)
        cout << edges - (nodes - max_connected_components);
    else
        cout << "-1";
}