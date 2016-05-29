#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

class Base
{
public:
    Base(const int value)
    :_value(value) {}
    virtual void show() = 0;
protected:
    int _value;
};

class A : public Base
{
public:
    A(const int value)
    :Base(value) {}
    void show() {
        std::cout << "class A: " << _value << std::endl;
    }
};

class B : public Base
{
public:
    B(const int value)
    :Base(value) {}
    void show() {
        std::cout << "class B: " << _value << std::endl;
    }
};

class C : public Base
{
public:
    C(int value)
    :Base(value) {}
    void show() {
        std::cout << "class C: " << _value << std::endl;
    }
};
std::vector<Base*> objects;

class Functor
{
public:
    virtual void operator()() {};
    virtual void operator()(std::string, int) {};
};

class FunctorShow : public Functor
{
public:
    FunctorShow() {};
    void operator()() {
        for (auto it : objects)
            it->show();
    }
};

class FunctorCreate : public Functor
{
public:
    FunctorCreate() {};
    void operator()(std::string classname, int value) {
        std::map<std::string, Base*> classes;
        classes["A"] = new A(value);
        classes["B"] = new B(value);
        classes["C"] = new C(value);
        Base* base;
        base = classes[classname];
        objects.push_back(base);
    }
};

std::vector<std::string> separation(const std::string &s)
{
    std::vector<std::string> words;
    std::istringstream ist(s);
    std::string tmp;
    while (ist >> tmp)
        words.push_back(tmp);
    return words;
}

int main()
{
    std::map<std::string, Functor*> mfunc;
    Functor *fshow = new FunctorShow;
    Functor *fcreate = new FunctorCreate;
    mfunc["showall"] = fshow;
    mfunc["create"] = fcreate;
    std::string command;
    std::vector<std::string> words;
    Functor *fctr;
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (std::size_t i = 1; i <= n; ++i)
    {
        std::getline(std::cin, command);
        words = separation(command);
        fctr = mfunc[words[0]];
        switch (words.size()) {
            case 1:
                (*fctr)();
                break;
            case 3:
                (*fctr)(words[1], stoi(words[2]));
                break;
            default:
                std::cout << "Неверная команда!\nВведите снова!\n";
                --i;
                break;
        }
    }
    return 0;
}