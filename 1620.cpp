#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<map>
using namespace std;

int main() {
	int N, M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	string arr[100001];
	map<string, int> m;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		m.insert(pair<string,int>(temp,i));
		arr[i] = temp;
	}
	
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (isdigit(s[0]))
		{
			int k = stoi(s);
			cout << arr[k - 1] << endl;
		}
		else
		{
			cout << m.find(s)->second+1<<endl;
		}
		
		
	}

	return 0;
}

