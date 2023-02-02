#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<map>
#include<queue>

using namespace std;
int arr[129][129];
int blue;
int white;
void check(int a, int b, int size)
{
	int c;
	bool flag = false;
	for (int i = a; i < a + size; i++)
	{
		for (int j = b; j < b + size; j++)
		{
			if (i == a && j == b)
				c = arr[i][j];
			if (c != arr[i][j])
			{
				flag = true;
				break;
			}

		}
	}
	if (flag)
	{
		check(a, b, size / 2);
		check(a + size / 2, b, size / 2);
		check(a, b + size / 2, size / 2);
		check(a + size / 2, b + size / 2, size / 2);
	}
	else
	{
		if (c == 0)
			white++;
		else
			blue++;
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	check(0, 0, N);
	cout << white << blue << endl;

	return 0;
}
