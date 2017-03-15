
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <string>
#include <time.h>

using namespace std;

const int MAX = 5;

class queue {
private:
	int data[MAX];
	int f, l;
public:
	queue() {
		f = 0, l = 0;
	}

	~queue() {
		clear();
	}

	void clear() {
		f = 0, l = 0;
	}


	bool pop(int & v) {
		if (isEmpty())
			return 0;

		v = data[f];
		for (int i = 0; i < l; i++)
			data[i] = data[i + 1];
		l--;
		return 1;
	}

	int peek() {
		if (isEmpty())
			return  -1;
		return data[f];
	}

	inline bool isFull(){ return l == MAX; }
	inline bool isEmpty(){ return l == 0; }
	inline int getLength() { return l; }

	bool push(int v) {
		if (isFull())
			return 0;

		data[l++] = v;
		return 1;
	}

	void print() {
		printf("FRONT -> ");
		for (int i = f; i < l; i++)
			printf("%d%s", data[i], i == l - 1 ? "" : " , ");
		puts("");
	}
};

class cqueue {
private:
	int data[MAX];
	int f, l, len;
public:
	cqueue() {
		f = 0, l = 0, len = 0;
	}

	~cqueue() {
		clear();
	}

	void clear() {
		f = 0, l = 0, len = 0;
	}


	bool pop(int & v) {
		if (isEmpty())
			return 0;
		v = data[f];
		f = (f + 1) % MAX;
		len--;
		return 1;
	}

	int peek() {
		if (isEmpty())
			return  -1;
		return data[f];
	}

	inline bool isFull(){ return len == MAX; }
	inline bool isEmpty(){ return len == 0; }
	inline int getLength() { return len; }

	bool push(int v) {
		if (isFull())
			return 0;

		data[l++] = v;
		l %= MAX;

		len++;

		return 1;
	}

	void print() {
		printf("FRONT -> ");
		for (int i = f, j = 0; j < len; j++, i = (i + 1) % MAX)
			printf("%d%s", data[i], j == len - 1 ? "" : " , ");
		puts("");
	}
};


int main() {
	cqueue q;

	q.push(10);
	q.push(0);
	q.push(3);
	q.push(5);
	q.push(4);

	q.print();

	int x;
	q.pop(x);
	q.pop(x);

	q.print();

	q.push(2);
	q.push(1);

	q.print();
	printf("First Element: %d\n", q.peek());

	puts("Pop All Elements..");
	int v = 0;
	while (q.pop(v))
		printf("%d\n", v);

	return 0;
}
