#include <iostream>

using namespace std;

template <class T>
class Iterator;

class Product {
	private:
		string name;
	public:
		Product(){};
		~Product(){};
		void setName(string value) {
			name = value;
		};
		string getName() {
			return name;
		};
};

template <class T>
class List{
	private:
		T* items[10];
		int sp;
	public:
		friend class Iterator<T>;
		List() {
			sp = -1;
		};
		~List(){};

		void add(T* value) {
			items[++sp] = value;
		};

		int size() {
			return sp + 1;
		};
		T* get(int i) {
			return items[i];
		};
		Iterator<T>* iterator();
};

template <class T>
class Iterator {
	private:
		List<T>* list;
		int index;
	public:
		Iterator(List<T>* value) {
			list = value;
			index = 0;
		};
		~Iterator(){};
		bool hasNext() {
			return index <= list->sp;
		};
		T* next() {
			return list->items[index++];
		};
};

template <class T>
Iterator<T>* List<T>::iterator() {
	return new Iterator<T>(this);
};

int main() {
	Product* p1 = new Product();
	p1->setName("Taro");
	Product* p2 = new Product();
	p2->setName("Jiro");
	List<Product>* list = new List<Product>();
	list->add(p1);
	list->add(p2);
	for(int i = 0; i < list->size(); i++) {
		Product* p = list->get(i);
		cout << p->getName() << endl;
	}
	Iterator<Product>* iterator = list->iterator();
	while(iterator->hasNext()) {
		Product* p = iterator->next();
		p->setName(p->getName() + "X");
	};
	for(int i = 0; i < list->size(); i++) {
		Product* p = list->get(i);
		cout << p->getName() << endl;
	}
}
