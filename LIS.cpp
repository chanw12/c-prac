#include<stdio.h>

using namespace std;


int main() {
	int n,i,pre,now,cnt=0,max = -2147000000;
	scanf("%d",&n);
	scanf("%d",&pre);
	cnt=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&now);
		if(pre<= now) cnt++;
		else cnt=1;
		if(max<cnt) max = cnt;
		pre = now;
	}
	printf("%d\n",max);
	
}
