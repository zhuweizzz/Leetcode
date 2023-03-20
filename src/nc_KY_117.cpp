#include <iostream>
#include <algorithm>


#define N 10

using namespace std;


typedef struct country
{
    int golds;  //金牌
    int rewards;//奖牌
    int people; //人口

    int r1,r2,r3,r4; //四种方式的排名
}cty;

bool g_Compare(cty x, cty y)
{
    return x.golds > y.golds;
}

bool r_Compare(cty x, cty y)
{
    return x.rewards > y.rewards;
}

bool pg_Compare(cty x, cty y)
{
    return 1.0*x.golds/x.people > 1.0*y.golds/y.people;
}

bool pr_Compare(cty x, cty y)
{
    return 1.0*x.rewards/x.people > 1.0*y.rewards/y.people;
}

int main()
{
    int t,n,m; //国家数，排名国家数

    bool flag[N];
    cty ctrys[N];

    while (cin >> n)
    {
        cin >> m;

        for (int i = 0; i < n; i++)
            cin >> ctrys[i].golds >> ctrys[i].rewards >> ctrys[i].people;
        
        for (int i = 0; i < m; i++)
        {
            cin >> t;
            flag [t] = true;
        }

        sort(ctrys, ctrys+n, g_Compare); //

        
        

        



    }
    

    

    return 0;
}