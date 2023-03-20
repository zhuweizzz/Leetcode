#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int max;
    int t;

    vector<int> nums;

    while(cin >> N)
    {

        for(int i=0; i<N; i++)
        {
            cin >> t;
            nums.push_back(t);
        }

        sort(nums.begin(),nums.end());
        

        if(nums.size() == 1)
        {
            cout << nums.back() << endl;
            cout << "-1";
        }
        else
        {
            cout << nums.back() << endl;
            nums.pop_back();
            for(vector<int>::iterator a=nums.begin(); a != nums.end(); a++)
                cout << *a << " ";
        }
    }
    
}