/*Hi!
this is the program to
find out the day for a given date.
In this program I am going to comment
after I write the statements.

logic:
  we are using switch-case and case 0 will be Sunday
  case 1 will be Monday and so on.
  the fact that days repeat make it simple!
  after 7 days the 8th day will be again Monday,
  whose index(in switch-case) is same as (8%7)-1.
  so in general we can say index is nothing but
  "(number days till the given date)%7)-1"
  
process:
  1)find the number of days till the given date
  2)find (days%7)-1 which is nothing but index
  3)print day

Happy Reading! ;) */

#include<stdio.h>
#include<conio.h>

 int day,month,year;
 
 int calculate();
 void total_to_day(int);
 
int main()
{
    clrscr();
    char k,l;//redundant; used to store "/" between date.
    int br[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    //to check validity of given date, we need this "br".
    printf("enter any date in the format \"dd/mm/yyyy\"\n");
    scanf("%2d%c%2d%c%4d",&day,&k,&month,&l,&year);
    //assignment to variables
    if(year%4==0&&(year%100!=0||year%400==0))
    br[1]+=1;//if(leap year)Feb_days=29.;
    
    if(day<1||month<1||month>12|| year<1||day>br[month-1])
    printf("invalid date");
    //checks for validity of date
  int total=calculate();//total days till given date.
  total_to_day(total);//prints the day.
  return 0;
}


    
 int calculate()
{
  int yearcount,/*stores number of days before the
  given year*/a,b,c,/*a,b,c are to calculate
   the number of leap years before the given date.*/monthcount;
  a=year/4; b=year/100; c=year/400;
    if((year%4==0&&(year%100!=0||year%400==0))&&(month<=2))
    yearcount=(year-1)*365+a-b+c-1;
    /*if(leap year)
     yearcount = (year-1)*365+(number of leap years)-1
     (because the given year is leap year itself,
      os we should substract the current year).*/
    else
    yearcount=(year-1)*365+a-b+c;
    
    {//this bracket is not related to "else".
  int ar[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<month-1;i++)
    monthcount=monthcount+ar[i];
    }//number of days from start of the year till the given month.
           
  int total=monthcount+day+yearcount;//total days.
  return total;
}//this function calculates the number of days till the given date.



void total_to_day(int total)
{
  
if(total<7)
   {
    switch(total)
   {
    case 0:printf("\n %2d/%2d/%4d is a Sunday!",day,month,year);
    break;
    case 1:printf("\n %2d/%2d/%4d is a Monday!",day,month,year);
    break;
    case 2:printf("\n %2d/%2d/%4d is a Tuesday!",day,month,year);
    break;
    case 3:printf("\n %2d/%2d/%4d is a Wednesday!",day,month,year);
    break;
    case 4:printf("\n %2d/%2d/%4d is a Thursday!",day,month,year);
    break;
    case 5:printf("\n %2d/%2d/%4d is a Friday!",day,month,year);
    break;
    case 6:printf("\n %2d/%2d/%4d is a Saturday!",day,month,year);
    break;
   }
   }
else
   {
  switch(total%7)
  {
    case 0:printf("\n %2d/%2d/%4d is a Sunday!",day,month,year);
    break;
    case 1:printf("\n %2d/%2d/%4d is a Monday!",day,month,year);
    break;
    case 2:printf("\n %2d/%2d/%4d is a Tuesday!",day,month,year);
    break;
    case 3:printf("\n %2d/%2d/%4d is a Wednesday!",day,month,year);
    break;
    case 4:printf("\n %2d/%2d/%4d is a Thursday!",day,month,year);
    break;
    case 5:printf("\n %2d/%2d/%4d is a Friday!",day,month,year);
    break;
    case 6:printf("\n %2d/%2d/%4d is a Saturday!",day,month,year);
    break;
  }
   }
}//this function deduces the day from the number of days.

