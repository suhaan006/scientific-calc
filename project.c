#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define M_PI 3.14
#define M_E 2.71828
void add(double x, double y)
{
    printf("Result: %.2f\n", x + y);
}

void subtract(double x, double y)
{
    printf("Result: %.2f\n", x - y);
}

void multiply(double x, double y)
{
    printf("Result: %.2f\n", x * y);
}

void divide(double x, double y)
{
    if (y == 0)
    {
        printf("Error: Division by zero.\n");
    }
    else
    {
        printf("Result: %.2f\n", x / y);
    }
}

void power(double x, double y)
{
    printf("Result: %.2f\n", pow(x, y));
}

void squareRoot(double x)
{
    if (x < 0)
    {
        printf("Error: Negative number.\n");
    }
    else
    {
        printf("Result: %.2f\n", sqrt(x));
    }
}

void factorial(int x)
{
    if (x < 0)
    {
        printf("Error: Negative number.\n");
    }
    else
    {
        int result = 1;
        for (int i = 1; i <= x; i++)
        {
            result *= i;
        }
        printf("Result: %d\n", result);
    }
}

void logarithm(double x, double base)
{
    if (x <= 0)
    {
        printf("Error: Non-positive number.\n");
    }
    else
    {
        printf("Result: %.2f\n", log(x) / log(base));
    }
}

void sinFunction(double x)
{
    printf("Result: %.2f\n", sin(x * M_PI / 180));
}

void cosFunction(double x)
{
    printf("Result: %.2f\n", cos(x * M_PI / 180));
}

void tanFunction(double x)
{
    printf("Result: %.2f\n", tan(x * M_PI / 180));
}

void displayMenu()
{
    printf("\n** Scientific Calculator **\n");
    printf("1. Arithmetic Operations\n");
    printf("2. Trigonometric Functions\n");
    printf("3. Logarithmic Functions\n");
    printf("4. Power and Square Root\n");
    printf("5. Factorial\n");
    printf("0. Exit\n");
    printf("Select a category: ");
}

void arithmeticMenu()
{
    printf("\nArithmetic Operations:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Select an operation: ");
}

void trigMenu()
{
    printf("\nTrigonometric Functions:\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("Select an operation: ");
}

void logMenu()
{
    printf("\nLogarithmic Functions:\n");
    printf("1. Natural Logarithm (base e)\n");
    printf("2. Logarithm with Custom Base\n");
    printf("Select an operation: ");
}

void powerRootMenu()
{
    printf("\nPower and Square Root:\n");
    printf("1. Power\n");
    printf("2. Square Root\n");
    printf("Select an operation: ");
}

void main()
{
    int choice, subChoice;
    double x, y, base;

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting the calculator.\n");
            exit(0);

        case 1:
            arithmeticMenu();
            scanf("%d", &subChoice);
            printf("Enter two numbers: ");
            scanf("%lf %lf", &x, &y);

            switch (subChoice)
            {
            case 1:
                add(x, y);
                break;
            case 2:
                subtract(x, y);
                break;
            case 3:
                multiply(x, y);
                break;
            case 4:
                divide(x, y);
                break;
            default:
                printf("Invalid operation.\n");
                break;
            }
            break;

        case 2:
            trigMenu();
            scanf("%d", &subChoice);
            printf("Enter the angle in degrees: ");
            scanf("%lf", &x);

            switch (subChoice)
            {
            case 1:
                sinFunction(x);
                break;
            case 2:
                cosFunction(x);
                break;
            case 3:
                tanFunction(x);
                break;
            default:
                printf("Invalid operation.\n");
                break;
            }
            break;

        case 3:
            logMenu();
            scanf("%d", &subChoice);

            if (subChoice == 1)
            {
                printf("Enter the number: ");
                scanf("%lf", &x);
                logarithm(x, M_E);
            }
            else if (subChoice == 2)
            {
                printf("Enter the number and base: ");
                scanf("%lf %lf", &x, &base);
                logarithm(x, base);
            }
            else
            {
                printf("Invalid operation.\n");
            }
            break;

        case 4:
            powerRootMenu();
            scanf("%d", &subChoice);

            if (subChoice == 1)
            {
                printf("Enter the base and exponent: ");
                scanf("%lf %lf", &x, &y);
                power(x, y);
            }
            else if (subChoice == 2)
            {
                printf("Enter the number: ");
                scanf("%lf", &x);
                squareRoot(x);
            }
            else
            {
                printf("Invalid operation.\n");
            }
            break;

        case 5:
            printf("Enter the number for factorial: ");
            scanf("%lf", &x);
            factorial((int)x);
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    getch();
}
