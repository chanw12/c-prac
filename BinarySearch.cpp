#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


	int main() {
	int n,c;
	cin >> n >> c;
	vector<int> pos(n);
	vector<int> pos1(n);
	for (int i = 0; i < n; i++) { cin >> pos[i]; }
	sort(pos.begin(), pos.end());
	for (int i = 0; i < n-1; i++)
	{
		pos1[i] = pos[i + 1] - pos[i];
	}
	int left = 0,right = pos[n-1];
	int h = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n-1; i++)
		{
			if (sum + pos1[i] >= mid)
			{
				sum = 0;
				cnt++;
			}
			else
			{
				sum += pos1[i];
			}
			if (i == n - 2)
			{
				if (cnt>=c-1)
				{
					left = mid + 1;
					
					h = max(h, mid);
				}
				else
				{
					right = mid - 1;

				}
			}

		}




	}
	cout << h;
	return 0;
	
}





