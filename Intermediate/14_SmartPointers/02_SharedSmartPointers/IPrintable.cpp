#include <iostream>
#include "IPrintable.h"

std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
    obj.print(os);
    return os;
}
