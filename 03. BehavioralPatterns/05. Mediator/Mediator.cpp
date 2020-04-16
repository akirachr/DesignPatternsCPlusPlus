#include <iostream>

using namespace std;

enum {X, Y};

class Mediator;

class Process {
	private:
		Mediator* mediator;
	public:
		Process(Mediator* value) {
			mediator = value;
		}
		virtual void changed(string data);
		virtual void updateProcess(string data) = 0;
};

class ProcessX:public Process {
	public:
		ProcessX(Mediator* mediator):Process(mediator) {
		}
		void updateProcess(string data) {
			cout << "ProcessX got " + data << endl;
		};
};

class ProcessY:public Process {
        public:
                ProcessY(Mediator* mediator):Process(mediator) {
                }
                void updateProcess(string data) {
                        cout << "ProcessY got " + data << endl;
                };
};

class Mediator{
	private:
		Process* processes[2];
	public:
		Mediator() {
			processes[X] = new ProcessX(this);
			processes[Y] = new ProcessY(this);
		}
		Process* deliverProcess(int which) {
			return processes[which];
		};
		void processExecuted(Process* process, string data) {
			if(process== processes[X]) {
				processes[Y]->updateProcess(data);
			}
			else if(process == processes[Y]) {
				processes[X]->updateProcess(data);
			}
		};
};

void Process::changed(string data) {
	mediator->processExecuted(this, data);
};

int main() {
	Mediator* mediator = new Mediator();
	Process* processX = mediator->deliverProcess(X);
	Process* processY = mediator->deliverProcess(Y);
	processX->changed("Taro");
	
	return 0;
}
