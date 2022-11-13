#include <iostream>
#include <List>
#include <cmath>
using namespace std;

template<class T>
class LLstack {
public :
	LLstack() {
	}
	void clear() {
		lst.clear();
	}
	bool isEmpty() const {
		return lst.empty();
	}
	T& topEl() {
		return lst.back();
	}
	T pop() {
		T el = lst.back();
		lst.pop_back();
		return el;
	}

	void push(const T& el) {
		lst.push_back(el);
	}
	int size();

private :
	list<T> lst;
};

template<class T>
int LLstack<T> ::size() {
	return lst.size();
}

int main() {

	LLstack<int> stack1;
	LLstack<int> stack2;
	LLstack<int> result;
	int mop1, mop2, stackresult = 0, n;
	int i = 0, tmp;

	cout << "두 개의 숫자를 입력하세요." << endl;
	cin >> mop1;
	tmp = mop1;
	while (tmp != 0) {
		tmp /= 10;
		i++;
	}

	while (i>0) {
		n = pow(10, i-1);
		tmp = mop1 / n;
		stack1.push(tmp);
		mop1 = mop1 % n;
		i--;
	}

	i = 0;
	cin >> mop2;
	tmp = mop2;
	while (tmp != 0) {
		tmp /= 10;
		i++;
	}

	while (i>0) {
		n = pow(10, i-1);
		tmp = mop2 / n;
		stack2.push(tmp);
		mop2 = mop2 % n;
		i--;
	}

	if (stack1.size() >= stack2.size()) {
		while (!stack1.isEmpty()) {
			if (!stack2.isEmpty()) {
				tmp = stack1.topEl() + stack2.topEl();
				result.push(tmp);
				stack1.pop();
				stack2.pop();
			}
			else {
				tmp = stack1.topEl();
				result.push(tmp);
				stack1.pop();
			}
		}
	}

	else {
		while (!stack2.isEmpty()) {
			if (!stack1.isEmpty()) {
				tmp = stack1.topEl() + stack2.topEl();
				result.push(tmp);
				stack1.pop();
				stack2.pop();
			}
			else {
				tmp = stack2.topEl();
				result.push(tmp);
				stack2.pop();
			}
		}
	}

	while (!result.isEmpty()) {
		stackresult += result.topEl() * pow(10, result.size()-1);
		result.pop();
	}

	cout << "두수를 더한 값은 : " << stackresult;

}