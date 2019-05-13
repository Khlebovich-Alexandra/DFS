#include <iostream>
#include <fstream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

void dfs(int index, vector<vector<int>>&matrix, vector<bool>& visit, vector<int>& met, int& count);

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int n;
	in >> n;
	vector<vector<int>> matrix(n);
	vector<bool> visit(n, false);
	vector<int> met(n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp;
			in >> tmp;
			matrix.at(i).push_back(tmp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!visit.at(i))
		{
			dfs(i, matrix, visit, met, count);
		}
	}

	for (int i = 0; i < n; i++)
	{
		out << met.at(i) << ' ';
	}
	//	cout << endl;

	//	system("pause");
	return 0;
}

void dfs(int index, vector<vector<int>>& matrix, vector<bool>& visit, vector<int>& met, int & count)
{
	visit.at(index) = true;
	met.at(index) = ++count;
	for (int i = 0; i < matrix.size(); i++)
	{
		if (matrix.at(index).at(i) == 1 && !visit.at(i))
		{
			dfs(i, matrix, visit, met, count);
		}
	}
}
