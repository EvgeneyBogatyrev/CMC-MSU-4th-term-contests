#include <iostream>

int main()
{
    int count;
    std::cin >> count;
    
    Holder *holders = new Holder[count];

    for (int i = 0; i < count / 2; ++i) {
        holders[i].swap(holders[count - i - 1]);
    }

    delete [] holders;
}
