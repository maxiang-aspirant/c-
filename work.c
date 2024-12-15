#include<stdio.h>
int runYear(int year){
	return (year%4==0 && year%100!=0 ||year%400==0  );
}
int dayssince2024(int day,int month,int year){
	int days = 0;
	int start_year = 2024;
	int i=start_year;
	for(i;i<year;i++){
		if (runYear(i)==365)
			days+=365;
		if (runYear(i)==366)
			days+=366;
        }
        int months_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (runYear(year))
		months_days[1] = 29;
	for(int m= 0;m<month;m++){
		days+=months_days[m-1];
	}
	days+=day;
	return days;
}
int main(){
	int day,month,year;
	printf("Please input Year:");
	scanf("%d",&year);
	printf("Please input Month:");
	scanf("%d",&month);
	printf("Please input Day:");
	scanf("%d",&day);
	int status = 2;
	int days =dayssince2024(year, month,day);
	int weekdays_index = (days+status)%7;
	const char* weekdays[]= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Firday","Saturday"};
        printf("The input date is: %s\n",weekdays[weekdays_index]);
        return 0;
}


