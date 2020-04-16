#include <iostream>

using namespace std;

class DOMService {
	public:
		int parse(string data) {
			int start = data.find("<data>");
			int end = data.find("</data>");
			int startPosition = start + 6;
			int length = data.length() - start - 6 - 7;
			int value = stoi(data.substr(start + 6, length));
			return value;
		};

		string format(int data) {
			string value = "<data>" + to_string(data) + "</data>";
			return value;
		};

		string multiply(string data) {
			int in = parse(data);
			int result = in * 2;
			string value = format(result);
			return value;
		};
};

class Adapter {
	public:
		virtual int calculate(int data) = 0;
};

class DOMServiceAdapter: public Adapter, public DOMService {
	public:
		int calculate(int data) {
			string in = format(data);
			string response = multiply(in);
			return parse(response);
		};
};

int main() {
	DOMServiceAdapter* domAdapter = new DOMServiceAdapter();
	cout << domAdapter->calculate(5) << endl;
	return 0;
} 
