#ifndef WIDGET_H
#define WIDGET_H
#include <string>

class widget {
    public:
    virtual ~widget() {}
    virtual char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const=0;
    virtual widget* copy() const=0;
    //friend void print();
};

class label : public widget {
    std::string s;
    public:
    label(std::string s)
    : s{s} {}
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
    widget* copy() const {return new label(*this);}
};

class checkerboard : public widget {
    char a, b;
    public:
    checkerboard(char a, char b)
    : a{a}, b(b) {

    }
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
    widget* copy() const {return new checkerboard(*this);}
};

class stretchy : public widget {
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
    public: widget* copy() const { return new stretchy(*this); }
};

class vertical_split : public widget {
    widget *t, *b;
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
    public:
    vertical_split(widget *a, widget *b): t(a), b{b} {}
    ~vertical_split() { delete t; delete b; }
    // Copy Constructor
    vertical_split(const vertical_split& o) : t(o.t->copy()), b{o.b->copy()} {}
    // Assignment Operator
    vertical_split& operator=(const vertical_split &o);
    widget* copy() const { return new vertical_split(*this); };
};

class window : public widget {
    widget *aw;
    char char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const;
    public:
    ~window() { delete aw; }
    window(widget* aw) : aw(aw) {}
    window(const window &w) : aw{w.aw->copy()} {}
    window& operator=(window const &w);
    window* copy() const { return new window(*this); }
};

#endif