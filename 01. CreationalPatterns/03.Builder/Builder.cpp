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

class TableBuilder {
	protected:
		Table *table;
	public:
		TableBuilder() {
		}
		virtual ~TableBuilder() {
		}
		virtual void addLegs() {};
		virtual void addBoard() {};
		Table* deliverTable() {
			return table;
		};
};

class TableDirector {
	protected:
		TableBuilder* tableBuilder;
	public:
		TableDirector() {
		}
		void setTableBuilder(TableBuilder* value) {
			tableBuilder = value;
		};
		void createTable() {
			tableBuilder->addLegs();
			tableBuilder->addBoard();
		};
		Table* deliverTable() {
			return tableBuilder->deliverTable();
		};
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

class ModernTableBuilder:public TableBuilder {
	public:
		ModernTableBuilder() {
			table = new ModernTable();
		}
		~ModernTableBuilder() {
		}
		void addLegs() {
			table->addLegs("Modern Legs");
		}
		void addBoard() {
			table->addBoard("Modern Board");
		};
};

class VictorianTableBuilder:public TableBuilder {
	public:
		VictorianTableBuilder() {
			table = new VictorianTable();
		}
		~VictorianTableBuilder() {
		}
		void addLegs() {
			table->addLegs("Victorian Legs");
		}
		void addBoard() {
			table->addBoard("Victorian Board");
		};
};

int main() {

	TableBuilder* tableBuilder = new ModernTableBuilder();
	TableDirector* tableDirector = new TableDirector();
	tableDirector->setTableBuilder(tableBuilder);
	tableDirector->createTable();
	Table* table = tableDirector->deliverTable();
	table->print();

	return 0;
}
