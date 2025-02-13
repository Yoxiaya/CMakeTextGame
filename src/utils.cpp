#include "utils.h"

#include <iostream>

void clearWindow() {
    std::cout << "\033[2J\033[1;1H";
}