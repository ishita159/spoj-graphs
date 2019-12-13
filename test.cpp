#include <iostream>
#include <vector>
#include <map>
using namespace std;
//Driver
int main()
{
    // Iterating over whole array
    vector<int> v;
    for(int i = 0; i < 5; i++)
    {
        v[i] = i;
    }

    for (int i : v[2])
        cout << i << ' ';
    return 0;
}

