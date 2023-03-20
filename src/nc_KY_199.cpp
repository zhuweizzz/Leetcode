#include <iostream>
#include <cstdio>

#include <algorithm>

#define N 100

using namespace std;

bool binarySearch(int* arr , int target , int length)  //二分查找
{
    int left=0, right = length-1;
    int middle;
    while (left <= right)
    {
        middle = (left + right)/2;
        if(target > arr[middle])
            left = middle+1;
        else if(target < arr[middle])
            right = middle-1;
        else
            return true;
    }
    return false;
}



int main()
{
    int n,m;
    int nums[N];
    int target;

    while (cin >> n)
    {
        for(int i=0; i<n; i++)
            cin >> nums[i];

        sort(nums,nums+n);

        cin >> m;

        for(int i=0; i<m; i++)
        {
            cin >> target;
            if(binarySearch(nums,target,n))
                cout << "YES" <<endl;
            else
                cout << "NO" <<endl;
        }   
        
    }

    return 0;
}