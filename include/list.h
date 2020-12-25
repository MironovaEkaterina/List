#include <iostream>

template<class T> struct Node
{
	T data;
	Node<T>* next;
};

template<class T>
class List {
private:
	Node<T>* head;
	Node<T>* last;
public:
	List() {
		head = NULL;
		last = NULL;
	}

	~List() {
		if (head != NULL) {
			Node<T>* current = head;
			while (current->next != NULL) {
				current = current->next;
				delete head;
				head = current;
			}
		}
	}

	List(const List& list) {
		head = NULL;
		last = NULL;
		Node<T>* current = head;
		for (iterator iter = list.begin(); iter != list.end(); ++iter)
			push_back(iter.current->data);
	}
	
	T GetFirst() { return head->data; }

	T GetLast() { return last->data; }

	void push_front(T d) {
		Node<T>* n = new Node<T>;
		n->data = d;
		n->next = head;
		head = n;
		if (last == NULL) last = head;
	}

	void push_back(T d) {
		if (last == NULL) push_front(d);
		else {
			Node<T>* n = new Node<T>;
			n->data = d;
			n->next = NULL;
			last->next = n;
			last = n;
		}
	}

	void pop_front() {
		if ((*this).IsEmpty()) throw std::logic_error("List is empty");
		Node<T>* tmp = head;
		head = tmp->next;
		delete tmp;
		if (head == NULL) last = NULL;
	}

	void pop_back() {
		if ((*this).IsEmpty()) throw std::logic_error("List is empty");
		if (head != last) {
			Node<T>* current = head;
			while (current->next != last)
				current = current->next;
			std::swap(current, last);
			delete current;
			last->next = NULL;
		}
		else pop_front();
	}

	void PrintList() {
		for (iterator iter = begin(); iter != end(); ++iter) {
			std::cout << iter.current->data << ' ';
		}
	}

	bool IsEmpty() {
		return head == NULL;
	}

	class iterator {
	public:
		Node<T>* current;
		iterator() { current = head; }
		iterator(Node<T>* n) { current = n; }
		iterator(const iterator& iter) { current = iter.current; }
		Node<T>*& operator*() { return current; }
		Node<T>*& operator->() { return current; }
		iterator operator++() {
			if (current != NULL)
				current = current->next;
			return *this;
		}
		bool operator==(const iterator& iter) {
			return iter.current == current;
		}
		bool operator!=(const iterator& iter) {
			return iter.current != current;
		}
	};
	iterator begin() const {
		iterator iter(head);
		return iter;
	}
	iterator end() const{
		iterator iter(NULL);
		return iter;
	}

	void DeleteNextElem(iterator iter) {
		if ((*this).IsEmpty()) throw std::logic_error("List is empty");
		if (iter != end()) {
			iterator tmp(iter);
			++tmp;
			iter.current->next = tmp->next;
			delete tmp.current;
		}
	}
};