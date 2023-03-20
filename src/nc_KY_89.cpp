#include <iostream>
#include <cstdio>
#include <algorithm>

#define N 100

using namespace std;

typedef struct anti{
    int index;
    int speed;
    int aflag;

}anti;

void anti_move(anti *p)
{
    p->index += p->speed;
}

void anti_two(anti *p1, anti *p2)  //两只蚂蚁碰头
{
    swap(p1->speed,p2->speed);
}

void anti_three(anti *p1, anti *p2, anti *p3) // 三只蚂蚁碰头
{
    if(p1->speed == 0)
        swap(p2->speed,p3->speed);
    if(p2->speed == 0)
        swap(p1->speed,p3->speed);
    if(p3->speed == 0)
        swap(p1->speed,p2->speed);
}

int main()
{
    int sum;
    int clock=0;
    anti ants[N];
    bool afail = false;

    scanf("%d", &sum);

    for(int i=0; i<sum; i++)
    {
        scanf("%d %d", &ants[i].index, &ants[i].speed);
        if(ants[i].speed == 0)
            ants[i].aflag=1;
        else
            ants[i].aflag=0;
    }


    while(++clock)
    {
        for(int i=0; i<sum; i++)
            anti_move(&ants[i]);

        for(int i=0; i<sum; i++)
        {
            if(ants[i].index == 0 && ants[i].index == 100)  //删除掉落的蚂蚁
            {
                if(ants[i].aflag == 1)         //检查掉落的蚂蚁是否是A
                {
                    afail = true;
                    break;
                }
                else if(i <= sum-1)
                {
                    if(i<sum-1)
                    {
                        ants[i].index = ants[sum-1].index;
                        ants[i].speed = ants[sum-1].speed;
                        ants[i].aflag = ants[sum-1].aflag;
                    }
                    sum--;
                    i--;
                }
            }
        }


        //检查是否有碰头
        bool tt_flag = true;

        for(int i=0; i<sum; i++)
            for(int j=i+1; j<sum; j++)
            {
                if(ants[i].index == ants[j].index)
                {
                    for(int k=j+1; k<sum; k++)
                    {
                        if(ants[k].index == ants[j].index)
                        {
                            anti_three(&ants[i],&ants[j],&ants[k]);
                            tt_flag = false;
                        }
                    }
                    if(tt_flag)
                        anti_two(&ants[i],&ants[j]);
                }
            }

        if(afail == true)
        {
            cout << clock << endl;
            break;
        }

        if(sum == 1)
        {
            cout << "Cannot fail!" << endl;
            break;
        }

    }

    return 0;
}
