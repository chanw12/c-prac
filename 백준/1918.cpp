#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <map>
#include <stack>
using namespace std;

char arr[100];
char result[101];
int parnum = 0;
int resultIndex = 1;
int indexnum = 40;

int main(void)
{

    string input;
    cin >> input;
    stack<char> s;
    string result;

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            result += input[i];
        }
        else if (input[i] == '(')
        {
            s.push(input[i]);
        }
        else if (input[i] == '*' || input[i] == '/')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                char k = s.top();
                s.pop();
                result += k;
            }
            s.push(input[i]);
        }
        else if (input[i] == '+' || input[i] == '-')
        {
            while (!s.empty() && s.top() != '(')
            {
                char k = s.top();
                s.pop();
                result += k;
            }
            s.push(input[i]);
        }
        else if (input[i] == ')')
        {
            while (s.top() != '(')
            {
                char k = s.top();
                s.pop();
                result += k;
            }
            s.pop();
        }
    }
    while (!s.empty())
    {
        if (s.top() != '(' || s.top() != ')')
            result += s.top();
        s.pop();
    }
    cout << result << endl;
}
