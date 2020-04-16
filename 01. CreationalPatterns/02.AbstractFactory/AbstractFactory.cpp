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
};


class Chair {
  	protected:
		string legs;
		string board;

 	public:
		Chair() {
		}
		virtual ~Chair() {
		}

		virtual void addLegs(string value) {};
		virtual void addBoard(string value) {};
		virtual void print() {};
};

class Factory {
	protected:
		Table *table;
		Chair *chair;
	public:
		Factory() {
		}
		virtual ~Factory() {
		}
		virtual Table* createTable() = 0;
		virtual Chair* createChair() = 0;
};

class ModernTable:public Table {
	public:
		ModernTable() {
		}
		~ModernTable() {
		}
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

class VictorianTable:public Table {
	public:
		VictorianTable() {
		}
		~VictorianTable() {
		}
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


class ModernChair:public Chair {
	public:
		ModernChair() {
		}
		~ModernChair() {
		}
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

class VictorianChair:public Chair {
	public:
		VictorianChair() {
		}
		~VictorianChair() {
		}
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

class ModernFactory:public Factory {
	public:
		ModernFactory() {
			table = new ModernTable();
			chair = new ModernChair();
		}
		~ModernFactory() {
		}
		Table* createTable() {
			table->addLegs("Modern Legs");
			table->addBoard("Modern Board");
			return table;
		}
		Chair* createChair() {
			chair->addLegs("Modern Legs");
			chair->addBoard("Modern Legs");
			return chair;
		}
};

class VictorianFactory:public Factory {
	public:
		VictorianFactory() {
			table = new VictorianTable();
			chair = new VictorianChair();
		}
		~VictorianFactory() {
		}
		Table* createTable() {
			table->addLegs("Victorian Table Legs");
			table->addBoard("Victorian Table Board");
			return table;
		}
		Chair* createChair() {
			chair->addLegs("Victorian Chair Legs");
			chair->addBoard("Victorian Chair Board");
			return chair;
		}
};

int main() {

	Factory *factory = new VictorianFactory();
	Table* table = factory->createTable();
	table->print();
	Chair* chair = factory->createChair();
	chair->print();

	return 0;
}