#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int i,n,j,tmp;
	scanf("%d",&n);
	
	vector<int> ch(n+1);
	
	for(i=2;i<=n;i++)
	{
		tmp = i;
		j=2;
		while(true)
		{
			if(tmp%j==0)
			{
				tmp = tmp/j;
				ch[j]++;
			}
			else j++;
			if(tmp==1) break;
		}
		
	}
	if(ch[2]<ch[5]) printf("%d",ch[2]);
	else printf("%d",ch[5]);
	return 0;
}
