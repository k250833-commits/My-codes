#include <stdio.h>

double calculateRepayment(double loan, double interest_rate, int years, double installment) {
    if (loan <= 0 || years == 0)
        return 0;
        loan = loan - installment;
    if (loan < 0) loan = 0; 
    loan = loan + (loan * interest_rate / 100);
    printf("Year %d: Remaining loan = %.2f\n", years, loan); 
    double final = calculateRepayment(loan, interest_rate, years - 1, installment);
    return installment + final;  
}


int main() {

    int years;
    double loan;
    double interest_rate;
    double installment;

    printf("Enter the amount of loan for which the repayment has to be calculated: ");
    scanf("%lf", &loan);

    printf("Enter the amount of installment: ");
    scanf("%lf", &installment);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    double totalPaid = calculateRepayment(loan, interest_rate, years, installment);

    printf("\nTotal amount paid in %d years = %.2f\n", years, totalPaid);

    return 0;
}

