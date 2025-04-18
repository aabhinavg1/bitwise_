#include <iostream>
#include <cstdint>
#include <cassert>

// 32-bit unsigned bitwise adder
uint32_t bitwiseAdd(uint32_t a, uint32_t b) {
    while (b != 0) {
        uint32_t carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}

// Print 32-bit binary
void printBinary(uint32_t n) {
    for (int i = 31; i >= 0; --i)
        std::cout << ((n >> i) & 1);
    std::cout << std::endl;
}

int main() {
    // 1. Check size is 4 bytes = 32 bits
    std::cout << "Size of uint32_t: " << sizeof(uint32_t) << " bytes" << std::endl;
    assert(sizeof(uint32_t) == 4); // Fails if not 32 bits

    // 2. Test with normal numbers
    uint32_t a = 25;
    uint32_t b = 17;
    uint32_t result = bitwiseAdd(a, b);

    std::cout << "a      = "; printBinary(a);
    std::cout << "b      = "; printBinary(b);
    std::cout << "result = "; printBinary(result);
    std::cout << "Decimal result: " << result << std::endl;

    // 3. Overflow test
    uint32_t x = 0xFFFFFFFF;  // 4294967295
    uint32_t y = 1;
    uint32_t overflow_result = bitwiseAdd(x, y);

    std::cout << "\nOverflow test:\n";
    std::cout << "x      = "; printBinary(x);
    std::cout << "y      = "; printBinary(y);
    std::cout << "result = "; printBinary(overflow_result);
    std::cout << "Decimal result: " << overflow_result << std::endl;

    return 0;
}
