#include <iostream>
#include <math.h> // Зачем для нижеописанных методов?

class Complex
{
private:
    double re_, im_;
    
public:
    // Где конструктор по умолчанию?
    Complex (double r = 0.0, double i = 0.0)
    : re_(r), im_(i)
    {
        printf(".ctor");
        //  Зачем использовать printf в C++ (В ++ используют std::cout)?
    }
    void copy (Complex &c)
    // Если под этим методом имелся ввиду конструктор копирования,
    // то и нужно было делать конструктор копирования, а не выносить в отдельный метод.
    // Надо было перегрузить оператор = для таких целей, а не вызывать отдельный метод.
    // Почему бы не вынести присваивание до начала блока, как это сделано выше?
    {
        re_ = c.re_;
        im_ = c.im_;
    }
    void set (double a, double b)
    //: re_(a), im_(b)
    {
        re_ = a ;
        im_ = b;
        // Почему бы не вынести присваивание до начала блока, как это сделано выше?
    }
    double re (Complex &c)
    // Зачем передавать в этот метод другой объект, если, по идее(и по названию), этот метод возвращает re_?
    {
        return c.re_;
    }
    double im (Complex &c)
    // Аналогично предыдущему
    {
        return c.im_;
    }
    /*Complex summ (Complex &a, Complex &b)
    {
        Complex c;
        double re, im;
        re = a.re_ + b.re_;
        im = a.im_ + b.im_;
        c.re_ = re;
        c.im_ = im;
        return c;
    }
    Complex sub (Complex &a, Complex &b)
    {
        Complex c;
        double re, im;
        re = a.re_ - b.re_;
        im = a.im_ - b.im_;
        c.re_ = re;
        c.im_ = im;
        return c;
    }
    Complex div (Complex &a, Complex &b)
    {
        Complex c;
        double re, im;
        re = (a.re_ * b.re_ - a.im_ * b.im_) / (b.re_ * b.re_ + b.im_ * b.im_);
        im = (a.im_ * b.re_ - a.re_ * b.im_) / (b.re_ * b.re_ + b.im_ * b.im_);
        c.re_ = re;
        c.im_ = im;
        return c;
    }
    Complex mul (Complex &a, Complex &b)
    {
        Complex c;
        double re, im;
        re = a.re * b.re - a.im_ * b.im_;
        im = a.re * b.im_ + a.im_ * b.re_;
        c.re_ = re;
        c.im_ = im;
        return c;
    }*/
    // Что это такое? Почему бы не перегружать операторы для таких целей. Тем более, что на лабораторной уже разобрали как делать сложение и деление.
    // Удобно было бы использовать функции для работы с числами/строками, а не просто "+", "-"...?
    // Да и в самих методах этих есть опечатки.
    void print (Complex &a)
    // Почему бы не перегрузить оператор << ?
    {
        if (a.im_ < 0)
            std::cout << a.re_ << a.im_ << "i" << std::endl;
        else std::cout << a.re_ << "+" << a.im_ << "i" << std::endl;
    }
    ~Complex() 
    { 
        printf(".dtor");
        // См. выше(конструктор)
    }
};