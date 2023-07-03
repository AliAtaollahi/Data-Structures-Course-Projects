#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	queue<int> tasklist;
	bool check = true;
	int n, m, player1, player2,i=0,target;
	cin >> n >> m;
	vector<vector<int>*> prisoners;
	vector<int> group1(n, 0), group2(n, 0),isNotChecked(n,1);
	for (int i = 0; i < n; i++) prisoners.push_back(new vector<int>);
	for (int i = 0; i < m; i++)
	{
		cin >> player1 >> player2;
		prisoners[player1 - 1]->push_back(player2 - 1);
		prisoners[player2 - 1]->push_back(player1 - 1);
	}
	while (i < prisoners.size())
	{
		/*for (int k = 0; k < group1.size(); k++)
		{
			cout << (group1[k]?k+1:0) << " " << (group2[k]?k+1:0)<<" "<<isNotChecked[k] << endl;
		}
		cout << endl << endl;*/
		while (!tasklist.empty())
		{
			for (int j = 0; j < prisoners[tasklist.front()]->size(); j++)
			{
				target = prisoners[tasklist.front()]->at(j);
				if (isNotChecked[target]) {
					/*for (int k = 0; k < group1.size(); k++)
					{
						cout << (group1[k] ? k + 1 : 0) << " " << (group2[k] ? k + 1 : 0) <<" "<<isNotChecked[k]<< endl;
					}
					cout << endl << endl;*/
					if (group1[tasklist.front()]) group2[target] = 1;
					else group1[target] = 1;
					tasklist.push(target);
					isNotChecked[target] = 0;
				}
				else if ((group1[tasklist.front()] && group1[target]) || (group2[tasklist.front()] && group2[target])) {
					check = false;
					break;
				}
			}
			//cout << tasklist.size() << "  sdfsdfdsf"<<endl;
			tasklist.pop();
		}
		if (group1[i] || group2[i]) i++;
		else {
			group1[i] = 1;
			isNotChecked[i] = 0;
			for (int j = 0; j < prisoners[i]->size(); j++)
			{
				if (isNotChecked[prisoners[i]->at(j)]) {
					group2[prisoners[i]->at(j)] = 1;
					tasklist.push(prisoners[i]->at(j));
					isNotChecked[prisoners[i]->at(j)] = 0;
				}
			}
		}
	}
	if (check) {
		cout << "Yes" << endl;
		for (int i = 0; i < group1.size(); i++) cout << (group1[i] ? 1 : 0) << " ";
	}
	else cout << "No";
	return 0;
}
