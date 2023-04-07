#include <iostream>

float inDegree(float x, int degree)
{
    float temp = 1;
    for (int i = 0; i < degree; i++)
    {
        temp *= x;
    }
    return temp;
}

//float ln(float x)
//{
//    x = 2.7;
//    float temp = 1;
//    int i = 1;
//    float sum = 1;
//    while (abs(temp) > 0.000001)
//    {
//        /*sum += temp / i;
//        temp *= -1 * x;
//        i++;*/
//        sum += temp;
//        temp *= inDegree((x - 1), 2) / (i * inDegree((x + 1), 2));
//        i += 2;
//    }
//    std::cout << sum << '\n';
//    return sum * 2 * (x - 1) / (x + 1);
//}

float function(float x)
{
    return log(inDegree(x, 2) + sqrt(inDegree(x, 4) + 1));
}

float firstDeriative(float x)
{
    return 2*x/sqrt(inDegree(x, 4) + 1);
}
float leftDifferenceDerivative(float x, float h)
{
    return (function(x + h) - function(x)) / h;
}

float rightDifferenceDerivative(float x, float h)
{
    return (function(x) - function(x - h)) / h;
}

float centralDifferenceDerivative(float x, float h)
{
    return (function(x + h) - function(x - h)) / (2 * h);
}

float secondDeriative(float x)
{
    return (2 * (sqrt(inDegree(x, 4) + 1) - (2 * inDegree(x, 4)) / (sqrt(inDegree(x, 4) + 1)))) / (inDegree(x, 4) + 1);
}

float secondDifferenceDeriative(float x, float h)
{
    return ((function(x - h) - 2 * function(x) + function(x + h)) / (inDegree(h, 2)));
}

void task1(float h1, float h2, float start, float end)
{
    std::cout << "\nStep: " << h1 << '\n';
    for (float i = start; i < end; i += h1)
    {
        std::cout << "h = " << i << ":\n";
        std::cout << "First difference relatives:\n";
        std::cout << "Mean = " << firstDeriative(i) << ", ";
        std::cout << "left: " << leftDifferenceDerivative(i, h1) << ", ";
        std::cout << "central: " << centralDifferenceDerivative(i, h1) << ", ";
        std::cout << "right: " << rightDifferenceDerivative(i, h1) << "\n";
        std::cout << "Second relative:\n";
        std::cout << "Mean = " << secondDeriative(i) << ", ";
        std::cout << "second difference deriative = " << secondDifferenceDeriative(i, h1) << "\n";
    }

    std::cout << "\nStep: " << h2 << '\n';
    for (float i = start; i < end; i += h2)
    {
        std::cout << "h = " << i << ":\n";
        std::cout << "First difference relatives:\n";
        std::cout << "Mean = " << firstDeriative(i) << ", ";
        std::cout << "left: " << leftDifferenceDerivative(i, h2) << ", ";
        std::cout << "central: " << centralDifferenceDerivative(i, h2) << ", ";
        std::cout << "right: " << rightDifferenceDerivative(i, h2) << "\n";
        std::cout << "Second relative:\n";
        std::cout << "Mean = " << secondDeriative(i) << ", ";
        std::cout << "second difference deriative = " << secondDifferenceDeriative(i, h2) << "\n";
    }


}

int main()
{
    std::cout << "This is the nineth lab of project design.\n\n";
    std::cout << "First task is to build right, left and central difference derivatives of function. Find the second difference derivative of function. Compare with correct derivate.\n";
    std::cout << "Function: ln(x^2 + sqrt(x^4 + 1)).\n";
    float h1 = 0.3;
    float h2 = 0.05;
    task1(h1, h2, 1, 2.5);

    std::cout << "\n\n" << log(2.7) << ' ' << log(1);
}