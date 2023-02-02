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

int v[3000][3000];
void check(int n,int x,int y)
{
	bool flag = false;
	int s;
	if (n == 1)
	{
		if (v[x][y] == 1)
			cnt3++;
		else if (v[x][y] == 0)
			cnt2++;
		else
			cnt1++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			if (j == 0 && i == 0)
				s = v[x+i][y+j];
			if (v[x + i][y + j] != s)
			{
				flag = true;
				break;
			}
			
		}
		
	}
	if (flag)
	{
		check(n / 3, x, y);
		check(n / 3, x + n / 3, y);
		check(n / 3, x + n / 3 * 2, y);

		check(n / 3, x, y + n / 3);
		check(n / 3, x + n / 3, y + n / 3);
		check(n / 3, x + n / 3 * 2, y + n / 3);
		check(n / 3, x, y + n / 3 * 2);
		check(n / 3, x + n / 3, y + n / 3 * 2);
		check(n / 3, x + n / 3 * 2, y + n / 3 * 2);

	}
	else
	{
		if (s == -1)
			cnt1++;
		else if (s == 0)
			cnt2++;
		else
			cnt3++;
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
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	int x = 0;
	int y = 0;
	check(n, x, y);
	

	cout << cnt1 << endl;
	cout << cnt2 << endl;
	cout << cnt3 << endl;




	


	return 0;
}
