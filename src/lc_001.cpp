#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> tsmg ={"hello", "world", "from", "vscode"};

    for(string & i : tsmg)
    {
        cout << i << " " ;
    }

    cout << endl;

}