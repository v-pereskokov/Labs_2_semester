// #include <string.h>
// Думаю не все знают, что надо подключить эту библиотеку именно
// На счет iostream не уверен(т.к она есть у многих), но лучше бы ее подключить тоже сюда
// Возможно, что просто не скопировали вместе с остальным кодом
using namespace std;
// В заголовочных файлах очень редко используют пространство имен std. Скорее по возможности вообще бы лучше не использовать
// Это пространство содержит в себе всю стандартную библиотеку C++
// Дело в том, что что директива using снимает защиту с указанного пространства и действует до конца компиляции
// Также снимает защиту со всех файлов, в которые включен этот заголовочный файл
// А среди таких файлов могут оказаться другие заголовочные файлы, для которых вовсе не нужно использовать using namespace std

class MyString
{
private:
    wchar_t *str = nullptr;
    // Зачем здесь делать указатель нулевым?
    
public:
    
    MyString()
    // :str(new wchar_t)
    {
        str = new wchar_t[1];
        // Почему бы не инициализировать до блока?
        // И зачем тебе new wchar_t[1], если можно просто new wchar_t и все?
        // У тебя конструктор по умолчанию создаст один объект, а не массив
        // А потом, во время работы с этим объектом, остальные методы(описанные у тебя ниже), сами переопределяют память этому объекту
        str[0] = '\0';
    }
    
    MyString(wchar_t *str)
    // Про стиль : используй разные названия переменных класса и передаваемых в метод
    {
        this->str = new wchar_t[wcslen(str)+1];
        // Пример: str_(в классе), MyString(... *str). И тогда избежишь указателя this
        // Сделал бы название переменной иной, мог бы вынести выделение до начала блока
        wcscpy(this->str, str);
    }
    
    MyString(MyString &s)
    // :str(new wchar_t[wcslen(s.str) + 1])
    {
        
        str = new wchar_t[wcslen(s.str) + 1];
        // Тоже можно вынести инициализацию до начала блока
        wcscpy(str, s.str);
    }
    
    
    MyString& operator=(MyString &s)
    {
        if (str != nullptr)
            delete[] str;
        // Про стиль еще : придерживайся одного стиля написания кода
        // Не нужно оставлять между строчками в одном месте одну строчку, в другом - две
        str = new wchar_t[wcslen(s.str) + 1];
        
        wcscpy(str, s.str);
        
        return *this;
        
        
    }
    // С методами тоже самое. Держи все на одинаковом расстоянии
    
    wchar_t operator[](int index)
    {
        return str[index];
    }
    
    ~MyString()
    {
        delete[] str;
    }
    
    friend MyString operator+(MyString &s1, MyString &s2);
    // На паре уже делали такое: сначала надо было описать перегрузку оператора "+=" в классе
    // А затем уже вне класса оператора "+"
    // Можно примерно так :
    /*
     MyString &operator+=(const MyString &s1)
     {
     wchar_t *res = new wchar_t[wcslen(this->str) + wcslen(s1.str) + 1];
     wcscpy(res, this->str);
     wcscat(res, s1.str);
     MyString r(res);
     delete [] res;
     return r;
     }
    */
    // А при описании "+" использовать "+="

    friend wostream &operator<<(wostream &out, MyString &s);
    friend wistream &operator>>(wistream &in, MyString &s);
    // Я бы еще добавил методы, которые возвращают длину строки, очищают строку, итераторы на начало и конец
    // Первые два метода довольно полезны и часто используются в std::string
};

MyString operator+(MyString &s1, MyString &s2)
{
    wchar_t *res = new wchar_t[wcslen(s1.str) + wcslen(s2.str) + 1];
    
    wcscpy(res, s1.str);
    wcscat(res, s2.str);
    
    MyString r(res);
    // res все же можно бы очистить
    //delete [] res;
    return r;
    // И использовать лучше переменные с нормальными названиями, а не буквами
    // Частично код должен заменять сами комментарии. Другой программист должен по названию понимать что это за переменная и зачем нужна, а не искать ее применение где - то в середине кода
}

wostream &operator<<(wostream &out, MyString &s)
// Лучше использовать const MyString &s
{
    out << s.str;
    return out;
}

wistream &operator>>(wistream &in, MyString &s)
// Лучше использовать const MyString &s
{
    wchar_t buf[1000];
    in >> buf;
    
    if (s.str != nullptr)
        delete[] s.str;
    
    s.str = new wchar_t[wcslen(buf) + 1];
    wcscpy(s.str, buf);
    
    return in;
}
