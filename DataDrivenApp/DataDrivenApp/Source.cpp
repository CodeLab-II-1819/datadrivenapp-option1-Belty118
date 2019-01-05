#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int menu1;

int main() {

	cout << "Please press the key for the option you wish to see \n\nOption 1: Count all tweets in file. \nOption 2: Count tweets containing the word Money. \nOption 3: Count tweets that mention politics. \nOption 4: Print tweets that contain the word Paris. \nOption 5: Print tweets that contain the word Dreamworks. \nOption 6: Print tweets that contain the word Uber." << endl;
	cin >> menu1;

	switch (menu1) {

	case 1: cout << "You have chosen option: " << menu1 << " Counting total tweets in file" << endl;;
		break;
	case 2: cout << "You have chosen option: " << menu1 << " Counting tweets containing the word 'money'" << endl;
		break;
	case 3: cout << "You have chosen option: " << menu1 << " Counting the number of tweets that mention politics" << endl;
		break;
	case 4: cout << "You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Paris'" << endl;
		break;
	case 5: cout << "You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Dreamworks'" << endl;
		break;
	case 6: cout << "You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Uber'" << endl;
		break;
	case 7: cout << "" << endl;
		break;
	default: cout << "Please press the key for the option you wish to see" << endl;

	}


	system("pause");
	return 0;

}


