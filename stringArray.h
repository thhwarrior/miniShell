#include <string>
using namespace std;

struct stringArray {
	string* array;
	int length;
	stringArray(string* arr, int length) : array(arr), length(length) {}
	~stringArray() { delete[] array; }
	const char* get(int i) { return array[i].c_str(); }
};
