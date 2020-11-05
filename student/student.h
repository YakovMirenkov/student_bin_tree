#ifndef STUDENT_H
#define STUDENT_H

#include <cstdio>

class student
{
private:
	char *name = nullptr;
	int value = 0;

public:
	enum ERRORS
	{
		SUCCESS,
		EOF_ERROR,
		READ_ERROR,
		ALLOC_ERROR
	};

	int get_value() const { return value; }
	const char *get_name() const { return const_cast<const char *>(name); }
	int init(const char *new_name, int new_value);
	void rm();
	student(const char *new_name = nullptr, int new_value = 0) { init(new_name, new_value); }
	student(const student &x) { init(x.name, x.value); }
	student(student &&x) { name = x.name; x.name = nullptr; value = x.value; }
	~student() { rm(); }
	student &operator=(const student &x);
	student &operator=(student &&x);
	int operator>(const student &x) const;
	long long int cmp(const student &x) const;
	void swap(student &x);
	int read(FILE *in);
	void print() const;
};

#endif// STUDENT_H
