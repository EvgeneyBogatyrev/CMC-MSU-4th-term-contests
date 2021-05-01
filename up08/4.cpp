#include <iostream>
#include <cstring>
#include <string>


class Impl
{
    struct BlockContent
    {
        char *str = nullptr;
        size_t str_size = 0;
        size_t holders = 0;
    };

    BlockContent *content;

public:
    class Iteration;
    Iteration operator[](size_t ind);

    void get_content() 
    {
        BlockContent *new_block = new BlockContent;

        new_block->str = new char[content->str_size];
        snprintf(new_block->str, content->str_size, "%s", content->str);

        new_block->str_size = content->str_size;
    
        new_block->holders = 1;
        content->holders--;

        content = new_block;
    }

    Impl() 
    {
        content = new BlockContent;
        content->str = new char[1];
        content->str[0] = '\0';
        content->str_size = 1;
        content->holders = 1;
    }

    Impl(const char * str) 
    {
        content = new BlockContent;
        size_t len = strlen(str) + 1;
        content->str_size = len;

        content->str = new char[len];
        snprintf(content->str, len, "%s", str);

        content->holders = 1;
    }

    Impl(const Impl& other) 
    {
        content = other.content;    
        content->holders++;
    }   

    ~Impl()
    {
        if (content) {
            content->holders--;
            if (content->holders == 0) {   
                delete [] content->str;
                delete content;
            }
        }
    }

    Impl& operator=(const Impl& other)
    {
        if (this != &other) {
            content->holders--;
            if (content->holders == 0) {
                delete [] content->str;
                delete content;
            }

            content = other.content;
            content->holders++;
        }
        return *this;
    }

    Impl& operator+=(const Impl& other)
    {
        if (content->holders > 1) {
            get_content();
        }   
        size_t new_len = content->str_size + other.content->str_size - 1;

        char *new_str = new char[new_len];
        content->str_size = new_len;

        snprintf(new_str, new_len, "%s%s", content->str, other.content->str);
    
        delete [] content->str;
        content->str = new_str;
        return *this;
    }

    operator std::string() const 
    {
        return std::string(content->str);
    }
};


class Impl::Iteration
{
    friend Impl::Iteration Impl::operator[](size_t ind);
    Impl *pImpl = nullptr;
    size_t ind = 0;
    Iteration(Impl *p, size_t size);
public:
    operator char() const;
    Iteration& operator=(char symbol);
    Iteration& operator=(const Iteration& other);
};


Impl::Iteration::Iteration(Impl *p, size_t size) 
{
    pImpl = p;
    ind = size;
}

Impl::Iteration::operator char() const
{
    return pImpl->content->str[ind];
}

Impl::Iteration& Impl::Iteration::operator=(char symbol)
{
    if (pImpl->content->holders > 1) {
        pImpl->get_content();
    }
    pImpl->content->str[ind] = symbol;
    return *this;
}

Impl::Iteration& Impl::Iteration::operator=(const Iteration& other)
{
    if (pImpl->content->holders > 1) {
        pImpl->get_content();
    }
    pImpl->content->str[ind] = char(other);
    return *this;
}

auto Impl::operator[](size_t ind)->Impl::Iteration
{
    return Iteration(this, ind); 
}


class String
{
    Impl *pImpl = nullptr;
public:
    String();
    String(const char *str);
    String(const String &other);
    String(String &&other);
    ~String();
    String& operator=(const String& other);
    String& operator=(String&& other);
    String& operator+=(const String& other);
    operator std::string();
    Impl::Iteration operator[](size_t ind);
    char operator[](size_t) const;
};


String::String()
{
    pImpl = new Impl();
}

String::String(const char *init) 
{
    pImpl = new Impl(init);
}

String::String(const String &other)
{
    pImpl = new Impl(*other.pImpl);
}

String::String(String&& other)
{
    pImpl = other.pImpl;
    other.pImpl = nullptr;
}

String::~String()
{
    delete pImpl;
}

String& String::operator=(const String& other)
{
    *pImpl = *other.pImpl;
    return *this;
}

String& String::operator=(String&& other) 
{
    if (this != &other) {        
        delete pImpl;
        pImpl = other.pImpl;
        other.pImpl = nullptr;
    }
    return *this;
}

String& String::operator+=(const String& other)
{
    *pImpl += *other.pImpl;
    return *this;
}

String::operator std::string() {
    return std::string(*pImpl);
}

Impl::Iteration String::operator[](size_t ind)
{
    return (*pImpl)[ind];
}

char String::operator[](size_t ind) const 
{
    return (*pImpl)[ind];
}

