#include <iostream>
#include <vector>
#include <algorithm>

#define N 200

using namespace std;

typedef struct number
{
    int value;
    int order;
}Num;

bool Compare(Num x,Num y)
{
    return x.value < y.value; 
}


int main()
{
    int n,x;
    Num temp;
    vector<Num> nums;

    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> temp.value;
            temp.order = i;
            nums.push_back(temp);
        }

        cin >> x;

        sort(nums.begin(),nums.end(),Compare);

        

        
        
     }
    




    return 0;
}