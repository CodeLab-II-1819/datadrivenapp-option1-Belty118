//Banaanaananan

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib> 
using namespace std;

void count();
void menuchoice(string);


int menu1;
int menu2;
string myData;
ifstream inFile;
int numberOfTweets = 0;
string userInput;
string choice;
int choicenum;


int main() {

	inFile.open("Sampletweets.txt");

	cout << "Please press the key, for the option you wish to see.\n\nOption 1: Count all tweets in file. \nOption 2: Print all tweets containing the word 'money'\nOption 3: Print all tweets containing the word 'politics'\nOption 4: Print all tweets containing the word 'Paris'\nOption 5: Print all tweets containing the word 'Dreamworks'\nOption 6: Print all tweets containing the word 'Uber'\nOption 7: Print all tweets with a word of your choice \nOption 8: Print all Retweets\n";
	cin >> menu1;

	switch (menu1) {

	case 1: cout << "\nYou have chosen option: " << menu1 << " Counting total tweets in file..." << endl;;
		count();
		break;
	case 2: cout << "\nYou have chosen option: " << menu1 << " Counting tweets containing the word 'money'" << endl;
		menuchoice("money");
		break;
	case 3: cout << "\nYou have chosen option: " << menu1 << " Counting the number of tweets that mention politics" << endl;
		menuchoice("politics");
		break;
	case 4: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Paris'" << endl;
		menuchoice("Paris");
		break;
	case 5: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Dreamworks'" << endl;
		menuchoice("Dreamworks");
		break;
	case 6: cout << "\nYou have chosen option: " << menu1 << " Printing all tweets that contain the word 'Uber'" << endl;
		menuchoice("Uber");
		break;
	case 7: cout << "\nYou have chosen option: " << menu1 << " Please enter the word you want to search for in the tweets" << endl;
		cin >> userInput;
		menuchoice(userInput);
	case 8: cout << "\nYou have chosen option:" << menu1 << " Printing all retweets" << endl;
		menuchoice("RT");
		break;
	case 10: cout << "" << endl;
		break;
	default: cout << "Please press the key for the option you wish to see" << endl;

	}
}
	

void count() {

	if (inFile.good()) { //check file is opened
		while (!inFile.eof()) { // while you're not at the end of the file
			numberOfTweets++;   //add one to the tweet count
			getline(inFile, myData);
		}

		cout << "There are: " << numberOfTweets << " Tweets in the file." << endl;
		inFile.close(); // close the file

		cout << "Return to the main menu please press 1 or to exit, please press 2" << endl;
		cin >> menu2;

			if (menu2 == 1){
				main();
			}

			else if (menu2 == 2) {
				exit(0);
			}

		system("pause");

	}
}



void menuchoice(string choice) {

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find(" " + choice + " ") < myData.length()) {
				choicenum++;
				cout << myData << endl;
			}

		}
		cout << "There are: " << choicenum << " Tweets containing the word " << choice << endl;
		inFile.close();

		cout << "Return to the main menu please press 1 or to exit, please press 2" << endl;
		cin >> menu2;

		if (menu2 == 1) {
			main();
		}

		else if (menu2 == 2) {
			exit(0);
		}

		system("pause");
	}


}
