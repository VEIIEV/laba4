#include <iostream>
#include "doublesidequeue.h"
using namespace std;

int main()
{
	DoubleSideQueue<int> queue_1;
	queue_1.print();
	cout << "\n";
	queue_1.pushBack(1);
	queue_1.pushBack(2)
	queue_1.pushFront(3);
	queue_1.print();
	cout << "\nFront: " << queue_1.topFront() << "\tBack: " << queue_1.topBack() << "\n\n";
	queue_1.popBack();
	queue_1.print();
	cout << "\n";
	queue_1.popFront();
	queue_1.print();
	cout << "\n";

	DoubleSideQueue<int> queue_2(queue_1);
	queue_2.print();dsd
	cout << "\n";
	queue_2.clear();
	queue_2.print();
	cout << "\n";
	queue_2 = queue_1;
	queue_2.print();
	return 0;
}
