#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(109, 147, 172); //sets backgroudn colour
	mainfont.load("mainfont.otf", 32);  //loads the font for the main title
	logo.load("logo.png");
	smaller.load("mainfont.otf", 14);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


	ofSetColor(196, 214, 226);  //set colour to anything below r,g,b
	ofDrawRectangle(10,11, 800, 100); //x,y, width, height
	ofSetColor(255, 255, 255);   //logo and name bar
	ofDrawRectangle(850, 11, 150, 150);

	ofSetColor(255, 255, 255);   //search bar
	ofDrawRectRounded(190, 130, 620, 60,5);
	ofSetColor(0, 0, 0);
	smaller.drawString("Search...", 215,165);


	ofSetColor(255, 255, 255);    //logo drawning
	logo.draw(855, 15 , 150, 150); //image load (x,y,width, height


	mainfont.drawString("George's Marvelous Find a Word", 40, 50); //draw a string with the font ("words", x, y)  //title
	mainfont.drawString("Inside a Tweet in a File Program!", 40, 100);



	ofSetColor(139, 177, 189);  //set colour to anything below r,g,b     //button backgrounds for alt options
	ofDrawRectRounded(14, 133, 150, 63, 10);
	ofDrawRectRounded(14, 213, 150, 63, 10);	 //x,y,width, height, radius of roundness
	ofDrawRectRounded(14, 293, 150, 63, 10);
	ofDrawRectRounded(14, 373, 150, 63, 10);  
	ofDrawRectRounded(14, 453, 150, 63, 10);
	ofDrawRectRounded(14, 533, 150, 63, 10);
	ofDrawRectRounded(14, 613, 150, 63, 10);
	ofDrawRectRounded(14, 693, 150, 33, 10);

	ofSetColor(0, 0, 0);							 //alternate options text
	smaller.drawString("Count Tweets\n in file", 20, 170);
	smaller.drawString("Find Tweets\ncontaining\n'money'", 20, 230);
	smaller.drawString("Find Tweets\ncontaining\n'politics'", 20, 310);
	smaller.drawString("Find Tweets\ncontaining\n'Paris'", 20, 390);
	smaller.drawString("Find Tweets\ncontaining\n'Dreamworks'", 20, 470);
	smaller.drawString("Find Tweets\ncontaining\n'Uber'", 20, 550); 
	smaller.drawString("Find Tweets\nTweeted @\n'Donald Trump'", 20, 630);
	smaller.drawString("Find Retweets", 20, 710);

	ofSetColor(0, 172, 237);			//results page
	ofDrawRectangle(190, 210, 810, 520);

	ofSetColor(255, 255, 255);             //results page white bit
	ofDrawRectangle(210, 230, 770, 480);

	ofSetColor(0, 0, 0);			//results text
	smaller.drawString("Results...", 230, 260);



	
}

