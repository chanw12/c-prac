#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> st(n);
	vector<int> f(n,1);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&st[i]);
	}
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i) continue;
			if(st[i] < st[j]) f[i]++;
		}
		
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",f[i]);
	}
	
	return 0;	
}
