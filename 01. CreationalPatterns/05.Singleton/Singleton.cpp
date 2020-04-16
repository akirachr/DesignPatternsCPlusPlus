#include <iostream>
using namespace std;

class Singleton {
	private:
		static Singleton *instance;
		int data;
 
		Singleton() {
			data = 0;
		}

	public:
		static Singleton *getInstance() {
			if (instance == nullptr)
				instance = new Singleton;
			return instance;
		}

		int getData() {
			return this -> data;
		}

		void setData(int data) {
			this -> data = data;
		}
};

Singleton *Singleton::instance = nullptr;

int main(){
	Singleton *s = s->getInstance();
	s->setData(100);
	cout << s->getData() << endl;
	Singleton *t = t->getInstance();
	cout << t->getData() << endl;
	return 0;
}
