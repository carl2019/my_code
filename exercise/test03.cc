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
	m.insert(pair<string, string>("peach", "����"));
	m["apple"] = "ƻ��";
	m.insert(m.find("banan"), make_pair("waterme", "ˮ����"));
	cout << m.size() << endl;
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("peach", "��ɫ"));
	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" <<
		ret.first->second << " ����ʧ��" << endl;
	m.erase("apple");
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	if (1 == m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple������" << endl;
}

void TestSet()
{
	// ������array�е�Ԫ�ع���set
	int array[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	set<int> s(array, array + sizeof(array) / sizeof(array));
	cout << s.size() << endl;
	// �����ӡset�е�Ԫ�أ��Ӵ�ӡ����п��Կ�����set��ȥ��
	for (auto& e : s)
		cout << e << " ";
	cout << endl;
	for (auto it = s.rbegin(); it != s.rend(); ++it)
		cout << *it << " ";
	cout << endl;
	// set��ֵΪ3��Ԫ�س����˼���
	cout << s.count(3) << endl;
}

#include <vector>
class Solution {
public:
	class Compare
	{
	public:
		// ��set�н�������ʱ�ıȽϹ���
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
		size_t count = 0; // ͳ����ͬ�������ʵĸ���
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