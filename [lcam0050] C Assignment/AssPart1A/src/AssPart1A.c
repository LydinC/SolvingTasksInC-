#include <stdio.h>
#define TaxRate1	1.00
#define TaxRate2	0.85
#define TaxRate3	0.71
#define Breakpoint1	300.00
#define Breakpoint2	480.00
#define Calculation1 (TaxRate1 * Breakpoint1)
#define Calculation2 (Calculation1 + (TaxRate2 * (Breakpoint2 - Breakpoint1)))

float BasicPayRate = 22.50;
float HoursWorked=0, NormalHoursWage=0;
float Overtime=0, OvertimeWageAddition=0, OvertimeMultiplier=1.5;
float GrossPay=0, NetPay=0;

int main(void) {
	printf("Please enter the number of hours worked during the week =  ");
	fflush(stdout);
	scanf("%f", &HoursWorked);

	//Calculating Wage when Hours Worked is Less Than or Equal to 40 hours
	if(HoursWorked <= 40)
		NormalHoursWage = (BasicPayRate * HoursWorked);
	else
		NormalHoursWage = (BasicPayRate * 40);
	printf("\nNormal hours pay = Eur %.2f \n", NormalHoursWage);

	//Calculating Overtime over 40 hours
	if (HoursWorked > 40)
		Overtime = HoursWorked - 40;
	printf("Hours worked as Overtime = %.2f hours", Overtime);

	OvertimeWageAddition = Overtime * (OvertimeMultiplier * BasicPayRate);
	printf("\nOver time extra pay = Eur %.2f", OvertimeWageAddition);

	//Gross Pay Calculation
	GrossPay = (NormalHoursWage + OvertimeWageAddition);
	printf("\nGross pay is = Eur %.2f", (GrossPay));

    //Tax Calculations
	if (GrossPay <= Breakpoint1)
		NetPay = GrossPay * TaxRate1;
	else if (GrossPay <= Breakpoint2)
		NetPay = Calculation1 + ((GrossPay - Breakpoint1) * TaxRate2);
	else if (GrossPay > Breakpoint2)
		NetPay = Calculation2 + ((GrossPay - Breakpoint2) * TaxRate3);

	printf("\nTax deductions = Eur %.2f", (GrossPay - NetPay));
	printf("\nNet pay of this week's pay is = Eur %.2f", NetPay);
	return 0 ;
}
