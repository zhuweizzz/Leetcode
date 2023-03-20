#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct student
{
    int number;
    int score;
}stu;

bool Compare(stu x, stu y)
{
    if(x.score == y.score )
        return x.number < y.number;
    else
        return x.score < y.score;
}


int main()
{
    int N;
    stu temp;
    vector<stu> stus;


    cin >> N;

    for(int i=0; i<N; i++)
    {
        cin >> temp.number >> temp.score;
        stus.push_back(temp);
    }

    sort(stus.begin(),stus.end(),Compare);

    for(vector<stu>::iterator a = stus.begin(); a != stus.end(); a++ )
        cout << a->number << " " << a->score << endl;


    return 0;
}