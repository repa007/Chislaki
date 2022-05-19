#include <iostream>
#include <math.h>

long double fun(long double x) 
{
    return asin(2.00 * x);
}

void rectangular_method(long double a, long double b,long double h) 
{
    long double steps = (b - a) / h;
    long double f = 0;
    for (int i = 1; i <= steps; i++) 
    {
        long double argument = a + h * (i - 0.5);
        f += h * fun(argument); //берём по серединке прямоугольника
    }
    std::cout << "By the rectangular method: " << f << "\n";
}

void trapezoid_method(long double a, long double b, long double h) 
{
    long double n = (b - a) / h;
    long double f = fun(a) + fun(b);
    for (int i = 1; i <= n - 1; i++) 
    {
        f += 2.00 * fun(a + h * i); 
    }
    f = f * (h / 2.00);
    std::cout << "By the trapezoid method:   " << f << "\n";
}

void simpson_method(long double a,long double b,long double h) 
{
    long double n = (b - a) / h;
    long double f = fun(a) + fun(b);
    int k;
    for (int i = 1; i <= n - 1; i++) 
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
    long double b = (1.00 / 4.00); //верхний предел
    long double a = 0; //нижний предел
    long double h = 0.01; //шаг
    rectangular_method(a, b, h);
    trapezoid_method(a, b, h);
    simpson_method(a, b, h);
}
