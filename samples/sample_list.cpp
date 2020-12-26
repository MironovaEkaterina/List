#include "list.h"

template<class T>
void DeleteMiddleElem(List<T>& list) {
	int kol = 0;
	for (auto i = list.begin(); i != list.end(); ++i)
		kol++;
	auto iter = list.begin();
	if (kol % 2 == 1) {
		for (int i = 1; i < (kol - 1) / 2; i++)
			++iter;
		list.DeleteNextElem(iter);
	}
	if (kol % 2 == 0) {
		for (int i = 1; i < (kol - 2) / 2; i++)
			++iter;
		list.DeleteNextElem(iter);
		list.DeleteNextElem(iter);
	}
}


int main() {
	List<int> list;
	std::cout << "First example:\n";
	list.push_back(3);
	list.push_front(2);
	list.push_front(1);
	list.push_front(0);
	list.PrintList();
	std::cout << std::endl;
	DeleteMiddleElem(list);
	std::cout << "Delete middle elements:\n";
	list.PrintList();
	std::cout << "\nSecond example:\n";
	list.push_front(3);
	list.PrintList();
	std::cout << std::endl;
	DeleteMiddleElem(list);
	std::cout << "Delete middle elements:\n";
	list.PrintList();
	return 0;
}