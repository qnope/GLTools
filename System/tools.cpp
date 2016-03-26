#include "tools.hpp"
#include <cmath>

unsigned nextPowerOfTwo(unsigned number) {
    if(fmod(log2(number), 1) < 0.00001)
        return number;

    unsigned n = (unsigned)log2(number) + 1;
    return 1 << n;
}
