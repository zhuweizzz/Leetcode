#include <iostream>
#include <string>

using namespace std;

int key[] = {
    1,2,3,
    1,2,3,
    1,2,3,
    1,2,3,
    1,2,3,
    1,2,3,4,
    1,2,3,
    1,2,3,4
};

int main()
{
    string str;
    int time=0;

    while(cin >> str)
    {
        time = 0;
        for(int i=0; i<str.size(); i++)
        {
            time += key[str[i] - 'a'];
            if( i!=0 && (str[i] - str[i-1] == key[str[i] - 'a' ] - key[str[i-1] - 'a'] ))
                time += 2;
        }
        cout << time << endl;
    }
}