// SEtestone.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;


bool isNum(string str)
{
	//if (str == "") return false;
	stringstream temp(str);
	double d;
	char c;
	if (!(temp >> d))
		return false;
	if (temp >> c)
		return false;
	return true;
}


int main()
{
	//vector<int> intVec;
	//int n = 10;//最多输入100个数
	//while (n!=0)
	//{
	//	int num;
	//	cin >> num;
	//	intVec.push_back(num);
	//}
	int num = 0;
	string numStr; vector<double> numVec;
	//cin >> numStr;
	while (getline(std::cin, numStr))
	{
		//getline(std::cin, numStr);
		//vector<string> initVec(5);
		istringstream iss(numStr), end;
		//copy(istream_iterator<string>(iss), istream_iterator<string>(end), initVec.begin());
		std::istream_iterator<std::string> Itbegin = std::istream_iterator<std::string>(iss);
		std::istream_iterator<std::string> ItEnd = std::istream_iterator<std::string>();
		//vector<string> initVec(istream_iterator<string>(iss), istream_iterator<string>(end));
		vector<string> initVec(Itbegin, ItEnd);


		for (auto s : initVec)
		{
			if (isNum(s))
			{
				double d = stod(s);
				//cout << d;
				if (d == -999)
					goto f;
				numVec.push_back(d);
				num++;
				if (num == 10)
				{
					goto f;
				}
			}

		}
	}
f:	sort(numVec.begin(), numVec.end());
	for (auto s : numVec)
	{
	cout << s << " ";
	}
	
	int n1;
	int n2;
	cout << "请输入上下界" << endl;
	cin >> n1 >> n2;
	cout << "n1和n2分别是" << n1 << " " << n2 << endl;
	//找出指定范围内的数
	//vector<double> tempVec;
	//decltype(numVec.begin()) iter1;
	//decltype(numVec.begin()) iter2;
	//vector<double>::iterator iter1, iter2;
	int iter1=0, iter2=numVec.size();
	bool first1 = false;
	bool first2 = false;
	for (auto iter = numVec.begin()	; iter !=numVec.end(); iter++)
	{
		if (*iter>=n1&&!first1)
		{
			iter1 = iter-numVec.begin();
			cout << "iter1" << iter1<<" "<<*iter << endl;
			first1 = true;
		}
		if (*iter>n2&&!first2)
		{
			iter2 = iter-numVec.begin();
			cout << "iter2" << iter2 << endl;
			first2 = true;
			break;
		}
	}
	
	//vector<double> tempVec(iter1, iter2);
	//auto iterfirst=(numVec.begin()+iter1)
	vector<double> tempVec(numVec.begin() + iter1, numVec.begin() + iter2);
	double sum = 0;
	double average = 0;
	for (auto e : tempVec)
	{
		cout << e << " ";
		//}
		sum += e;

	}
	average = sum / tempVec.size();
	cout << "总和" << sum << endl;
	cout << "均值" << average << endl;
	return 0;
}

