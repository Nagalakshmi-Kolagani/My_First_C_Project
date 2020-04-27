#include<stdio.h>
#include<conio.h>
int main(){
	int date,n,mc,yc,century,result,year,month,result1;
	int a[12]={1,4,4,0,2,5,0,3,6,1,4,6}; //code that is used months
	int b[4]={0,6,4,2}; //code that is used for years
	int c[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //no of days in months
	int i,days,start;
	int Month,Year,TRUE;
	//textcolor(WHITE);
	//clrscr();
	printf("\n\tThis program shows calendar of \n");
	printf("\n\ta given month. Enter month, year...format is mm-yyyy.\n");
	/* taking input */
	while(1)
	{
	//fflush(stdin);
	printf("\n\n\tEnter dd-mm-yyyy: ");
	scanf("%d-%d-%d",&date,&Month,&Year);
	// Doing all kind of validations here
	if(Year < 0)
    {
	printf("\nInvalid year value...");
	continue;
    }
    if(Year < 100)
	Year += 1900;
    if(Year < 1582 || Year > 4902)
    {
	printf("\nInvalid year value...");
	continue;
    }
    if(Month < 1 || Month > 12)
    {
	printf("\nInvalid month value...");
	continue;
    }
    if(date<0||date>31) {
    printf("invalid date value......");
    continue;
    }
    break;
	}
	month=Month;
	year=Year;
	century=year/100+1; //calculating to which century the year belongs to
	n=year%100; //obtaining the last two digits
	yc=b[century%4]; //finding the year code
	mc=a[month-1]; //finding the month code
	result1=(1+yc+mc+n+(n/4))%7; //computing the code for the day of  first day of a month
	result=(date+yc+mc+n+(n/4))%7; //computing the code for the day for given date
	//printf("\n%d %d\n",yc,mc);
	// Checking whether leap year or not
	if(year%4==0&&year%100!=0&&month<3||year%400==0&&month<3){
		c[1]=c[1]+1;
		if(result==0)
		result=result+6;
		else
		result=result-1;
	}
	if(year%4==0&&year%100!=0&&month<3||year%400==0&&month<3){
		if(result==0)
		result1=result1+6;
		else
		result1=result1-1;
	}
	// Obtaining the day based on the code obatined (result)
	if(result==0)
	printf("\nsaturday");
	if(result==1)
	printf("\nsunday");
	if(result==2)
	printf("\nmonday");
	if(result==3)
	printf("\ntuesday");
	if(result==4)
	printf("\nwednessday");
	if(result==5)
	printf("\nthursday");
	if(result==6)
	printf("\nfriday");
	//Printing the Month Calender
	days=c[month-1];
	if(result1==0) {
	      start=result1+7;
	      }
	else
	    {
	      start=result1;
	      }
	      printf("\nSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n");
		 for(i=1;i<=days+start-1;i++){

			      if(i<start)
			      {
				       printf(" \t");
			      }
			      else
			      {
					printf("%d\t",i-start+1);
			      }
			      if((i%7)==0)
			      printf("\n");
			      }
			getch();

	}
