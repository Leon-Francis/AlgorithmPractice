#include<iostream>
#include<string>
#include<stdio.h>
#include<set>
using namespace std;

int valid(int year, int month, int day)
{
	if(year >= 60)
	{
		year += 1900;
	}
	else
	{
		year += 2000;
	}
	if(month > 12 || day > 31)
	{
		return -1;
	}
	bool ren = false;
	if((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
	{
		ren = true;
	}
	switch(month)
	{
		case 2:
			if (ren)
			{
				if (day > 29)
				{
					return -1;
				}
			}
			else
			{
				if (day > 28)
				{
					return -1;
				}
			}
			break;
		case 4:
			if (day > 30)
			{
				return -1;
			}
			break;
		case 6:
			if (day > 30)
			{
				return -1;
			}
			break;
		case 9:
			if (day > 30)
			{
				return -1;
			}
			break;
		case 11:
			if (day > 30)
			{
				return -1;
			}
			break;
	}
	return year * 10000 + month * 100 + day;
}

int main()
{
	string str;
	cin >> str;
	int num_1, num_2, num_3;
	num_1 = (str[0] - '0') * 10 + (str[1] - '0');
	num_2 = (str[3] - '0') * 10 + (str[4] - '0');
	num_3 = (str[6] - '0') * 10 + (str[7] - '0');
	set<int> nums;
	nums.insert(valid(num_1, num_2, num_3));
	nums.insert(valid(num_3, num_1, num_2));
	nums.insert(valid(num_3, num_2, num_1));
	for(set<int>::iterator i = nums.begin(); i != nums.end(); i++)
	{
		if(*i != -1)
		{
			printf("%d-%02d-%02d\n", (*i)/10000, ((*i)%10000)/100, (*i)%100);
		}
	}
	return 0;
}
