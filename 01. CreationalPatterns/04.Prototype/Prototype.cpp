#include <iostream>

using namespace std;

class Table {
  	protected:
		string legs;
		string board;

 	public:
		Table() {
		}
		virtual ~Table() {
		}

		virtual void addLegs(string value) {};
		virtual void addBoard(string value) {};
		virtual void print() {};
		virtual Table* clone() = 0;
};

class ModernTable:public Table {
	public:
		ModernTable() {
		}
		~ModernTable() {
		}
		Table* clone() {
			ModernTable* o = new ModernTable();
			o->addLegs(this->legs);
			o->addBoard(this->board);
			return o;
		};
		void addLegs(string value) {
			legs = value;
		}
		void addBoard(string value) {
			board = value;
		}
		void print() {
			cout << legs + ":" + board << endl;
		}
};

int main() {

	Table *table = new ModernTable();
	table->addLegs("Modern Legs");
	table->addBoard("Modern Board");
	Table *clone = table->clone();
	clone->print();

	return 0;
}
