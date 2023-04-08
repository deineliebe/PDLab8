#include <iostream>

float rnd(float x)
{
    int temp = x * 1000;
    return temp / 1000.;
}

float inDegree(float x, int degree)
{
    float temp = 1;
    for (int i = 0; i < degree; i++)
    {
        temp *= x;
    }
    return temp;
}

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

void task1(float h, float start, float end)
{
    std::cout << "\nStep: " << h << '\n';
    for (float i = start; i < end; i += h)
    {
        std::cout << "h = " << i << ":\n";
        std::cout << "First difference relatives:\n";
        std::cout << "Mean = " << rnd(firstDeriative(i)) << ", ";
        std::cout << "left: " << rnd(leftDifferenceDerivative(i, h)) << ", ";
        std::cout << "central: " << rnd(centralDifferenceDerivative(i, h)) << ", ";
        std::cout << "right: " << rnd(rightDifferenceDerivative(i, h)) << "\n";
        std::cout << "Second relative:\n";
        std::cout << "Mean = " << rnd(secondDeriative(i)) << ", ";
        std::cout << "second difference deriative = " << rnd(secondDifferenceDeriative(i, h)) << "\n\n";
    }
}

void task2(float h, float start, float end)
{
    float result;
    result = function(start);
    result += function(end);
    for (float i = start; i < end; i += h)
    {
        result += 4 * function(i - 0.5);
    }
    for (float i = start; i < end; i += h)
    {
        result += 2 * function(i);
    }
    std::cout << "Result: " << rnd((h / 6.) * result);
}

int main()
{
    std::cout << "This is the eigth lab of project design.\n\n";
    float h1 = 0.3;
    float h2 = 0.05;
    float start = 1;
    float end = 2.5;
    std::cout << "Function: ln(x^2 + sqrt(x^4 + 1)).\n";
    std::cout << "Interval = [" << start << ", " << end << "]\n";
    std::cout << "h1 = " << h1 << ", h2 = " << h2 << '\n';
    std::cout << "First task is to build right, left and central difference derivatives of function. Find the second difference derivative of function. Compare with correct derivate.\n";
    task1(h1, start, end);
    task1(h2, start, end);
    std::cout << "\nSecond task is to integrate function on an interval.\n";
    if (h1 < h2)
    {
        std::cout << "Step: " << h2 << '\n';
        task2(h2, start, end);
    }
    else
    {
        std::cout << "Step: " << h1 << '\n';
        task2(h1, start, end);
    }
}