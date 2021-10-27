#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int A[11];
	int B[11];
	int winner=0;
	int APnt = 0, BPnt = 0;
	for (int i = 0; i < 10; i++) cin >> A[i];
	for (int i = 0; i < 10; i++) cin >> B[i];
	int i = 0;
	while (i<=9)
	{
		if (A[i] > B[i])
		{
			APnt += 3;
			winner = 1;
		}
		else if(A[i] < B[i])
		{
			BPnt += 3;
			winner = 2;
		}
		else
		{
			APnt++; BPnt++;
		}
		i++;
	}
	cout << APnt << " " << BPnt << endl;
	if (APnt == BPnt)
	{
		if (winner == 1)
			cout << "A";
		if (winner == 2)
			cout << "B";
		if (winner == 0)
			cout << "D";
	}
	else if (APnt > BPnt)
	{
		cout << "A";
	}
	else
		cout << "B";


	return 0;
}

