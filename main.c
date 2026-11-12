#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//gcc main.c -o main -lm && ./main  
//command to run the program

void clear_stdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

double get_double(const char *prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%lf", &value) == 1) {
            clear_stdin();
            return value;
        }
        printf("Invalid input. Please enter a valid number.\n");
        clear_stdin();
    }
}

int get_int(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            clear_stdin();
            return value;
        }
        printf("Invalid input. Please enter an integer.\n");
        clear_stdin();
    }
}

void print_menu(void) {
    printf("\n========================================\n");
    printf("         SCIENTIFIC CALCULATOR          \n");
    printf("========================================\n");
    printf(" 1. Addition (+)          9. Sine (sin)\n");
    printf(" 2. Subtraction (-)      10. Cosine (cos)\n");
    printf(" 3. Multiplication (*)   11. Tangent (tan)\n");
    printf(" 4. Division (/)         12. Natural Log (ln)\n");
    printf(" 5. Power (x^y)          13. Base-10 Log (log10)\n");
    printf(" 6. Square Root (sqrt)   14. Exponential (e^x)\n");
    printf(" 7. Absolute Value       15. Factorial (n!)\n");
    printf(" 8. Modulo (%%)            0. Exit\n");
    printf("========================================\n");
}

long long factorial(int n) {
    if (n < 0) return -1;
    long long res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main(void) {
    int choice;
    double a, b, result;

    while (1) {
        print_menu();
        choice = get_int("Select an option (0-15): ");

        if (choice == 0) {
            printf("Exiting calculator.\n");
            break;
        }

        switch (choice) {
            case 1: // Add
                a = get_double("Enter first number: ");
                b = get_double("Enter second number: ");
                printf("Result: %.6g + %.6g = %.6g\n", a, b, a + b);
                break;

            case 2: // Subtract
                a = get_double("Enter first number: ");
                b = get_double("Enter second number: ");
                printf("Result: %.6g - %.6g = %.6g\n", a, b, a - b);
                break;

            case 3: // Multiply
                a = get_double("Enter first number: ");
                b = get_double("Enter second number: ");
                printf("Result: %.6g * %.6g = %.6g\n", a, b, a * b);
                break;

            case 4: // Divide
                a = get_double("Enter numerator: ");
                b = get_double("Enter denominator: ");
                if (b == 0.0) {
                    printf("Error: Division by zero is undefined.\n");
                } else {
                    printf("Result: %.6g / %.6g = %.6g\n", a, b, a / b);
                }
                break;

            case 5: // Power
                a = get_double("Enter base (x): ");
                b = get_double("Enter exponent (y): ");
                printf("Result: %.6g ^ %.6g = %.6g\n", a, b, pow(a, b));
                break;

            case 6: // Square Root
                a = get_double("Enter number: ");
                if (a < 0.0) {
                    printf("Error: Cannot calculate real square root of a negative number.\n");
                } else {
                    printf("Result: sqrt(%.6g) = %.6g\n", a, sqrt(a));
                }
                break;

            case 7: // Absolute Value
                a = get_double("Enter number: ");
                printf("Result: |%.6g| = %.6g\n", a, fabs(a));
                break;

            case 8: // Modulo
                a = get_double("Enter dividend: ");
                b = get_double("Enter divisor: ");
                if (b == 0.0) {
                    printf("Error: Modulo by zero is undefined.\n");
                } else {
                    printf("Result: fmod(%.6g, %.6g) = %.6g\n", a, b, fmod(a, b));
                }
                break;

            case 9: // Sin (Degrees)
                a = get_double("Enter angle in degrees: ");
                result = sin(a * M_PI / 180.0);
                printf("Result: sin(%.6g deg) = %.6g\n", a, result);
                break;

            case 10: // Cos (Degrees)
                a = get_double("Enter angle in degrees: ");
                result = cos(a * M_PI / 180.0);
                printf("Result: cos(%.6g deg) = %.6g\n", a, result);
                break;

            case 11: // Tan (Degrees)
                a = get_double("Enter angle in degrees: ");
                if (fmod(fabs(a - 90.0), 180.0) == 0.0) {
                    printf("Error: tan(%.6g deg) is undefined (asymptote).\n", a);
                } else {
                    result = tan(a * M_PI / 180.0);
                    printf("Result: tan(%.6g deg) = %.6g\n", a, result);
                }
                break;

            case 12: // Natural Log (ln)
                a = get_double("Enter number: ");
                if (a <= 0.0) {
                    printf("Error: Logarithm domain error (x must be > 0).\n");
                } else {
                    printf("Result: ln(%.6g) = %.6g\n", a, log(a));
                }
                break;

            case 13: // Log10
                a = get_double("Enter number: ");
                if (a <= 0.0) {
                    printf("Error: Logarithm domain error (x must be > 0).\n");
                } else {
                    printf("Result: log10(%.6g) = %.6g\n", a, log10(a));
                }
                break;

            case 14: // Exponential (e^x)
                a = get_double("Enter exponent (x): ");
                printf("Result: e^(%.6g) = %.6g\n", a, exp(a));
                break;

            case 15: { // Factorial
                int n = get_int("Enter a non-negative integer (<= 20): ");
                if (n < 0) {
                    printf("Error: Factorial of a negative number is undefined.\n");
                } else if (n > 20) {
                    printf("Error: Input too large. 64-bit integer overflow occurs above 20!.\n");
                } else {
                    printf("Result: %d! = %lld\n", n, factorial(n));
                }
                break;
            }

            default:
                printf("Error: Unknown command. Please select an option from the menu.\n");
                break;
        }
    }

    return 0;
}