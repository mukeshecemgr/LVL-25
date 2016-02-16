/*******************************************************************************
 * File : DayOfYear.c
 * Description : This file takes user input in the format of dd-mm-yyyy, and 
gives 
 * 		 Day of the year as output
 * 
*******************************************************************************/
/*******************************************************************************
 * 				Include Files				 
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************
 * 				Macro Defines				 
 ******************************************************************************/
#define MAX_LEN 10
#define LEAP_YEAR 1
#define NOT_LEAP_YEAR 2
/*******************************************************************************
 * 				Global Variables				 
*******************************************************************************/
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/*******************************************************************************
 * Function : check_leap_year
 * Description : This function check whether given year is leap year or not
 
*******************************************************************************/
int check_leap_year(int year)
{
	if ( year % 400 == 0 || year % 4 == 0)
		return LEAP_YEAR;
	else
		return NOT_LEAP_YEAR;
}

/*******************************************************************************
 * Function : main
 * Description : This function provides control to enter into the program
 ******************************************************************************/
int main(int argc, char *argv[])
{
	char dmy[10] = {0}; //Holds user input
	char *cur = NULL; //Scrolling pointer to user input
	char rBuff[4] = {0}; // Reusable buffer
	int iDate = 0, iMonth = 0, iYear = 0; //Holds individual values for 
					     // date,month and year
	int day_of_year = 0, remaining_day_year = 365,isLeapYear = 0;
	int idx = 0;

	while(1)
	{
		printf("Enter date in dd-mm-yyyy format:");
		scanf("%s",dmy);

		/**
		 * Validating user input
		 */
		/**
		* Validating correct length of user input entered
		*/
		if ( MAX_LEN != strlen(dmy))
		{
			printf("Wrong size of user input\n");
			continue;
		}
		cur = dmy;
		
		/**
		 * Validating date format, should be in range of 01-31
		 */
		if( (*cur >= 48 && *cur <= 51) &&
			(*(cur+1) >= 47 && *(cur+1) <= 57) )
		{
			sprintf(rBuff,"%.*s",2,dmy);
			iDate = atoi(rBuff);
			if ( iDate > 0 && iDate <= 31 )
			{
				cur += 2;
			} else {
				printf("%d is wrong date range, \
					   should be in between 01-31\n",iDate);
				continue;
			}
		} else {
			printf(" Wrong date formate entered\n");
			continue;
		}

		/**
		 * Checking for separator, should be '-'
		 */
		if ( *cur != 45 )
		{
			printf("wrong separator used other than '-'\n");
			continue;
		}
		cur++;
		
		/**
		 * Validating Month format, should be in range of 01-12
		 */
		if ( (*cur >= 48 && *cur <= 49) &&
			(*(cur+1) >= 48 && *(cur+1) <= 57))
		{
			sprintf(rBuff,"%.*s",2,dmy+3);
			iMonth = atoi(rBuff);
			if ( iMonth >= 0 && iMonth <= 12 )
			{
				cur+=2;
			} else {
				printf("%d is wrong month range, \
					   should be in between 01-12\n",iMonth);
				continue;
			}
		} else {
			printf("Wrong month formate entered\n");
			continue;
		}

		/**
		 * Checking for separator, should be '-'
		 */
		if ( *cur != 45 )
		{
			printf("wrong separator used other than '-'\n");
			continue;
		}
		cur++;
		
		/**
		 *Validating Year, should be in range of 1900-2020
		 */
		if ( (*cur >= 49 && *cur <= 50 ) &&
			(*(cur+1) >= 48 || *(cur+1) <= 50) && 
			(*(cur+2) >= 48 && *(cur+2) <= 57) &&
			(*(cur+3) >= 48 && *(cur+3) <= 57 ) )
		{
			sprintf(rBuff,"%.*s",4,dmy+6);
			iYear = atoi(rBuff);
			if ( iYear <= 1900  && iYear >= 2020 )
			{
				printf("%d is Invalid Year range, \
					   should be in between 1900-2020\n",iYear);
				continue;
			}
		} else {
			printf("Invalid year format entered\n");
			continue;
		}
		break;
	}

	/**
	 *Checking for leap year
	 */
	isLeapYear = check_leap_year(iYear);
	
	if ( isLeapYear == LEAP_YEAR)
	{
		 remaining_day_year += 1;
	}
	/**
	 * Calculating Days of Year and Days remaining in year
	 */
	for(idx = 0; idx < iMonth-1 ; idx++)
	{
		if ( idx == 2 && isLeapYear == LEAP_YEAR)
		{
			day_of_year += 1;
		}
		day_of_year += days[idx];

	}
	
	day_of_year += iDate;
	remaining_day_year -= day_of_year;
	printf("**************************\n");
	printf("* Year %d is %s\n",iYear,
			(isLeapYear == LEAP_YEAR)?"a Leap Year":"Not a Leap Year");
	printf("* Day of Year:			: %d\n",day_of_year);
	printf("* Remaining Days in year	: %d\n",remaining_day_year);
	printf("* Total days in year		: %d\n",
		   day_of_year + remaining_day_year);
	printf("**************************\n");
	exit(0);
}
/************************* End of File ****************************************/
