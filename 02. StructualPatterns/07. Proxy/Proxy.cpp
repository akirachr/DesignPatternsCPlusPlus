#include <iostream>
#include "unistd.h"

using namespace std;

class Image {
	private:
		string value;
	public:
		Image(){
			value = "Image";
			sleep(5);
		};
		string getValue() {
			return value;
		};
};

class Proxy {
	private:
		static Image* image;
	public:
		static Image* getImage() {
			if( image == 0 ) {
				image = new Image();
			};
			return image;
		};
};

Image* Proxy::image = 0;

class Document {
	public:
		Document() {};
		void printText() {
			cout << "Text" << endl;
		};
		void drawImage() {
			Image* image = Proxy::getImage();
			cout << image->getValue() << endl;
		};
};

int main() {
	Document* doc = new Document();
	doc->printText();
	doc->drawImage();
	doc->drawImage();

	return 0;
}