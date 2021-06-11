#include<iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b){
   double sum = 0, dalta = .0001;
   for (double x = a + dalta/2; x < b; x += dalta)
      sum += f(x) * dalta;
   return sum;
};

double line(double x){  // This is the functions y=x
    return x;
}

double square(double x){  // This is the function y=x^2
    return x*x;
}

double cube(double x){  // This is the function y=x^3
    return x*x*x;
}

int main(){

    cout << "The Integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The Integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The Integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;

return 0;
}