#ifndef CHORE_H
#define CHORE_H

#include <iostream>
#include <string>

class Chore {
    public:
        Chore(std::string d = "", int p = 0);

        bool operator < (const Chore& c) const {return priority < c.priority;}

        void input(std::istream& ins);
        void output(std::ostream& outs) const;
    private:
        std::string description;
        int priority;
};

std::istream& operator >> (std::istream& ins, Chore& c);
std::ostream& operator << (std::ostream& outs, const Chore& c);

#endif