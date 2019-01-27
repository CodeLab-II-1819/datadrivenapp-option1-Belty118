//Banaanaananan

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

void count();
void money();
void politics();
void paris();
void dreamworks();
void uber();
void search();

int menu1;
string myData;
ifstream inFile;
int numberOfTweets = 0;
string userInput;


int main() {

	inFile.open("Sampletweets.txt");

	cout << "Please press the key, for the option you wish to see.\n\nOption 1: Count all tweets in file. \nOption 2: Print all tweetscontaining the word 'money'\nOption 3: Print all tweets containing the word 'Politics'\nOption 4: Print all tweets containing the word'paris'\nOption 5: Print all tweets containing the word'dreamworks'\nOption 6: Print all tweets containing the word 'uber'\nOption 7: Print all tweets with a word of your choice \n";
	cin >> menu1;

	switch (menu1) {

	case 1: cout << "\nYou have chosen option: " << menu1 << " Counting total tweets in file..." << endl;;
		count();
		break;
	case 2: cout << "\nYou have chosen option: " << menu1 << " Counting tweets containing the word 'money'" << endl;
		money();
		break;
	case 3: cout << "\nYou have chosen option: " << menu1 << " Counting the number of tweets that mention politics" << endl;
		politics();
		break;
	case 4: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Paris'" << endl;
		paris();
		break;
	case 5: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Dreamworks'" << endl;
		dreamworks();
		break;
	case 6: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Uber'" << endl;
		uber();
		break;
	case 7: cout << "\nYou have chosen option: " << menu1 << " Please enter the word you want to search for in the tweets" << endl;
		cin >> userInput;
		search();
	case 8: cout << "" << endl;
		break;
	default: cout << "Please press the key for the option you wish to see" << endl;

	}

	return 0;

}

void count() {


	if (inFile.good()) { //check file is opened
		while (!inFile.eof()) { // while you're not at the end of the file
			numberOfTweets++;   //add one to the tweet count
			getline(inFile, myData);
		}

		cout << "There are: " << numberOfTweets << " Tweets in the file." << endl;
		inFile.close(); // close the file
	}


};

void money() {


	if (inFile.good()) {         //if the file is opened properly
		while (!inFile.eof()) {             //while you're not at the end of the file
			getline(inFile, myData);             //get the line and put the data into a string

			if (myData.find("money") < myData.length() || myData.find("Money") < myData.length()) {   //if the string you collected above has the word you're looking for in it
				cout << myData << endl;    //print the data
			}
		}
		inFile.close();        //close the file when done

	};
};

void politics() {

};

void paris() {

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find("paris") < myData.length() || myData.find("Paris") < myData.length()) {
				cout << myData << endl;
			}
		}
		inFile.close();

	};

};

void dreamworks() {

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find("dreamworks") < myData.length() || myData.find("Dreamworks") < myData.length()) {
				cout << myData << endl;
			}
		}
		inFile.close();

	};

};

void uber() {

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find("uber") < myData.length() || myData.find("Uber") < myData.length()) {
				cout << myData << endl;
			}
		}
		inFile.close();

	};

};

void search() {

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find(" " + userInput + " ") < myData.length()) {
				cout << myData << endl;
			}
		}
		inFile.close();

	};

};

