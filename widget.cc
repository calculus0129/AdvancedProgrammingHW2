#include "widget.h"

char label::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if(y || x<0 || x >= s.size() || x >= width) return ' ';
    if(s.size()>width && x+3>=width) return '.';
    return s[x];
}