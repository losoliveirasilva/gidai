#ifndef MODIFIER_H
#define MODIFIER_H

#include <ostream>
namespace Color {
    enum Code {
        STRIKE      = 9,
        RES_STRIKE  = 29,
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_YELLOW   = 33,
        FG_BLUE     = 34,
        FG_MAGENTA  = 35,
        FG_CYAN     = 36,
        FG_LGRAY    = 37,
        FG_DEFAULT  = 39,
        FG_DGRAY    = 90,
        FG_LRED     = 91,
        FG_LGREEN   = 92,
        FG_LYELLOW  = 93,
        FG_LBLUE    = 94,
        FG_LMAGENTA = 95,
        FG_LCYAN    = 96,
        FG_WHITE    = 97
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif
