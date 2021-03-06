#include<iostream>
#include<stdio.h>
using namespace std;
class Date
{
public:
	int getMonthDay(int year, int month);
	Date operator+(int n);
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	int _year;
	int _month;
	int _day;
};
int Date::getMonthDay(int year, int month)
{
	static int daysArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = daysArray[month];
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
	{
		days = 29;
	}
	return days;
}
Date Date::operator+(int n)
{
	Date ret(*this); //拷贝构造临时
	ret._day += n;
	while (ret._day > getMonthDay(ret._year, ret._month)) //不合法时
	{
		ret._day -= getMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
	}
	return ret;
}
int main()
{
	int n = 0, m = 0;
	int year, month, day;
	cin >> m;
	while (m--)
	{
		cin >> year >> month >> day >> n; //n是天数
		Date d(year, month, day);
		Date ret(d);
		ret = d + n;
		printf("%04d-%02d-%02d\n", ret._year, ret._month, ret._day);
	}
	return 0;
}