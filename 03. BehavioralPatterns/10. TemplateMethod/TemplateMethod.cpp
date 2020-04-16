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

class TableFactory {
	protected:
		Table *table;
	public:
		TableFactory() {
		}
		virtual ~TableFactory() {
		}
		void createTable() {
			addLegs();
			addBoard();
		};
		Table* deliverTable() {
			return table;
		};
		virtual void addLegs() {};
		virtual void addBoard() {};
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

class ModernTableFactory:public TableFactory {
	public:
		ModernTableFactory() {
			table = new ModernTable();
		}
		~ModernTableFactory() {
		}
		void addLegs() {
			table->addLegs("Modern Legs");
		}
		void addBoard() {
			table->addBoard("Modern Board");
		};
};

class VictorianTableFactory:public TableFactory {
	public:
		VictorianTableFactory() {
			table = new VictorianTable();
		}
		~VictorianTableFactory() {
		}
		void addLegs() {
			table->addLegs("Victorian Legs");
		}
		void addBoard() {
			table->addBoard("Victorian Board");
		};
};

int main() {

	TableFactory *tableFactory = new ModernTableFactory();
	tableFactory->createTable();
	Table* table = tableFactory->deliverTable();
	table->print();

	return 0;
}
