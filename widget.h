#ifndef WIDGET_H
#define WIDGET_H
#include <string>

class widget {
    public:
    virtual ~widget() {}
    virtual char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const=0;
    //friend void print();
};

class label : public widget {
    std::string s;
    public:
    label(std::string s)
    : s{s} {}
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
};

#endif