/*************************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the expression 
	from the keyboard, so I am giving that to you. You have to fill in 
	the rest of the main.

	John Dolan	Fall 2016	Ohio University		Home of the Bobcats
*************************************************************************/
#include <stack>
#include <iostream>
#include <cstdlib>
#include "calc_useful.h"
using namespace std;

int main(){
	char c;
	char tmp;
	int onenum, twonum;
	bool continu = true;
	bool error = false;
	// declare an STL stack called nums right here:
	stack<int> nums;

	cout << "Please enter your expression:\n";

	while(continu == true){
		do {
			c = cin.get();
			
			if(isdigit(c)){
				cin.putback(c);
				cin >> onenum;
				// stack operation here.
				nums.push(onenum);
			}
			else if(isop(c)){
				if (nums.empty()) {
					error = true;
				}
				else {
					onenum = nums.top();
					nums.pop();

					if (nums.empty()) {
						error = true;
					}
					else {
						nums.push(onenum);
						error = false;
					}
				}

				if(!error){
					// pop two numbers from the stack
					onenum = nums.top();
					nums.pop();
					twonum = nums.top();
					nums.pop();

					// evaluate them using the evaluate from stack_useful
					onenum = evaluate(twonum, onenum, c);

					// push result onto the stack
					nums.push(onenum);
				}
				else{
					cout << "Error: ";
					cout << "there must be two numbers before an operand" << endl; // what did this error tell us about the user's expression?
					return -1;
				}
			}

			
		} while(c != '\n');  // bottom of the loop that reads a single expression from the keyboard

		// output the final result from the top of the stack
		// but only after you check to make sure there's something on the stack
		if (!nums.empty()) {
			onenum = nums.top();
			nums.pop();

			if (!nums.empty()) {
				cout << "Error: ";
				cout << "there are too many numbers remaining on the stack" << endl;
				return -1;
			}
			else {
				cout << onenum << endl;
			}
		}

		cout << "Enter another equation?(y or n)";
		cin >> tmp;
		cin.ignore();
		if(tmp == 'y' || tmp == 'Y')
			continu = true;
		else
			continu = false;

	}
	return 0;
}