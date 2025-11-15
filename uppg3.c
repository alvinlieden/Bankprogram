#include <stdio.h>
#include <math.h>
#define MAXTERMS 101

struct fraction{
    int numerator, denominator;
};
typedef struct fraction Fraction;

struct polynomial{
    Fraction coefficients[MAXTERMS];
    int nrOfTerms;
};
typedef struct polynomial Polynomial;

float valueOfPolynomial(Polynomial p, float x);

int main(){

    Fraction fraction1 = {4,3}, fraction2;
    fraction2.numerator = 6;
    fraction2.denominator = 7;
    Polynomial polynomial = {{{1,3},{-4,3},{1,2}},3};
    printf("%.3f\n",valueOfPolynomial(polynomial,2.1));

    return 0;
}

float valueOfPolynomial(Polynomial p, float x){
    float result = 0;
    for(int term=0;term<p.nrOfTerms;term++){
        result += (float) p.coefficients[term].numerator / p.coefficients[term].denominator * pow(x,term);
    }
    return result;
}