#include <iostream>
#include <string>

using namespace std;

class Validator {
	protected:
		Validator *nextValidator;
	public:
		Validator() {
			nextValidator = nullptr;
		}
		virtual ~Validator() {
		}
		
		void addNextValidator(Validator* value) {
			nextValidator = value;
		};
		
		bool check(string value) {
			bool checked = doCheck(value);
			if( checked && nextValidator != nullptr ) {
				return nextValidator->check(value);
			};
			
			return checked;
		}; 
	
	virtual bool doCheck(string value) {
		return true;
	};
};

class AtMarkValidator:public Validator {
	public:
		AtMarkValidator() {
		}
		~AtMarkValidator() {
		}
		bool doCheck(string value) {
			size_t indexOfAtMark = value.find("@");
			bool checked = (indexOfAtMark != string::npos);
			if( !checked ) {
				cout << "@ is missing." << endl;
			};
			return checked;
		};
};

class DomainValidator:public Validator {
	public:
		DomainValidator() {
		}
		~DomainValidator() {
		}
		bool doCheck(string value) {
			size_t indexOfAtMark = value.find("@");
			string v = value.substr(indexOfAtMark);
			size_t indexOfDot = v.find(".");
			bool checked = (indexOfDot != string::npos);
			if( !checked ) {
				cout << "Domain must have a dot(.)." << endl;
			};
			return checked;
		};
};

int main() {
	Validator* firstValidator = new AtMarkValidator();
	Validator* secondValidator = new DomainValidator();
	firstValidator->addNextValidator(secondValidator);
	bool checked = firstValidator->check("akirachr@gmail.com");
	cout << checked << endl;
	
	return 0;
}