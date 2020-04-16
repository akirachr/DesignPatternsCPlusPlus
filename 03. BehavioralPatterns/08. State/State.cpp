#include <iostream>
#include <map>

using namespace std;

class State;

class Contract {
	private:
		State* state;
		map<string, State*> states;
		map<string, State*>::iterator ite;
	public:
		Contract();
		string getStateName();
		void execute();
		void setState(string state);
};

class State {
	public:
		State() {};
		void execute(Contract* contract) {
			doExecute();
			goNextState(contract);
		}

		virtual string getStateName() = 0;
		virtual void doExecute() = 0;
		virtual void goNextState(Contract* contract) = 0;
};

class CreateState:public State {
	public:
		CreateState() {
		};
		~CreateState() {};
		string getStateName() {
			return "CREATE";
		};
		void doExecute() {
			cout << "A contract has been created." << endl;
		};
		void goNextState(Contract* contract) {
			contract->setState("REVIEW");
		}
};

class ReviewState:public State {
	public:
		ReviewState() {
		};
		~ReviewState() {};
		string getStateName() {
			return "REVIEW";
		};
		void doExecute() {
			cout << "A contract has been reviewed." << endl;
		};
		void goNextState(Contract* contract) {
			contract->setState("APPROVE");
		}
};

class ApproveState:public State {
	public:
		ApproveState() {
		};
		~ApproveState() {};
		string getStateName() {
			return "APPROVE";
		};
		void doExecute() {
			cout << "A contract has been approved." << endl;
		};
		void goNextState(Contract* contract) {
		}
};

Contract::Contract() {
	states["REVIEW"] = new ReviewState();
	states["APPROVE"] = new ApproveState();
	state = new CreateState();
};
string Contract::getStateName() {
	return state->getStateName();
};
void Contract::execute() {
	state->execute(this);
};
void Contract::setState(string value) {
	ite = states.find(value);
	state = ite->second;
};

int main() {
	Contract* contract = new Contract();
	cout << contract->getStateName() << endl;
	contract->execute();
	cout << contract->getStateName() << endl;
	contract->execute();
	cout << contract->getStateName() << endl;
	contract->execute();

	return 0;
}
