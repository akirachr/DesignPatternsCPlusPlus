#include <iostream>
#include <vector>

using namespace std;

class Component {
	protected:
		string name;
		vector<Component*> children;
		string indent = "";
	public:
		void addIndent(string value) {
			indent += value;
			for (int i = 0; i < children.size(); i++) {
				children[i]->addIndent(value);
			}
		};
		void print() {
			cout << indent + name << endl;
			for (int i = 0; i < children.size(); i++) {
			  children[i]->print();
			}
		};
};

class Leaf: public Component {
	public:
		Leaf(string value) {
			name = value;
		}
};

class Composite: public Component {
	public:
		Composite(string value) {
			name = value;
		};
		void add(Component *element) {
			element->addIndent("   ");
			children.push_back(element);
		};
};

int main() {
	Composite* designPatterns = new Composite("Design Patterns");
	Composite* creationalPatterns = new Composite("Creational Patterns");
	Composite* structuralPatterns = new Composite("Structural Patterns");
	Composite* behavioralPatterns = new Composite("Behavioral Patterns");
	Leaf* factoryMethod = new Leaf("Factory Method");
	Leaf* abstractFactory = new Leaf("Abstract Factory");
	creationalPatterns->add(factoryMethod);
	creationalPatterns->add(abstractFactory);
	designPatterns->add(creationalPatterns);
	designPatterns->add(structuralPatterns);
	designPatterns->add(behavioralPatterns);
	designPatterns->print();

	return 0;
};

