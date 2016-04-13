#include <iostream>
#include "vector.h"

int main() {
    vector v1(1, 2);
    v1.printPoint();
    vectorE v2(1, 2, 3);
    v2.printPoint();
    v2.printLength();
    return 0;
}