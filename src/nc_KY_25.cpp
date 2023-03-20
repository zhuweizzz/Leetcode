#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;



int main()
{
    int L,M; //L总长度，M区间个数

    int tstart=0,tend=0;

    map<int,int> regin;
    
    map<int,int>::iterator iter;
    map<int,int>::iterator next;
    
    int sum=0;

    while(scanf("%d",&L) != EOF)
    {
        scanf("%d",&M);
        sum =0;

        while(M--)
        {
            scanf("%d %d", &tstart, &tend);

            regin.insert({tstart,tend});
        }

        iter = regin.begin();

        while(iter != regin.end())
        {

            next = iter;
            if(++next == regin.end())
                break;
            if(next->first <= iter->second)
            {
                if(next->second > iter->second)
                    iter->second = next->second;
                regin.erase(next);
            }
            else
                iter++;
        }

        for(map<int,int>::iterator iter= regin.begin() ; iter != regin.end(); iter++)
        {
            sum+= iter->second - iter->first +1;
        }

        printf("%d\n", L+1-sum);
    }


    return 0;
}
