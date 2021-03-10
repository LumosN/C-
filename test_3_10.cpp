#include<iostream>
#include<stdio.h>
using namespace std;
int getMonthDay(int year, int month)
{
    int daysArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = daysArray[month];
    if(((year%4==0&&year%100!= 0)||year%400 == 0)&&month == 2)
    {
        days = 29;
    }
    return days;
}
int main()
{
    int year, month = 1, day;
    int n;
    while(cin>>year>>n)
    {
        day = n;
        while(day > getMonthDay(year, month))
        {
            day -= getMonthDay(year, month);
            month++;
            if(month == 13)
            {
                month = 1;
                year++;
            }
        }
        if(month<10)
        {
            if(day<10)
            {
                printf("%d-0%d-0%d",year,month,day);   
            }
            else
            {
                printf("%d-0%d-%d",year,month,day);
            }
        }
        else
        {
            if(day<10)
            {
                printf("%d-%d-0%d",year,month,day);
            }
            else
            {
                printf("%d-%d-%d",year,month,day);
            }
        }
    }
    return 0;
}
