#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> len(n);
	for (int i = 0; i < n; i++) { cin >> len[i]; }
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += len[i];
	}


	

	int left = 0, right = sum;
	int h = 1000000;
	while (left <= right)
	{
		int sum = 0;
		int cnt = 1;
		int mid = (left + right)/2;

		for (int i = 0; i < n; i++)
		{
			if (mid == 0)
				break;
			sum += len[i];
			if (sum > mid)
			{
				i--;
				sum = 0;
				cnt++;
			}
		}
		if (mid == 0)
			break;

		if (cnt < m)
		{
			right = mid - 1;
			h = min(h, mid);
		}
			
		else if (cnt == m)
		{
			h = min(h, mid);
			right = mid - 1;
		}
		else
		{
			left= mid +1;
			
		}

	}
	cout << h << endl;
	
}


