#include "widget.h"

char label::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if(y || x<0 || x >= s.size() || x >= width) return ' ';
    if(s.size()>width && x+3>=width) return '.';
    return s[x];
}

char checkerboard::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if(x<0 || y<0 || x>=width || y>=height) return ' '; // exceptional case. Not considered in the assignment02.pdf.
    return (x+y)&1?a:b; // considering the Example in the pdf file description of main03-bin
}

char stretchy::char_at(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const {
    if(x<0 || y<0 || x>=width || y>=height) return ' '; // exceptional case. Not considered in the assignment02.pdf.
    return (y==0 || y==height-1)?'.':((y==1 || y==height-2)?':':'|');
}