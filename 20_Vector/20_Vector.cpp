#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>v1, vector<int>v2)
{
	cout << "Vector1: " << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";

	}
	cout << endl;
	cout << "Vector2" << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";

	}

}
int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int>v2 = { 10,11,12,13,14 };

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";

	}
	cout << endl;
	v[0] = 55;
	for (auto item: v)
	{
		cout << item << " ";
		item = 0;
	}
	cout << endl;
	for (auto i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	int a = 5;
	auto b = 6;
	auto c = 3.33;
	float d = 1.25;

	PrintVector(v, v2);
	v.erase(v.begin());
	PrintVector(v, v2);
	v.erase(v.end()-1);
	PrintVector(v, v2);

	v.shrink_to_fit();

	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl;
	v.erase(v.begin(), v.end() - 4);
	PrintVector(v, v2);

	v.insert(v.begin(), 55);
	PrintVector(v, v2);
	v.insert(v.end(), { 7,8,9,10 });
	PrintVector(v, v2);
	v.insert(v.begin() + 2, 5, 44);
	PrintVector(v, v2);
	v.insert(v.end(), v2.begin() + 1, v2.end() - 2);
	PrintVector(v, v2);

	v.push_back(100);
	v.pop_back();

	//v.swap(v2);
	PrintVector(v, v2);

	cout << "Show first element: " << v.front() << endl;
	cout << "Show last element: " << v.back() << endl;

	v.resize(70);

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]==7)
		{
			v.insert(v.begin() + i+1, 7);
		}

	}
	PrintVector(v, v2);


}