#include <iostream>

using namespace std;

class Character {
	private:
		string name;
	public:
		Character() {};
		Character(string value) {
			name = value;
		};
		string getName() {
			return name;
		};
};

class CharacterFactory {
	private:
		static int num;
		static Character* characters;
	public:
		static Character getCharacter(string value) {
			for( int i = 0; i < num; i++ ) {
				if( value == characters[i].getName() ) {
					return characters[i];
				};
			};
			characters[num] = Character(value);
			return characters[num++];
		};
};

int CharacterFactory::num = 0;
Character* CharacterFactory::characters = new Character[128];

int main() {
	cout << CharacterFactory::getCharacter("A").getName() << endl;
	cout << CharacterFactory::getCharacter("B").getName() << endl;
	cout << CharacterFactory::getCharacter("C").getName() << endl;
	cout << CharacterFactory::getCharacter("A").getName() << endl;
	
	return 0;
};