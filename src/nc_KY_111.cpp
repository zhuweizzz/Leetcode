#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

bool ifrun(int y)  //判断润年
{
    if((y % 100 != 0 && y%4 == 0) || (y % 400 ==0) )
        return true;
    return false;
}

int daytable[2][13]={
{0,31,28,31,30,31,30,31,31,30,31,30,31},
{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int main()
{
    char bdata[9];
    char edata[9];

    int by,bm,bd;
    int ey,em,ed;

    int run_flag=0;    //润年标志位

    int samm_flag = 0;   //同月标志位
    int samy_flag = 0;    //同年标志位
    int deta=0;

    while(scanf("%s",bdata)!=EOF)
    {
        getchar();
        scanf("%s",edata);
        sscanf(bdata,"%04d%02d%02d",&by,&bm,&bd);  //使用sscanf解析字符串
        sscanf(edata,"%04d%02d%02d",&ey,&em,&ed);  //使用sscanf解析字符串

        if(by>ey)
        {
            swap(by,ey);
            swap(bm,em);
            swap(bd,ed);
        }
        else if(by == ey)
        {
            samy_flag =1;
            if(bm>em)
            {
                swap(bm,em);
                swap(bd,ed);
            }
            else if(bm == em)
            {
                if(bd>ed)
                    swap(bd,ed);
                samm_flag = 1;
            }
        }

        if(samy_flag  == 1)
        {
            if(ifrun(by))
                run_flag = 1;
            else
                run_flag = 0;

            if(samm_flag ==1)
            {
                //同年同月
                if(bd+1 == ed)
                    deta = 2;
                else
                    deta = ed-bd+1;
            }
            else
            {
                //同年不同月
                for(int i = bm+1; i<em; i++)
                {
                    deta+= daytable[run_flag][i];
                }
                deta+= daytable[run_flag][bm] - bd;
                deta+= ed;
            }
        }
        else
        {      //不同年
            if(ifrun(by))
                run_flag = 1;
            else
                run_flag = 0;

            for(int i = bm+1 ; i<=12; i++)
            {
                deta += daytable[run_flag][i];
            }
            deta += daytable[run_flag][bm] - bd;

            by++;
            while(by<ey)
            {
                if(ifrun(by))
                    deta += 366;
                else
                    deta += 365;
                by++;
            }

            if(ifrun(ey))
                run_flag = 1;
            else
                run_flag = 0;

            for(int i = 0; i<em; i++)
            {
                deta += daytable[run_flag][i];
            }
            deta += ed;
        }
        deta++;
        printf("%d",deta);

    }

    return 0;

}
