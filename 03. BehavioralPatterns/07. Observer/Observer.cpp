#include <iostream>
#include <vector>
using namespace std;

class Observer;

class Subject {
	private:
		vector<Observer*> observers;
		string name;
	public:
		Subject() {
		}
		void attach(Observer* observer) {
			observers.push_back(observer);
		}
		void setName(string value) {
			name = value;
			notify();
		}
		string getName() {
			return name;
		}
		void notify();
};

class Observer {
	private:
		Subject* subject;
	protected:
		Subject* getSubject() {
			return subject;
		};
	public:
		Observer(Subject* value) {
			subject = value;
			subject->attach(this);
		}
		virtual void update(){};
};

void Subject::notify() {
	for(int i = 0; i < observers.size(); i++) {
		observers[i]->update();
	};
};

class XObserver:public Observer {
	public:
		XObserver(Subject* subject):Observer(subject) {
		}
		void update() {
			string name = getSubject()->getName();
			cout << name + "X" << endl;
		};
};

class YObserver:public Observer {
	public:
		YObserver(Subject* subject):Observer(subject) {
		}
		void update() {
			string name = getSubject()->getName();
			cout << name + "Y" << endl;
		};
};

int main() {
	Subject* subject = new Subject();
	subject->setName("Test");
	XObserver* xObserver = new XObserver(subject);
	YObserver* yObserver = new YObserver(subject);
	subject->notify();

	return 0;
};

