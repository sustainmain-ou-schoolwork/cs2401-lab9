#include <string>
#include "chore.h"


void Chore::input(std::istream& ins) {
    std::string lineIn;

    if (&ins == &std::cin) {
        std::cout << "Enter the chore description: ";
    }
    getline(ins, lineIn);
    description = lineIn;


    if (&ins == &std::cin) {
        std::cout << "Enter the chore priority: ";
    }
    ins >> priority;

    // discard extra newline
    ins.ignore();
}

void Chore::output(std::ostream& outs) const {
    if (&outs == &std::cout) {
        std::cout << "Description: ";
    }
    std::cout << description << '\n';


    if (&outs == &std::cout) {
        std::cout << "Priority: ";
    }
    std::cout << priority << '\n';
}

std::istream& operator >> (std::istream& ins, Chore& c) {
    c.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Chore& c) {
    c.output(outs);
    return outs;
}