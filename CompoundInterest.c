#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
    module      :   CompoundInterest.c
    Description :   Compound Interest Calculator
    Author      :   Brandon Knieriem
    Rev History :

    Date        Comment
    ----        -------
    10/25        Program creation
    10/28        Working Version

    Notes:
    ------
    - Don't use global variables if you can help it.
    Formulas:
    - Compute and return the amount of money, A, that you will have in n years if you invest P dollars now at annual interest rate i. Take n, i, and P as parameters.
        - A = P (1 + i)^n
    - Compute and return the amount of money, P, that you would need to invest now at annual interest rate i in order to have A dollars in n years. Take n, i, and A as parameters.
        - P = A / (1 + i)^n
 */

float   fnInvEst();
float   fnInvReq();
void    fnInputCheck();

int     *nptr;                                              // I'll try messing with this later but I'm pretty sure these don't have to be global. I can declare/initialize it below
float   *ptr;                                               // and pass the pointers into the function like I would anything else? I'm just going to turn it in now because it's due but I'll practice.

int main(void)
{
    int     s = 0;                                          // Switch Case Input
    char fname[100] = "Brandon", lname[100] = "Knieriem";   // For fun.

    printf("\n        COMPOUND INTEREST CALCULATOR (USD)\n\n");

    printf("First Name: ");
    scanf("%s", &fname);
    printf("Last Name:  ");
    scanf("%s", &lname);

    do
    {
        float   sum = 0, req = 0;

        printf("\n        COMPOUND INTEREST CALCULATOR (USD)\n\n");

        printf("Welcome back, %s %s! How can I help you?\n\n", fname, lname);
        printf("1.  Investment Return Calculator\n2.  Investment Requirement Calculator\n3.  Quit\n\n");
        printf("Enter a selection (1-3): ");
        scanf("%i", &s);

        /* Main Menu */

        switch(s)
        {
            case 1  :   // Investment Return Calculator
            sum = fnInvEst();
            printf("\nEstimated sum of investment: $%.2f\n", sum);
            break;

            case 2  :   // Investment Requirement Calculator
            req = fnInvReq();
            printf("\nAmount of investment required to reach your goal: $%.2f\n", req);
            break;

            case 3  :   // Quit Program
            printf("Closing program ...\n\n");
            break;

            default :   // Else
            printf("Invalid input. Try again.\n\n");
        }
    }
    while(s != 3);

    return 0;
}

/* Investment Return */
float fnInvEst()
{
    float   i = 0, sum = 0, req = 0, temp = 0;      // i = interest rate, req = investment, n = years.
    int     n = 0;

    printf("\nAmount invested: ");
    scanf("%10f", &req);
    ptr = &req;
    fnInputCheck();

    printf("\nAnnual Interest Rate: ");
    scanf("%10f", &i);
    ptr = &i;
    fnInputCheck();

    printf("\nYears Invested: ");
    scanf("%10i", &n);
    nptr = &n;
    fnInputCheck();

    /* A = P (1 + i)^n */

    temp = 1 + i;
    temp = pow(temp, n);
    sum  = req * temp;

    return sum;                                     // sum = estimated revenue.
}

/* Investment Requirement */
float fnInvReq()
{
    float   i = 0, sum = 0, req = 0, temp = 0;      // i = interest rate, a = accumulated revenue, n = years.
    int     n = 0;

    printf("\nRevenue Goal: ");
    scanf("%10f", &sum);
    ptr = &sum;
    fnInputCheck();

    printf("\nAnnual Interest Rate: ");
    scanf("%10f", &i);
    ptr = &i;
    fnInputCheck();

    printf("\nYears Invested: ");
    scanf("%10i", &n);
    nptr = &n;
    fnInputCheck();

    /* P = A / (1 + i)^n */

    temp =  1 + i;
    temp =  pow(temp, n);
    req  =  sum / temp;

    return req;                                      // req = estimated amount invested.
}

/* Input Checker */
void fnInputCheck()
{
    if(*ptr > 0.0 )
    {

    }
    else
    {
        printf("Invalid input.\n\n");
    }
}
