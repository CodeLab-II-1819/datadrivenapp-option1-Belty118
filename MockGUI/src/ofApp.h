#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofTrueTypeFont mainfont; //creates a custom font
		ofImage logo;
		ofTrueTypeFont smaller;
		
};
