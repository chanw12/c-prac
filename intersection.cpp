#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	int n, m;
	int a[30001], b[30001];
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	cin >> m;
	for (int i = 0; i < m; i++) { cin >> b[i]; }
	int newarr[30001];
	sort(a, a + n);
	sort(b, b + m);
	int pos = 0;
	int i = 0;
	int j = 0;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
			i++;
		else if (a[i] == b[j])
		{
			newarr[pos++] = a[i++];
			j++;
		}
		else
			j++;

	}
	for (int i = 0; i < pos; i++)
	{
		cout << newarr[i] << " ";
	}
	return 0;
	
}


