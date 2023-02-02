#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <regex>
#include <stack>
#include <deque>
using namespace std;
int main(void)
{
    string input, bomb_input;
    char s[1000001];
    int index = 0;
    cin >> input;
    cin >> bomb_input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == bomb_input.back())
        {
            bool check = true;
            int temp = index - 1;
            for (int j = bomb_input.size() - 2; j >= 0; j--)
            {
                if (bomb_input[j] != s[temp--])
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                for (int i = 0; i < bomb_input.size() - 1; i++)
                {
                    index--;
                }
                continue;
            }
        }
        s[index] = input[i];
        index++;
    }
    if (index == 0)
    {
        cout << "FRULA" << endl;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}
