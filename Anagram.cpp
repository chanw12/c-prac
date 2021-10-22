#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	char str[101];
	char str2[101];
	int cnt1=0;
	int cnt2=0;
	bool flag = true;
	cin >> str;
	cin >> str2;
	for (int i = 0; str[i] != '\0'; i++)
	{
		cnt1++;
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		cnt2++;
	}
	sort(str,str+cnt1);
	sort(str2, str2 + cnt2);

	for (int i = 0; i < cnt1 || i < cnt2; i++)
	{
		if (str[i] != str2[i])
		{
			flag = false;
			break;
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";
	



	return 0;
}


