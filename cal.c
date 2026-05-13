 #include <stdio.h>
#include <math.h>

void addition();
void subtraction();
void multiplication();
void division();
void square();
void squareRoot();
void matrixAddition();
void matrixSubtraction();
void matrixMultiplication();
void logarithm();
void trigonometric_angles();
void area();
void factorial();
void determinant();
void power_n();
void transpose();
void rank_of_matrix();

int main() {
    int choice;

    while (1) {
        printf("\n=== Scientific Calculator ===\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square\n6. Square Root\n");
        printf("7. Matrix Addition\n8. Matrix Subtraction\n9. Matrix Multiplication\n10. Logarithm\n");
        printf("11. Trigonometric Angles\n12. Area Calculation\n13. Factorial\n14. Matrix Determinant\n");
        printf("15. Power Calculation\n16. Matrix Transpose\n17. rank_of_matrix\n.0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addition(); break;
            case 2: subtraction(); break;
            case 3: multiplication(); break;
            case 4: division(); break;
            case 5: square(); break;
            case 6: squareRoot(); break;
            case 7: matrixAddition(); break;
            case 8: matrixSubtraction(); break;
            case 9: matrixMultiplication(); break;
            case 10: logarithm(); break;
            case 11: trigonometric_angles(); break;
            case 12: area(); break;
            case 13: factorial(); break;
            case 14: determinant(); break;
            case 15: power_n(); break;
            case 16: transpose(); break;
            case 17: rank_of_matrix(); break;
            case 0: return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}

void addition() {
    int n, i;
    double num, sum = 0;
    printf("How many numbers to add? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%lf", &num);
        sum += num;
    }
    printf("Sum is: %.2lf\n", sum);
}

void subtraction() {
    int n, i;
    double num, result;
    printf("How many numbers for subtraction? ");
    scanf("%d", &n);

    printf("Enter the first number: ");
    scanf("%lf", &result);
    for(i = 1; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%lf", &num);
        result -= num;
    }
    printf("Result is: %.2lf\n", result);
}

void multiplication() {
    int n, i;
    double num, result = 1;
    printf("How many numbers to multiply? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter number %d: ", i+1);
        scanf("%lf", &num);
        result *= num;
    }
    printf("Product is: %.2lf\n", result);
}

void division() {
    double num1, num2;
    printf("Enter dividend: ");
    scanf("%lf", &num1);
    printf("Enter divisor: ");
    scanf("%lf", &num2);

    if (num2 == 0) {
        printf("Cannot divide by zero.\n");
        return;
    }
    printf("Quotient is: %.2lf\n", num1 / num2);
}

void square() {
    double num;
    printf("Enter number to square: ");
    scanf("%lf", &num);
    printf("Square is: %.2lf\n", num * num);
}

void squareRoot() {
    double num;
    printf("Enter number to find square root: ");
    scanf("%lf", &num);

    if (num < 0) {
        printf("Cannot find square root of negative number.\n");
        return;
    }
    printf("Square root is: %.2lf\n", sqrt(num));
}

