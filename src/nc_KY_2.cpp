#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef struct stuent
{
    string name;
    int score;
    int order; //记录输入次序
} stu;

bool Compare_greater(stu x, stu y)  //升序
{
    if( x.score == y.score)
        return x.order < y.order;
    else
        return x.score > y.score; 
}

bool Compare_smaller(stu x, stu y) //降序
{
    if( x.score == y.score)
        return x.order < y.order;
    else
        return x.score < y.score; 
}

int main()
{
    int N;
    int falg; //升序降序标志位
    stu temp;

    vector<stu> stus;

    while (cin >> N)
    {
        cin >> falg;

        stus.clear();

        for(int i=0; i<N; i++)
        {
            cin >> temp.name >> temp.score;
            temp.order = i;
            stus.push_back(temp);
        }

        if(falg)
            sort(stus.begin(),stus.end(),Compare_smaller);
        else
            sort(stus.begin(),stus.end(),Compare_greater);

        for(vector<stu>::iterator a = stus.begin(); a != stus.end(); a++)
            cout << a->name << " " << a->score << endl;
        
    }

    return 0;
}