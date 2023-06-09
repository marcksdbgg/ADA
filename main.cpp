// Code B
// User type to simplify the declaration
#include <iostream>
using namespace std;

float Addition(float a, float b) { return a + b; }
float Subtraction(float a, float b) { return a - b; }
float Multiplication(float a, float b) { return a * b; }
float Division(float a, float b) { return a / b; }

typedef float (*lpfnOperation)(float, float);
// CVector of pointer to functions
lpfnOperation vpf[4] = {&::Addition, &::Subtraction, &::Multiplication, &::Division};

int main(){
    float a, b, c;
    int opt;
    // enter the operands
    std::cin >> a >> b;
    // enter the operation 0-Addition, 1-Subtraction, 3-Multiplication, 4-Division
    std::cin >> opt;
    // call the function
    c = vpf[opt](a, b);
    std::cout << c << std::endl;
    return 0;
}
