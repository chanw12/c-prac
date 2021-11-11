#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int s, n;
	int arr[1001];
	int cache[11] = { 0, };
	cin >> s >> n;
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	for (int i = 0; i < n; i++)
	{
		for (int j = s-1; j >0; j--)
		{
			cache[j] = cache[j-1];	
		}
		for (int j = 0; j < s; j++)
		{
			if (cache[j] == arr[i])
			{
				for (int c = j; c<s; c++)
				{
					cache[c] = cache[c + 1];
				}
			}
			cache[0] = arr[i];
		}

	}
	for (int i = 0; i < s; i++)
		cout << cache[i] << " ";

	
	return 0;
}


