#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	
	vector<int> ch(n);
	vector<int> d(n);
	
	for(int i=0; i<n;i++)
	{
		scanf("%d",&ch[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		d[i] = i+1;
		for(int j=0;j<i;j++)
		{
			if(ch[i] > ch[j]) d[i]--;
		}
	}
	for(int i=0; i<n;i++)
	{
		printf("%d ",d[i]);
	}
	return 0;	
}
