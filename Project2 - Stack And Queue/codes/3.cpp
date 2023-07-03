#include<iostream>
#include<string>
#include<vector> 
using namespace std;
int main()
{
    string turn;
    cin >> turn;
    vector<pair<int, char>> map;
    int i = 0;
    while (i < turn.size())
    {
        int num = 1;
        while (i + 1 < turn.size() && turn[i] == turn[i + 1])
        {
            num++;
            i++;
        }
        map.push_back({ num, turn[i] });
        i += 1;
    }
    int size = map.size();
    i = 0;
    bool end = false;
    while (true)
    {
        if (map[i % size].first != 0) 
        {
            int votes=map[i % size].first;
            char type = map[i % size].second;
            int j = (i + 1) % size;
            while (votes != 0) 
            {
                if (map[j % size].second != type) {
                    if (votes >= map[j % size].first) {
                        votes -= map[j % size].first;
                        map[j % size].first = 0;
                    }
                    else {
                        map[j % size].first -= votes;
                        votes = 0;
                    }
                }
                j++;
                if (j % size == i % size && map[(j - 1) % size].first == 0) {
                    cout << ((type == 'R') ? "Radiant" : "Dire");
                    end = true;
                    break;
                }
            }
        }
        if (end) break;
        i = (i + 1) % size;
    }
	return 0;
}
