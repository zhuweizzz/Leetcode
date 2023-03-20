#include <iostream>
#include <cstdio>

#define N 1000

using namespace std;

void prtpix(char temp[][N], int n, int t_i, int t_j) //将大小为n*n的temp输出在以t_i,t_j为左上坐标的位置
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
        {
            temp[i+t_i][j+t_j] = temp[i][j];
        }
    return;
}

void prtspx(char temp[][N], int n, int t_i, int t_j) //将大小为n*n的temp输出在以t_i,t_j为左上坐标的位置
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=0;j<n;j++)
        {
            temp[i+t_i][j+t_j] = ' ';
        }
    return;
}



int main()
{
    int n,level,psize=1;
    char pix[N][N];
    char tpix[5][5];
    while(1)
    {
        scanf("%d",&n);
        psize = n;

        if(n==0)
            break;

        getchar();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%c",&pix[i][j]);
                tpix[i][j] = pix[i][j];
            }
            getchar();

        }

        scanf("%d",&level);


        while(--level)
        {

            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                {
                    if(i==0 && j==0)
                    {}
                    else
                    {
                        if(tpix[i][j] !=' ')
                            prtpix(pix, psize , i*psize, j*psize);
                        else if(tpix[i][j] == ' ')
                            prtspx(pix, psize, i*psize, j*psize);
                    }
                }
            if(pix[0][0] == ' ')  //单独处理[0,0]
                prtspx(pix, psize, 0, 0);

            psize*=n;
        }

        for(int i=0; i<psize; i++)
        {
            for(int j=0; j<psize; j++)
                printf("%c",pix[i][j]);
            printf("\n");
        }
        psize=1;

    }

    return 0;
}
