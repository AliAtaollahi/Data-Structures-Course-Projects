#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
    int commonDivisor = 0;
    if (str1.size() < str2.size()) {
        swap(str1, str2);
    }
    for (int i = 0; i < str2.size(); i++)
    {
        if (str2.size() % (i + 1) == 0 && str1.size() % (i + 1) == 0) {
            bool check = true;
            string divisor = str2.substr(0,i+1);
            for (int j = 0; j < str2.size()/(i+1); j++)
            {
                for (int z = 0; z < divisor.size(); z++)
                {
                    if (divisor[z] != str2[j * divisor.size() + z]) {
                        check = false;
                        break;
                    }
                }
            }
            if (check) {
                for (int j = 0; j < str1.size() / (i + 1); j++)
                {
                    for (int z = 0; z < divisor.size(); z++)
                    {
                        if (divisor[z] != str1[j * divisor.size() + z]) {
                            check = false;
                            break;
                        }
                    }
                }
            }
            if (check) commonDivisor++;
        }
    }
    cout << commonDivisor;
	return 0;
}