#include <iostream>

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

template<class T>
struct Entry {
	string key;
	T* value;
};

template<class T>
void arraycopy(Entry<T>* source, int sourcePosition, Entry<T>* destination, int destinationPosition, int length) {
	for(int i = 0; i < length; i++) {
		destination[destinationPosition + i] = source[sourcePosition + i];
	};
};

template<class T>
class Dictionary {
	private:
		Entry<T>* entries;
		int size;
	public:
		Dictionary() {
			size = 0;
			entries = new Entry<T>[0];
		};
		void add(string key, T* t) {
			bool hit = false;
			int pos = 0;
			for(int i = 0; i < size; i++) {
				if(entries[i].key == key) {
					pos = i;
					hit = true;
					break;
				};
			};
			if(hit) {
				entries[pos] = (Entry<T>){key, t};
			} else {
				Entry<T>* temp = new Entry<T>[size + 1];
				arraycopy(entries, 0, temp, 0, size);
				temp[size] = (Entry<T>){key, t};
				size++;
				entries = temp;
			};
		};
		T* getValue(string key) {
			Entry<T> entry;
			for(int i = 0; i < size; i++) {
				if(entries[i].key == key) {
					entry = entries[i];
					break;
				};
			};
			return entry.value;
		};
		void deleteEntry(string key) {
			int pos = 0;
			bool hit = false;
			for(int i = 0; i < size; i++) {
				if(entries[i].key == key) {
					pos = i;
					hit = true;
					break;
				}
			};
			if(hit) {
				size--;
				Entry<T>* temp = new Entry<T>[size];
				arraycopy(entries, 0, temp, 0, pos);
				arraycopy(entries, pos + 1, temp, pos, size - pos);
				entries = temp;
			};
		};
		void printKeys() {
			for(int i = 0; i < size; i++) {
				auto [key, value] = entries[i];
				cout << key << endl;
			};
		};
		int length() {
			return size;
		};
		Entry<T>* getEntries() {
			return entries;
		};
};

class CommandProvider {
	private:
		static CommandProvider* instance;
		Dictionary<Command>* dictionary;

		CommandProvider() {
			dictionary = new Dictionary<Command>;
			dictionary->add("Register", new RegisterCommand());
			dictionary->add("Modify", new ModifyCommand());
			dictionary->add("Delete", new DeleteCommand());
		};
	public:
		static CommandProvider* getInstance() {
			return instance;
		};
		Command* getCommand(string key) {
			return dictionary->getValue(key);
		};
		void deleteCommand(string key) {
			dictionary->deleteEntry(key);
		};
		Entry<Command>* getCommands() {
			return dictionary->getEntries();
		};
		void printCommandKeys() {
			dictionary->printKeys();
		};
		int length() {
			return dictionary->length();
		};
		void addCommand(string key, Command* command) {
			dictionary->add(key, command);
		};
};

CommandProvider* CommandProvider::instance = new CommandProvider();

int main() {
	CommandProvider* commandProvider = CommandProvider::getInstance();
	Command* command = commandProvider->getCommand("Register");
	command->execute();
	cout << " " << endl;

	int size = commandProvider->length();
	Entry<Command>* entries = commandProvider->getCommands();
	for(int i = 0; i < size; i++) {
		entries[i].value->execute();
	};
	commandProvider->printCommandKeys();
	cout << " " << endl;

	commandProvider->deleteCommand("Modify");
	size = commandProvider->length();
	entries = commandProvider->getCommands();
	for(int i = 0; i < size; i++) {
		entries[i].value->execute();
	};
	commandProvider->printCommandKeys();
	cout << " " << endl;

	commandProvider->addCommand("Modify", new ModifyCommand());
	commandProvider->addCommand("Modify", new ModifyCommand());
	size = commandProvider->length();
	entries = commandProvider->getCommands();
	for(int i = 0; i < size; i++) {
		entries[i].value->execute();
	};
	commandProvider->printCommandKeys();

	return 0;
}
