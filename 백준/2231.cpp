#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {
	
	int N;
	bool find = true;
	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int temp = i;
		int tempsum = i;
		while (temp >0)
		{
			
			tempsum += (temp%10);
			temp /= 10;
		}
		if (tempsum == N)
		{
			cout << i << endl;
			find = false;
			break;
		}

	}
	if (find)
		cout << 0 << endl;
	
	return 0;
}
