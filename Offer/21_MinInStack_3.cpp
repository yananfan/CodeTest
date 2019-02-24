//#define _MinInStack_3_
#ifdef _MinInStack_3_

#include <iostream>
#include<stack>

using namespace std;

#define MYMAXSIZE 1000
#define NOVALUE 9999

struct minStack {
	int data[MYMAXSIZE];
	int min;
	int top;
};

struct minStack mystack;

int min(struct minStack * s);
void push(int n, struct minStack * s); 
int pop(struct minStack * s); 

int main() {

	mystack.top = -1;
	mystack.min = NOVALUE;
	push(4, &mystack);
	push(2, &mystack);
	push(3, &mystack);
	push(9, &mystack);
	push(1, &mystack);
	push(8, &mystack);

	cout << "+++++++++++++++++++++++++++++++" << endl;
	int i;
	for (i = 0; i < 6; i++) {
		cout << "topV = " << pop(&mystack) << " min = " << min(&mystack) << endl;
	}
	cout << "+++++++++++++++++++++++++++++++" << endl;

	return 0;
}
int min(struct minStack * s) {
	return s->min;
}

void push(int n, struct minStack * s) {
	if (s->min == NOVALUE) {
		s->data[++(s->top)] = 0;
		s->min = n;
	}
	else if (n < s->min) {
		s->data[++(s->top)] = n - s->min;
		s->min = n;
	}
	else {
		s->data[++(s->top)] = n - s->min;
	}
}

int pop(struct minStack * s) {
	if (s->top < 0) return NOVALUE;
	int topV;
	if (s->data[s->top] < 0) {
		topV = s->min;
		s->min = s->min - s->data[s->top];
	}
	else {
		topV = s->min + s->data[s->top];
	}
	s->top--;
	return topV;
}

#endif // _MinInStack_3_