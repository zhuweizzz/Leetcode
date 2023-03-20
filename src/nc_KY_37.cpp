#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct mouse
{
    int weight;
    string color;
}Mos;

bool Compare(Mos x, Mos y)
{
    return x.weight > y.weight;
}

int main()
{
    vector<Mos> moss;
    int N;
    Mos temp;

    while (cin >> N)
    {
        for(int i=0; i<N; i++)
        {
            cin >> temp.weight >> temp.color;
            moss.push_back(temp);
        }

        sort(moss.begin(),moss.end(),Compare);

        for (vector<Mos>::iterator a = moss.begin(); a != moss.end(); a++)
            cout << a->color <<endl;
    }
    return 0;
}