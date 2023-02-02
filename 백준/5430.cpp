#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<map>
#include<queue>

using namespace std;

void del(vector<int>& v,bool check,int &start,int &end)
{
	if (check)
		start++;
	else
		end--;
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	cin >> test_case;


	for (int t = 0; t < test_case; t++)
	{
		bool check = true;
		vector<int> v;
		string func;
		cin >> func;
		int num;
		cin >> num;
		string k;
		cin >> k;
		int i = 0;
		int temp = 0;
		bool checkf = false;
		while(k[i]!=']' && num!=0)
		{
			if (k[i] >= '0' && k[i] <= '9')
			{
				temp *= 10;
				temp += k[i] - '0';
			}
			if (k[i+1] == ','||k[i+1]==']')
			{
				v.push_back(temp);
				temp = 0;

			}
			i++;
		}
		int start = 0;
		int end = v.size() - 1;
		int cnt = 0;
		while (func[cnt] != '\0')
		{
			if (func[cnt] == 'D' && start>end)
			{
				cout << "error" << "\n";
				checkf = true;

				break;
			}
			else if (func[cnt] == 'D')
			{
				del(v,check,start,end);
			}
			else if (func[cnt] == 'R')
			{
				check = !check;
			}
			cnt++;
		}
		
		if (!checkf)
		{
			if (start>end)
				cout << "[]" << "\n";
			else if (check)
			{
				cout << "[";
				for (int i = start; i <= end; i++)
				{
					
					if (i != end)
					{
						cout << v[i] << ",";
					}
					else
					{
						cout << v[i];
					}
				}
				cout << "]"<<"\n";

			}
			else
			{
				cout << "[";
				for (int i = end; i>=start; i--)
				{
					if (i != start)
					{
						cout << v[i] << ",";
					}
					else
					{
						cout << v[i];
					}
				}
				cout << "]" << "\n";
			}

		}
		
		
	}
	

	return 0;
}
