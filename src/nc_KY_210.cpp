#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    int m;
    vector<int> num;

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> m;
        num.push_back(m);
    }

    sort(num.begin(),num.end());

    for(vector<int>::iterator a=num.begin(); a != num.end(); a++ )
        cout << *a << " ";

    return 0;
}