#include <iostream>
#include <inttypes.h>

enum
{
    BYTE_NUM = 4,
    ZERO_CODE = '0',
    NINE_CODE = '9',
    A_CODE = 'a',
    SPACE_CODE = ' ',
    OFFSET = 10,
    BITS_NUM = 8,
    NUMBERS_IN_LINE = 4
};

unsigned char get_num(unsigned char symbol)
{
    if (ZERO_CODE <= symbol && symbol <= NINE_CODE) {
        return symbol - ZERO_CODE;
    }
    return symbol - A_CODE + OFFSET;
}

bool read_offset()
{
    int c;
    while ((c = std::cin.get()) != EOF) {
        unsigned char symbol = (unsigned char) c;
        if (symbol == SPACE_CODE) {
            return true;
        }
    }
    return false;
}

bool read_number()
{
    uint32_t number = 0;
    for (int i = 0; i < BYTE_NUM; ++i) {
        uint8_t byte = 0;
        
        int c = std::cin.get();
        if (c == EOF) {
            return false;
        }
        unsigned char symbol = (unsigned char) c;
        byte |= get_num(symbol);
        byte <<= BITS_NUM/2;

        c = std::cin.get();
        symbol = (unsigned char) c;
        byte |= get_num(symbol);

        std::cin.get(); //skip space

        number <<= BITS_NUM;
        number |= byte;
    }
    std::cout << number << std::endl;
    return true;
}

int main()
{
    while (true) {
        if (!read_offset()) {
            break;
        }
        bool flag = true;
        for (int i = 0; i < NUMBERS_IN_LINE; ++i) {
            if (!read_number()) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    return 0;
}
