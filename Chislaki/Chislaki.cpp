#include <iostream>
#include <math.h>

long double fun(long double x)
{
    return log(x * x + 2);
}

void rectangular_method(long double a, long double b, long double steps)
{
    long double h = (b - a) / steps;
    long double f = 0;
    for (int i = 1; i <= steps; i++)
    {
        long double argument = a + h * (i - 0.5);
        f += h * fun(argument); //берём по серединке прямоугольника
    }
    std::cout << "By the rectangular method: " << f << "\n";
}

void trapezoid_method(long double a, long double b, long double steps)
{
    long double h = (b - a) / steps;
    long double f = fun(a) + fun(b);
    for (int i = 1; i <= steps - 1; i++)
    {
        f += 2.00 * fun(a + h * i);
    }
    f = f * (h / 2.00);
    std::cout << "By the trapezoid method:   " << f << "\n";
}

void simpson_method(long double a, long double b, long double steps)
{
    long double h = (b - a) / steps;
    long double f = fun(a) + fun(b);
    int k;
    for (int i = 1; i <= steps - 1; i++)
    {
        if (i % 2 == 0) k = 2;
        else k = 4;
        f += k * fun(a + h * i);
    }
    f = f * (h / 3.00);
    std::cout << "By the simpson method:     " << f << "\n";
}

int main()
{
    long double b = 100; //верхний предел
    long double a = 0; //нижний предел
    long double steps = 1000; //шаг
    rectangular_method(a, b, steps);
    trapezoid_method(a, b, steps);
    simpson_method(a, b, steps);
}