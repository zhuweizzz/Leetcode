#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> num1; //奇数序列
    vector<int> num2; //偶数序列
    int n;

    while (cin >> n)
    {

        if(n%2 == 0)
            num2.push_back(n);
        else 
            num1.push_back(n);

        for (int i = 1; i < 10; i++)
        {
            cin >> n;
            if(n%2 == 0)
                num2.push_back(n);
            else 
                num1.push_back(n);
        }

        sort(num1.begin(),num1.end(),greater<int>()); //降序排序
        sort(num2.begin(),num2.end());

        for(vector<int>::iterator a = num1.begin(); a != num1.end(); a++)
            cout << *a << " ";
        for(vector<int>::iterator a = num2.begin(); a != num2.end(); a++)
            cout << *a << " ";
        cout << endl;

    }


    return 0;
}