/*
S -> aTd
T -> aTd | bPc
P -> bPc | eps
*/

#include <iostream>

void P(int length)
{
    if (length < 2) {
        return;
    }

    std::cout << "b";
    P(length - 2);
    std::cout << "c";
}

void T(int length, int amount_of_ad)
{
    if (amount_of_ad > 0) {
        std::cout << "a";
        T(length - 2, amount_of_ad - 1);
        std::cout << "d";
    } else {
        std::cout << "b";
        P(length - 2);
        std::cout << "c";
    }
}

void S(int length, int amount_of_ad)
{
    if (length < 4 || length % 2 == 1 || amount_of_ad <= 0) {
        return;
    }

    std::cout << "a";
    T(length - 2, amount_of_ad - 1);
    std::cout << "d" << std::endl;

    S(length, amount_of_ad - 1);
}


int main()
{
    int k;
    std::cin >> k;
    if (k < 4 || k % 2 != 0) {}
    else {
        S(k, k / 2 - 1);
    }
    return 0;
}
