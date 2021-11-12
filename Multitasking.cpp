#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++) { cin >> v[i]; }
	int k;
	cin >> k;
	int i = 1;
	int rst;
	int count = 0;
	for (int t = 1; t <= k+1; t++,i++)
	{
		if (v[i] != 0)
		{
			if (t == k + 1)
			{
				rst = i;
				break;
			}
			v[i]--;
			if (v[i] == 0)
			{
				count++;
			}
		}
		else
		{
			t--;
		}
		
		if (i + 1 > n)
			i = 0;
		if (count == n)
		{

		}


	}
	sort(v.begin(), v.end());
	if (v[n] == 0)
		rst = -1;

	cout << rst << endl;

	return 0;
}

