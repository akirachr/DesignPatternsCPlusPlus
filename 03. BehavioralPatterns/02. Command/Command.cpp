#include <iostream>
#include <map>

using namespace std;

class Command {
	public:
		Command(){};
		virtual void execute() = 0;
};

class RegisterCommand: public Command {
	public:
		RegisterCommand(){};
		void execute() {
			cout << "Regsiter" << endl;
		};
};

class ModifyCommand: public Command {
	public:
		ModifyCommand(){};
		void execute() {
			cout << "Modify" << endl;
		};
};

class DeleteCommand: public Command {
	public:
		DeleteCommand(){};
		void execute() {
			cout << "Delete" << endl;
		};
};

class CommandProvider {
	private:
		static CommandProvider* instance;
		map<string, Command*> commands;
		map<string, Command*>::iterator ite;

		CommandProvider() {
			commands["Register"] = new RegisterCommand();
			commands["Modify"] = new ModifyCommand();
			commands["Delete"] = new DeleteCommand();
		};
	public:
		static CommandProvider* getInstance() {
			return instance;
		};
		Command* getCommand(string key) {
			ite = commands.find(key);
			return ite->second;
		};
};

CommandProvider* CommandProvider::instance = new CommandProvider();

int main() {
	CommandProvider* commandProvider = CommandProvider::getInstance();
	Command* command = commandProvider->getCommand("Register");
	command->execute();
	cout << " " << endl;
	
	command = commandProvider->getCommand("Modify");
	command->execute();
	
	return 0;
}
