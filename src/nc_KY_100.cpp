#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

#define maxn 10

using namespace std;


int main()
{
    int n;
    int rcount = 0;
    int index=0;
    string tstr;

    vector<string> rote[maxn];

    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            cin >> tstr;   //保存n个路径
            rote[i].push_back(tstr);
        }
        sort(rote, rote+n);  //将n个路径排序

        for(int i=0; i<n; i++)
        {
            int j;
            tstr = rote[i][0];
            rote[i].clear();
            while (j<tstr.size())   //拆分各个路径  
            {
                if( (index=tstr.find('\\',j) ) != string::npos)
                {
                    rote[i].push_back(tstr.substr(j,index-j));
                    j = index+1;
                }
                else
                {
                    rote[i].push_back(tstr.substr(j,tstr.size()-j));
                    break;
                }
            }
        }

        for (int i = 0; i < rote[0].size(); i++)  //打印第一组路径
        {
            for (int k = 0; k < i ; k++)
                cout << " ";
            cout << rote[0][i] << endl;
        }

        for(int i=1; i<n; i++)
        {
            
        }
            


    }


    return 0;
}
