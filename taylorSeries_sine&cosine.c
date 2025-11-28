#include <stdio.h>
#include <math.h>

int factorial(int x );
double degree_to_radian(double x);

double cosine_taylor(double x, int terms);
double sine_taylor(double x, int terms);


int main(){

    double degree;
    int terms; 

    printf("Please, enter the angle in degrees: ");
    scanf("%lf", &degree);

    printf("Please, enter the number of Taylor Series terms: ");
    scanf("%d", &terms);

    double x = degree_to_radian(degree);

    double sin_approx = sine_taylor(x, terms);
    double cos_approx = cosine_taylor(x, terms);

    double sin_real = sin(x);
    double cos_real = cos(x);


    printf("\n--- Taylor Series Approximation Values ---\n");
    printf("sin(%.2f) = %.8f (Taylor, %d terms)\n", degree, sin_approx, terms);
    printf("cos(%.2f) = %.8f (Taylor, %d terms)\n", degree, cos_approx, terms);

    printf("\n--- math.h Values ---\n");
    printf("sin(%.2f) = %.8f (math.h)\n", degree, sin_real);
    printf("cos(%.2f) = %.8f (math.h)\n", degree, cos_real);


    printf("\n--- Error Percentage ---\n");
    // Sine error
    if (sin_real == 0.0) {
        printf("Sine Error Percentage: not possible (true value is 0)\n");
    } else {
        double sin_error = fabs((sin_real - sin_approx) / sin_real) * 100.0;
        printf("Sine Error Percentage: %.6f%%\n", sin_error);
    }

    // Cosine error
    if (cos_real == 0.0) {
        printf("Cosine Error Percentage: not possible (true value is 0)\n");
    } else {
        double cos_error = fabs((cos_real - cos_approx) / cos_real) * 100.0;
        printf("Cosine Error Percentage: %.6f%%\n", cos_error);
    }

    return 0;
}


int factorial(int x){
    if(x==0 || x== 1){
        return 1;
    }else{
        return (x * factorial(x-1));
    }
}

double degree_to_radian(double x){
    return x * M_PI / 180; 
}

double cosine_taylor(double x, int terms){
    double result=0.0;
    int sign=1;

    for (int i=0 ; i< terms ; i++){
        int power= 2*i;
        result+=(sign* pow(x, power) / factorial(i*2));
        sign*=-1;
    }

    return result; 
}

double sine_taylor(double x, int terms){
    double result=0.0;
    int sign=1;

    for (int i=0 ; i< terms ; i++){
        int power = 2*i +1;
        result+=(sign* pow(x, power) / factorial(i*2 +1 ));
        sign*=-1;
    }

    return result; 
}
