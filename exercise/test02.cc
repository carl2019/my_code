#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	int a[] = { 1, 2, 3, 4 };
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	v[0] = 10;
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;

	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	return 0;
}

class Solution{
public:
	int singleNumber(vector<int>& nums){
		int value = 0;
		for (size_t i = 0; i < nums.size(); ++i){
			value ^= nums[i];
		}
		return value;
	}
};

string letterMap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz" };

class Solution{
public:
	void combinStr(const string& digits, size_t index, const string& str, vector<string>& strs)
	{
		if (index == digits.size())
		{
			strs.push_back(str);
			return;
		}
		string letters = letterMap[digits[index] - '0'];
		for (size_t i = 0; i < letters.size(); ++i)
		{
			combinStr(digits, index + 1; str + letters[i], strs);
		}
	}
	vector<string> letterCombinations(string digits){
		vector<string> strs;

		if (digits.empty())
			return strs;
		size_t index = 0;
		string str;

		combinStr(digits, index, str, strs);
		return strs;
	}
};









