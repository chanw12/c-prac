#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int t,j;
	cin >> t;
	int arr[101];
	for (int i = 0; i < t; i++) { cin >> arr[i]; }

	for (int i = 1; i < t; i++)
	{
		int tmp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
				break;
			
		}
		arr[j + 1] = tmp;
		
	}
	for (int i = 0; i < t; i++)
	{
		cout << arr[i];
	}
	return 0;
}


