#include <queue>
#include <iostream>
#include "chore.h"
#include "calc_useful.h"
using namespace std;

int main() {
    priority_queue<Chore> chores;
    Chore tmp;

    // read in 5 chores
    for (int i = 0; i < 5; i++) {
        cin >> tmp;
        chores.push(tmp);
    }

    // display 5 chores
    for (int i = 0; i < 5; i++) {
        cout << chores.top();
        chores.pop();
    }
}