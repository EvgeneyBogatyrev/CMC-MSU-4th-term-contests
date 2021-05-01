#include <iostream>

enum 
{
    MAX_COUNT = 5
};

void printRLE(unsigned char sym, int num)
{
    std::cout << '#'<< sym << std::hex << num << '#';
}

void print(int counter, unsigned char last_char)
{
    if (counter >= MAX_COUNT || last_char == '#') {
        printRLE(last_char, counter);
    } else {
        for (int i = 0; i < counter; ++i) {
            std::cout << last_char;
        }
    }
}

int main()
{
    unsigned char last_char = 0;
    bool last_char_set = false;
    int counter = 0;
    int c;

    while ((c = std::cin.get()) != EOF) {

        unsigned char sym = (unsigned char) c;

        if (!last_char_set) {
            last_char_set = true;
            last_char = sym;
            counter++;
        } else if (sym == last_char) {
            counter++;
        } else {
            print(counter, last_char);
            last_char = sym;
            counter = 1;
        }
    }

    if (last_char_set) {
        print(counter, last_char);
    }

    return 0;
}
