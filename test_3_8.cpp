#include<iostream>
#include<stdio.h>
using namespace std;
int getMonthDay(int year, int month)
{
    static int daysArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysArray[month];
    if(((year%4 == 0&&year%100 != 0)|| year%400 == 0) && month == 2)
    {
        days = 29;
    }
    return days;
}
int main()
{
    int n = 0, m = 0;
    int year, month, day, ret;
    while(cin>>year>>month>>day)
    {
        ret = 0;
        for(int i = 1;i < month; i++)
        {
            int days = getMonthDay(year,i);
            ret += days;
        }
        ret += day; // 将不完整的那个月的天数加上
        cout<<ret<<endl;
    }
    return 0;
}
