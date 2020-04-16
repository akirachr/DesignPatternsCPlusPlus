#include <iostream>
#include <string>
using namespace std;

class Visitor;

class Process {
	public:
		virtual void accept(Visitor* visitor) = 0;
};

class ProcessX:public Process {
	public:
		void accept(Visitor* visitor);
		void startup() {
			cout << "ProcessX started." << endl;
		};
		void shutdown() {
			cout << "ProcessX shut down." << endl;
		}
};

class ProcessY:public Process {
	public:
		void accept(Visitor* visitor);
		void startup() {
			cout << "ProcessY started." << endl;
		};
		void shutdown() {
			cout << "ProcessX shut down." << endl;
		}
};

class Visitor {
	public:
		virtual void visit(ProcessX* process) = 0;
		virtual void visit(ProcessY* process) = 0;
};

void ProcessX::accept(Visitor* visitor) {
	visitor->visit(this);
}

void ProcessY::accept(Visitor* visitor) {
	visitor->visit(this);
}

class StartupVisitor:public Visitor {
	void visit(ProcessX* process) {
		process->startup();
	};
	void visit(ProcessY* process) {
		process->startup();
	}
};

class ShutdownVisitor:public Visitor {
	void visit(ProcessX* process) {
		process->shutdown();
	};
	void visit(ProcessY* process) {
		process->shutdown();
	}
};

int main() {
	Process* processes[] = {new ProcessX(), new ProcessY()};
	Visitor* startupVisitor = new StartupVisitor();
	Visitor* shutdownVisitor = new ShutdownVisitor();
	for( int i = 0; i < 2; i++ ) {
		processes[i]->accept(startupVisitor);
	}
	for( int i = 0; i < 2; i++ ) {
		processes[i]->accept(shutdownVisitor);
	}
	
	return 0;
}
