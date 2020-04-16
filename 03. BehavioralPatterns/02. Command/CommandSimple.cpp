#include <iostream>

using namespace std;

enum CommandName {Register, Modify, Delete};

class Command {
	public:
		Command(){};
		virtual void execute() {};
};

class RegisterCommand:public Command {
	public:
		RegisterCommand(){};
		void execute() {
			cout << "Register" << endl;
		};
};

class ModifyCommand:public Command {
	public:
		ModifyCommand(){};
		void execute() {
			cout << "Modify" << endl;
		};
};

class DeleteCommand:public Command {
	public:
		DeleteCommand(){};
		void execute() {
			cout << "Delete" << endl;
		};
};

class CommandProvider {
	static Command* cache[];
	public:
		static Command* getCommand(CommandName commandName) {
			return cache[commandName];
		};
};

Command* CommandProvider::cache[3] = {new RegisterCommand(), new ModifyCommand(), new DeleteCommand()};

int main() {
	CommandName commandName = Register;
	Command* command = CommandProvider::getCommand(commandName);
	command->execute();
	return 0;
} 
