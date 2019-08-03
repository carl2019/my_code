template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair()
		: first(T1())
		, second(T2())
	{}
	pair(const T1& a, const T2& b)
		: first(a)
		, second(b)
	{}
};

#include <string>
#include <map>
#include <set>

void TestMap()
{
	map<string, string> m;
	m.insert(pair<string, string>("peach", "桃子"));
	m["apple"] = "苹果";
	m.insert(m.find("banan"), make_pair("waterme", "水蜜桃"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("peach", "桃色"));
	if (ret.second)
		cout << "<peach, 桃色>不在map中, 已经插入" << endl;
	else
		cout << "键值为peach的元素已经存在：" << ret.first->first << "--->" <<
		ret.first->second << " 插入失败" << endl;
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	if (1 == m.count("apple"))
		cout << "apple还在" << endl;
	else
		cout << "apple被吃了" << endl;
}

void TestSet()
{
	// 用数组array中的元素构造set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array));
	cout << s.size() << endl;
	// 正向打印set中的元素，从打印结果中可以看出：set可去重
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set中值为3的元素出现了几次
	cout << s.count(3) << endl;
}

#include <vector>
class Solution {
public:
	class Compare
	{
	public:
		// 在set中进行排序时的比较规则
		bool operator()(const pair<string, int>& left, const pair<string, int>& right)
		{
			return left.second > right.second;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		map<string, int> m;
		for (size_t i = 0; i < words.size(); ++i)
			++(m[words[i]]);
		multiset<pair<string, int>, Compare> ms(m.begin(), m.end());
		set<string> s;
		size_t count = 0; // 统计相同次数单词的个数
		size_t leftCount = k;
		vector<string> ret;
		for (auto& e : ms)
		{
			if (!s.empty())
			{
				if (count != e.second)
				{
					if (s.size() < leftCount)
					{
						ret.insert(ret.end(), s.begin(), s.end());
						leftCount -= s.size();
						s.clear();
					}
					else
					{
						break;
					}
				}
			}
			count = e.second;
			s.insert(e.first);
		}
		for (auto& e : s)
		{
			if (0 == leftCount)
				break;
			ret.push_back(e);
			leftCount--;
		}
		return ret;
	}
};