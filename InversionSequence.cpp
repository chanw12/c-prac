#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int N,cnt=0;
	int arr[101];
	int inversion[101];
	cin >> N;
	for (int i = 1; i <= N; i++) { arr[i] = INT_MAX; }
	
	for (int c = 1; c <= N; c++)
	{
		cin >> inversion[c];
	}
	for (int i = 1; i <= N; i++)
	{
		cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (cnt == inversion[i] && i < arr[j])
			{
				arr[j] = i;
				break;
			}
			if (i < arr[j])cnt++;
			
		}
	}

	for (int i = 1; i <= N; i++) { cout << arr[i] << " "; }
	return 0;
}



