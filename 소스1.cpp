
#include "calss.h"
int main() {
	priority_queue<int> program;

	program.push(-1);
	program.push(2);
	program.push(1);
	program.push(9);
	program.push(0);


	program.print();

	program.pop();
	cout << program.top() << '\n';
	program.pop();
	cout << program.top() << '\n';
	program.pop();
	cout << program.top() << '\n';

	program.print();
}