void matrixAddition() {
    int rows, cols, i, j;
    printf("Matrix addition:\nEnter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];

    printf("Matrix addition result:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void matrixSubtraction() {
    int rows, cols, i, j;
    printf("Matrix subtraction:\nEnter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            scanf("%d", &matrix2[i][j]);

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];

    printf("Matrix subtraction result:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void matrixMultiplication() {
    int rows1, cols1, rows2, cols2, i, j, k;
    printf("Matrix multiplication:\nEnter rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible with given dimensions.\n");
        return;
    }

    int matrix1[rows1][cols1], matrix2[rows2][cols2], result[rows1][cols2];

    printf("Enter elements of first matrix:\n");
    for(i = 0; i < rows1; i++)
        for(j = 0; j < cols1; j++)
            scanf("%d", &matrix1[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i = 0; i < rows2; i++)
        for(j = 0; j < cols2; j++)
            scanf("%d", &matrix2[i][j]);

    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for(k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Matrix multiplication result:\n");
    for(i = 0; i < rows1; i++) {
        for(j = 0; j < cols2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void logarithm() {
    double base, value;
    printf("Enter base and value: ");
    scanf("%lf %lf", &base, &value);

    if (base <= 0 || value <= 0 || base == 1) {
        printf("Invalid base or value for logarithm.\n");
        return;
    }
    printf("Logarithm result: %.2lf\n", log(value) / log(base));
}

void trigonometric_angles() {
    double angle;
    printf("Enter the angle in degrees: ");
    scanf("%lf", &angle);
    double radians = angle * M_PI / 180.0;
    printf("sin(%.2lf) = %.2lf\n", angle, sin(radians));
    printf("cos(%.2lf) = %.2lf\n", angle, cos(radians));
    printf("tan(%.2lf) = %.2lf\n", angle, tan(radians));
}

void area() {
    int shape;
    printf("Choose shape (1 for Square, 2 for Rectangle): ");
    scanf("%d", &shape);

    if (shape == 1) {
        double side;
        printf("Enter the side length: ");
        scanf("%lf", &side);
        printf("Area of Square: %.2lf\n", side * side);
    } else if (shape == 2) {
        double length, breadth;
        printf("Enter the length and breadth: ");
        scanf("%lf %lf", &length, &breadth);
        printf("Area of Rectangle: %.2lf\n", length * breadth);
    } else {
        printf("Invalid shape selected.\n");
    }
}

void factorial() {
    int n;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error! Factorial of a negative number doesn't exist.\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("Factorial: %lld\n", fact);
}

void determinant() {
    int rows, cols;

    // Ask for matrix dimensions (only 2x2 and 3x3 matrices supported)
    printf("Enter number of rows (2 or 3): ");
    scanf("%d", &rows);
    printf("Enter number of columns (2 or 3): ");
    scanf("%d", &cols);

    // Check if it's a valid matrix for determinant calculation
    if ((rows == 2 && cols == 2) || (rows == 3 && cols == 3)) {
        double matrix[3][3], det;

        // Input matrix elements
        printf("Enter the elements of the matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("Element [%d][%d]: ", i + 1, j + 1);
                scanf("%lf", &matrix[i][j]);
            }
        }

        // If matrix is 2x2, calculate determinant
        if (rows == 2 && cols == 2) {
            det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
            printf("The determinant of the matrix is: %.2lf\n", det);
        }
        // If matrix is 3x3, calculate determinant
        else if (rows == 3 && cols == 3) {
            det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) 
                - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            printf("The determinant of the matrix is: %.2lf\n", det);
        }
    } else {
        printf("Sorry, the program only supports 2x2 or 3x3 matrices for determinant calculation.\n");
    }
}

void power_n() {
    double base, result;
    int exponent;
    printf("Enter the base number: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);
    result = pow(base, exponent);
    printf("%.2lf raised to the power %d is %.2lf\n", base, exponent, result);
}

void transpose() {
    int rows, cols;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    double matrix[rows][cols], transpose[cols][rows];

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Finding transpose of the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Printing the transposed matrix
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%.2lf ", transpose[i][j]);
        }
        printf("\n");
    }
}

void rank_of_matrix() {
    int rows, cols;

    // Ask for matrix dimensions
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if matrix dimensions are valid for rank calculation
    if (rows <= 0 || cols <= 0) {
        printf("Invalid matrix dimensions. Exiting.\n");
        return;
    }

    // Define the matrix and input the elements
    double matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Function to calculate the rank (a simplified method)
    int rank = 0;

    // Copy the matrix into a temporary matrix to perform row reduction
    double temp_matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp_matrix[i][j] = matrix[i][j];
        }
    }

    // Perform Gaussian elimination (row reduction) to find the rank
    for (int i = 0; i < rows; i++) {
        if (temp_matrix[i][i] != 0) {
            for (int j = i + 1; j < rows; j++) {
                if (temp_matrix[j][i] != 0) {
                    double factor = temp_matrix[j][i] / temp_matrix[i][i];
                    for (int k = 0; k < cols; k++) {
                        temp_matrix[j][k] -= factor * temp_matrix[i][k];
                    }
                }
            }
            rank++;
        }
    }

    printf("The rank of the matrix is: %d\n", rank);
}