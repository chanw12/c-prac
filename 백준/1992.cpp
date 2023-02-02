#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<map>
#include<queue>

using namespace std;
int cnt1, cnt2, cnt3;

string v[65];
string k;
void check(int n,int x,int y)
{
	bool flag = false;
	int s;
	if (n == 1)
	{
		if (v[y][x] == '1')
			k += "1";
		else
			k += "0";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			if (j == 0 && i == 0)
				s = v[y + j][x+i];
			if (v[y + j][x + i] != s)
			{
				flag = true;
				k += "(";
				break;
			}
			
		}
		if (flag)
			break;
		
	}
	if (flag)
	{
		check(n / 2, x, y);
		check(n / 2, x + n / 2, y);

		check(n / 2, x, y + n / 2);
		check(n / 2, x + n / 2, y + n / 2);
		k += ")";

	}
	else
	{
		if (s == 49)
		{
			k += "1";
		}
		else {
			k += "0";
		}
	}
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int x = 0;
	int y = 0;
	check(n, x, y);
	cout<<k<<endl;




	


	return 0;
}
