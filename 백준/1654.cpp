#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long k, n;
long long cnt;
long long rtn;
long long len[10001];
void countnum(long long left,long long right)
{
	if (left > right)
		return;
	long long mid = (left + right) / 2;
	cnt = 0;

	for (int i = 0; i < k; i++)
	{
		cnt += len[i] / mid;
	}
	if (cnt >= n)
	{
		rtn = max(rtn, mid);
		countnum(mid+1,right);
	}
	if (cnt < n)
	{
		countnum(left, mid - 1);
	}


}


int main() {
	

	cin >> k >> n;



	for (int i = 0; i < k; i++) { cin>> len[i]; }

	sort(len, len+k);
	countnum(1, len[k - 1]);
	cout << rtn;
	return 0;
	
}


