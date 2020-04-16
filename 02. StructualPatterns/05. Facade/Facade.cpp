#include <iostream>

using namespace std;

class Scanner {
	public:
		static string scan(string value) {
			return value;
		};
};

class Parser {
	public:
		static string parse(string value) {
			return value;
		};
};

class CodeGenerator {
	public:
		static string generate(string value) {
			return value;
		};
};

class Compiler {
	public:
		static void compile(string value) {
			string scanned = Scanner::scan(value);
			string parsed = Parser::parse(scanned);
			string generated = CodeGenerator::generate(parsed);
			
			cout << generated << endl;
		};
};

int main() {
	Compiler::compile("ABCDE");
	
	return 0;
};