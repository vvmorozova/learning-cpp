#include "ex01.h"

int main()
{
	map<int, int> nums = {};
	vector<string> ans = {};
	int key;
	while (cin >> key)
	{
		if (nums.find(key) != nums.end())
		{

			ans.push_back("YES");
		}
		else
		{
			ans.push_back("NO");
			nums[key] = 1;
		}
	}
	for (string i : ans)
	{
		cout << i << endl;
	}
}