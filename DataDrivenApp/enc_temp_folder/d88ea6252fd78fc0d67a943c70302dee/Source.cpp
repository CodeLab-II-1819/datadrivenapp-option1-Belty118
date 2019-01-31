//Banaanaananan

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib> 
using namespace std;

void count();  //function to count tweets
void menuchoice(string);	//function for most of the searching for things
void date(string);	//function to find tweets from a specific date

bool menu1done = false;
int menu1;
int menu2;
string myData;
ifstream inFile;
int numberOfTweets = 0;
string userInput;
string choice;
int choicenum;
string userDate;
string dateLength = "1234567890";  //hacky way to avoid finding dates in the tweets by limiting the length of the search to that of this 10 digit string

int main() {

	inFile.open("Sampletweets.txt");   //opens the file

	choicenum = 0; //sets choice number to 0 so when you go back to the menu and choose another option it doesn't keep adding to the total from the last search, just from this new one
	do {

		menu1done = false;

		cout << " Please press the key for the option you wish to view.\n\n Option 1: Count all tweets in file. \n Option 2: Print all tweets containing the word 'money'\n Option 3: Print all tweets containing the word 'politics'\n Option 4: Print all tweets containing the word 'Paris'\n Option 5: Print all tweets containing the word 'Dreamworks'\n Option 6: Print all tweets containing the word 'Uber'\n Option 7: Print all tweets with a word of your choice \n Option 8: Print all Retweets\n Option 9: Print all tweets tweeted to Donald Trump \n Option 10: Print all tweets from a year of your choice \n"; //asks the user for input
		cin >> menu1;	//takes input into menu1 string 
		
		if (cin.fail()) { //if the cin failed (eg they put a character in not a number)
			cin.clear(); //clear the cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the buffer? Idk what this really means but its important
		}


		switch (menu1) {	//menu1 string is then compared with 1-10 in this switch statement

		case 1: cout << " \nYou have chosen option: " << menu1 << " Counting total tweets in file..." << endl;;
			count();	//if option 1 is chosen, the method to count all the tweets is called
			menu1done = true;
			break;
		case 2: cout << " \n You have chosen option: " << menu1 << " Counting tweets containing the word 'money'" << endl;
			menuchoice("money");		//all other options call the same menuchoice function but pass in a different string based on the user's choice
			menu1done = true;
			break;
		case 3: cout << "\n You have chosen option: " << menu1 << " Counting the number of tweets that mention politics" << endl;
			menuchoice("politics");
			menu1done = true;
			break;
		case 4: cout << " \n You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Paris'" << endl;
			menuchoice("Paris");
			menu1done = true;
			break;
		case 5: cout << "\n You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Dreamworks'" << endl;
			menuchoice("Dreamworks");
			menu1done = true;
			break;
		case 6: cout << " \n You have chosen option: " << menu1 << " Printing all tweets that contain the word 'Uber'" << endl;
			menuchoice("Uber");
			menu1done = true;
			break;
		case 7: cout << " \n You have chosen option: " << menu1 << " Please enter the word you want to search for in the tweets" << endl;
			cin >> userInput;  //user is asked to input a string for their own custom search. String is inputted into userInput
			menuchoice(userInput);	//menuchoice is called again with user's input passed in
			menu1done = true;
		case 8: cout << " \n You have chosen option:" << menu1 << " Printing all retweets" << endl;
			menuchoice("RT"); //searches for all tweets with RT in them, meaning they're retweets
			menu1done = true;
			break;
		case 9: cout << " \n You have chosen option: " << menu1 << " Printing all tweets tweeted at Donald Trump'" << endl;
			menuchoice("@realDonaldTrump");	//finds tweets tweeted at Donald Trump based on his username
			break;
		case 10: cout << " \n You have chosen option: " << menu1 << " Please enter the year you want to search for tweets from" << endl;
			cin >> userDate;	//users are asked to input a date as a string
			if (userDate == "2010" || "2011" || "2012" || "2013" || "2014" || "2015" || "2016" || "2017" || "2018") {   //if the user's inputted string is one of these (The dates the tweets are from) but this doesn't work apparently
				date(userDate);  //the date is passed through into a custom function called date
				menu1done = true;
			}
			else {
				main();
			}
			break;
		default: main(); // if 1-10 hasn't been inputted, ask again what you would like to see.
			break;
		}

	} while (!menu1done);
}

	

void count() {

	if (inFile.good()) { //check file is opened
		while (!inFile.eof()) { // while you're not at the end of the file
			numberOfTweets++;   //add one to the tweet count
			getline(inFile, myData);
		}

		cout << " There are: " << numberOfTweets << " Tweet(s) in the file." << endl;
		inFile.close(); // close the file

		cout << " \nReturn to the main menu please press 1 to exit press any other button" << endl;	//asks user if they would like to quit or go back to the main menu
		cin >> menu2; //takes in the int menu 2

			if (menu2 == 1){  //if the user pressed 1 to go back to the main menu
				main();	//main is called
			}

			else{ 
				exit(0); //otherwise, the function exit from  <cstdlib>  is called to close the program
			}

		system("pause"); //pauses the system to stop is closing whenever a button is pressed

	}
}

void menuchoice(string choice) {

	if (inFile.good()) { //if file is opened okay
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find(" " + choice + " ") < myData.length()) {  //search for the string passed through by the main switch with 2 spaces either side in order to single out the word (EG find only the word Read. Not bready when searching for red)
				cout << myData << endl; // print out the line that contains the word being searched for
				choicenum++;  //when the string is found in the line, add one to the total
			}

		}
		cout << " \nThere are: " << choicenum << " Tweet(s) containing the word " << choice << endl; //show how many tweets there are based on the passed through string called choice
		inFile.close(); //close the file
		 

		cout << " \nReturn to the main menu please press 1 to exit press any other button" << endl;	//asks user if they would like to quit or go back to the main menu
		cin >> menu2; //takes in the int menu 2

		if (menu2 == 1) {  //if the user pressed 1 to go back to the main menu
			main();	//main is called
		}

		else {
			exit(0); //otherwise, the function exit from  <cstdlib>  is called to close the program
		}

		system("pause"); //pauses the system to stop is closing whenever a button is pressed

	}
}


void date(string userDate) { //this function is mostly the same except for line 143

	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, myData);

			if (myData.find(userDate) <= dateLength.length()) { //the line (myData) isn't searched entirely like in the above function as that would also find tweets with the date in the tweet. It only searches the first 10 chars of the tweet as that is where the date and time of tweet information is stored
				choicenum++;									//is does this by having a string with 10 chars called dateLength that it searches the length of
				cout << myData << endl;
			}

		}
		cout << " \nThere are: " << choicenum << " Tweet(s) from the year " << userDate << endl;   //see comments in menu choice function
		inFile.close();


		cout << " \nReturn to the main menu please press 1 to exit press any other button" << endl;	//asks user if they would like to quit or go back to the main menu
		cin >> menu2; //takes in the int menu 2

		if (menu2 == 1) {  //if the user pressed 1 to go back to the main menu
			main();	//main is called
		}

		else {
			exit(0); //otherwise, the function exit from  <cstdlib>  is called to close the program
		}

		system("pause"); //pauses the system to stop is closing whenever a button is pressed

	}
}
