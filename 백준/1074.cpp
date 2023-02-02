#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
int N, r, c,i,j,cnt=0;


int box(int a,int r,int c)
{
	if (a == 2)
	{
		if (r == 0 && c == 0)return 1;
		else if (r == 0 && c == 1)return 2;
		else if (r == 1 && c == 0)return 3;
		else return 4;
		
	}
	else
	{
		a = a / 2;
		int sum=0;
		if (r <= a - 1 && c <= a - 1) sum = 0;
		else if (r <= a - 1 && c > a - 1)
		{
			c = c - (a);
			sum = a * a;
		}
		else if (r > a - 1 && c <= a - 1)
		{
			r = r - (a);
			sum = 2 * (a * a);
		}
		else
		{
			c = c - (a);
			r = r - (a);
			sum = 3 * (a * a);
		}
		return sum + box(a, r, c);
	}
	
}


int main() {

	scanf("%d %d %d", &N, &r, &c);
	int k = box(pow(2, N), r, c);
	printf("%d", k-1);
	return 0;
}