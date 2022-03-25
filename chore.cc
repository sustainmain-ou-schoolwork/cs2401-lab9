#include <string>
#include "chore.h"


void Chore::input(std::istream& ins) {

}

void Chore::output(std::ostream& outs) const {

}

std::istream& operator >> (std::istream& ins, Chore& c) {
    c.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Chore& c) {
    c.output(outs);
    return outs;
}