#include <iostream>
#include <vector>
#include <set>

using namespace std;

class solution {

public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> snum;
        for(auto a = nums.begin(); a != nums.end(); a++ )
        {
            snum.insert(*a);
        }
        if(snum.size() != nums.size())
            return true;
        else 
            return false;
    }
};

int main()
{
    vector<int> nums={1, 5, 6, 10, 11};
    solution prob;
    
    return prob.containsDuplicate(nums);

}