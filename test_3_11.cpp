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
bool isLeapYear(int year){
    if(year%100!=0&&year%4==0||year%400==0)
        return true;
    return false;
}
int main()
{
    int year1, month1, dayl;
    int year2, month2, day2;
    char num1[9],num2[9];
    while(cin>>num1>>num2)
    {
        int n1 = 0, n2 = 0;
        sscanf(num1,"%4d%2d%2d",&year1, &month1, &dayl);
        sscanf(num2,"%4d%2d%2d",&year2, &month2, &day2);
        for(int i = 0; i<= year1; i++)
        {
            if(isLeapYear(i))
            {
                n1+=366;
            }
            else n1+=365;
        }
        for(int i = 1; i< month1; i++)
        {
            n1+=getMonthDay(year1,i);
        }
        n1+=dayl;
            
        for(int i = 0; i<= year2; i++)
        {
            if(isLeapYear(i))
            {
                n2+=366;
            }
            else n2+=365;
        }
        for(int i = 1; i< month2; i++)
        {
            n2+=getMonthDay(year2,i);
        }
        n2+=day2;
        
        cout<<abs(n1-n2)+1<<endl;
    }
    return 0;
}
