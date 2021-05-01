#include <iostream>
#include <string>


class BinaryNumber
{
private:
    std::string str;
public:
    BinaryNumber(const std::string &s)
    {
        str.clear();
        size_t len = s.length();
        for (size_t i = 0; i < len; ++i) {
            str += s[i];
        }
    }

    operator std::string() const
    {
        return str;
    }

    const BinaryNumber &operator++()
    {
        int len = str.length();

        for (int i = len - 1; i >= 0; --i) {
            if (str[i] == '0') {
                str[i] = '1';
                return *this;
            } else {
                str[i] = '0';
            }
        }

        str.resize(len + 1);
        str[0] = '1';
        for (int i = 0; i < len; ++i) {
            str[i + 1] = '0';
        }

        return *this;
    }
};
