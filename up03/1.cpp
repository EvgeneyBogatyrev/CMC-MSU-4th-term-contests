#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

enum { PRECISION = 10 };

namespace numbers
{
    class complex
    {
        double re_{};
        double im_{};
    public:
        complex (double re = {}, double im = {}) : re_{re}, im_{im} {}
        
        explicit complex (std::string str) noexcept
        {
            int coma_index = str.find(',');
            std::string real = str.substr(1, coma_index - 1);
            std::string img = str.substr(coma_index + 1, str.length() - coma_index - 2);

            re_ = std::stod(real);
            im_ = std::stod(img);
        }

        double re() const noexcept
        {
            return re_;
        }

        double im() const noexcept
        {
            return im_;
        }

        double abs2() const noexcept
        {
            return re_ * re_ + im_ * im_;
        }

        double abs() const noexcept
        {
            return sqrt(abs2());
        }

        std::string to_string() const noexcept
        {
            std::ostringstream stream;
            stream << std::setprecision(PRECISION);
            stream << '(' << re_ << ',' << im_ << ')';
            return stream.str();
        }

        complex &operator += (complex other) noexcept
        {
            re_ += other.re_;
            im_ += other.im_;
            return *this;
        }

        complex &operator -= (complex other) noexcept
        {
            re_ -= other.re_;
            im_ -= other.im_;
            return *this;
        }

        complex &operator *= (complex other) noexcept
        {
            double re_saved = re_;
            double im_saved = im_;
            re_ = re_saved * other.re_ - im_saved * other.im_;
            im_ = re_saved * other.im_ + im_saved * other.re_;
            return *this;
        }

        complex &operator /= (complex other) noexcept
        {
            double re_saved = re_;
            double im_saved = im_;
            re_ = (re_saved * other.re_ + im_saved * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_);
            im_ = (other.re_ * im_saved - re_saved * other.im_) / (other.re_ * other.re_ + other.im_ * other.im_);
            return *this;
        }

        complex operator ~ () const noexcept
        {
            return complex(re_, -im_);
        }

        complex operator - () const noexcept
        {
            return complex(-re_, -im_);
        }

    };

    inline complex operator + (complex z1, complex z2)
    {
        z1 += z2;
        return z1;
    }

    inline complex operator - (complex z1, complex z2)
    {
        z1 -= z2;
        return z1;
    }
    
    inline complex operator * (complex z1, complex z2)
    {
        z1 *= z2;
        return z1;
 
    }
    
    inline complex operator / (complex z1, complex z2)
    {
        z1 /= z2;
        return z1;
    }

}
