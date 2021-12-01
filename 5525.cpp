#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> makeTable(string pattern)
{
    int len = pattern.size();
    vector<int> table(len, 0);
    int j = 0, i = 1;
    for (; i < len; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            table[i] = ++j;
        }
    }
    return table;
}

int kmp(string pattern, string text)
{
    int cnt = 0;
    vector<int> table = makeTable(pattern);
    int textsize = text.size();
    int patternsize = pattern.size();

    int j = 0;
    for (int i = 0; i < textsize; i++)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = table[j - 1];
        }
        if (pattern[j] == text[i])
        {
            if (j == patternsize - 1)
            {
                //문자열을 찾음
                cnt++;
                j = table[j];
            }
            else
            {
                j++;
            }
        }
    }
    return cnt;
}
int main(void)
{
    int n;
    cin >> n;
    string pattern = "I";
    for (int i = 0; i < n; i++)
    {
        pattern += "OI";
    }
    int m;
    string text;
    cin >> m;
    cin >> text;
    int cnt = kmp(pattern, text);
    cout << cnt << endl;

    return 0;
}