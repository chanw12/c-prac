#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;



int main() {
	
	int N;
	double sum = 0;
	int max = 0;
	cin >> N;
	vector<int>  v(N);
	vector<int> num(10000);
	vector<int> maxv(1000);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		sum += v[i];
		

		if (v[i] < 0)
		{
			num[v[i]+5000]++;

			if (num[v[i]+5000] == max)
			{
				maxv.push_back(v[i]);
			}
			else if (num[v[i]+5000] > max)
			{
				max = num[v[i]+5000];
				maxv.clear();
				maxv.push_back(v[i]);
			}
		}
		else
		{
			num[v[i]]++;
			if (num[v[i]] == max)
			{
				maxv.push_back(v[i]);
			}
			else if (num[v[i]] > max)
			{
				max = num[v[i]];
				maxv.clear();
				maxv.push_back(v[i]);
			}
		}

		
	}

	

	sort(v.begin(), v.end());
	sort(maxv.begin(), maxv.end());
	cout << round(sum / N) << endl;
	cout << v[N / 2] << endl;
	if (maxv.size() > 1)
	{
		cout << maxv[1]<<endl;
	}
	else
	{
		cout << maxv[0] << endl;
	}
	cout << v[N - 1] - v[0] << endl;


}
