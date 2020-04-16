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

		virtual void addLegs(string value) = 0;
		virtual void addBoard(string value) = 0;
		virtual void print() = 0;
		string getLegs() {
			return legs;
		};
		string getBoard() {
			return board;
		};
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
		virtual void addLegs() = 0;
		virtual void addBoard() = 0;
};

class TableFactoryDecorator {
	protected:
		TableFactory *tableFactory;
		TableFactoryDecorator *nextDecorator;
	public:
		TableFactoryDecorator() {
			nextDecorator = nullptr;
		}
		virtual ~TableFactoryDecorator() {
		}
		void setNextDecorator(TableFactoryDecorator* value) {
			nextDecorator = value;
		};
		void setTableFactory(TableFactory* value) {
			tableFactory = value;
		};
		void decorateTable() {
			decorate();
			if( nextDecorator != nullptr ) {
				nextDecorator->setTableFactory(this->tableFactory);
				nextDecorator->decorateTable();
			};
		};
		virtual void decorate() = 0;
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

class TableFactoryDecorator1:public TableFactoryDecorator {
	public:
		TableFactoryDecorator1() {
		}
		~TableFactoryDecorator1() {
		}
		void decorate() {
			Table *table = tableFactory->deliverTable();
			string legs = table->getLegs() + "X";
			string board = table->getBoard() + "X";
			table->addLegs(legs);
			table->addBoard(board);
		};
};

class TableFactoryDecorator2:public TableFactoryDecorator {
	public:
		TableFactoryDecorator2() {
		}
		~TableFactoryDecorator2() {
		}
		void decorate() {
			Table *table = tableFactory->deliverTable();
			string legs = table->getLegs() + "Y";
			string board = table->getBoard() + "Y";
			table->addLegs(legs);
			table->addBoard(board);
		};
};

int main() {

	TableFactory* tableFactory = new ModernTableFactory();
	TableFactoryDecorator* decorator1 = new TableFactoryDecorator1();
	TableFactoryDecorator* decorator2 = new TableFactoryDecorator2();
	decorator1->setTableFactory(tableFactory);
	decorator1->setNextDecorator(decorator2);
	tableFactory->createTable();
	decorator1->decorateTable();
	Table* table = tableFactory->deliverTable();
	table->print();
	
	return 0;
}
