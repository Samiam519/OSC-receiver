#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        ofxOscReceiver receiver;
        int x;
        int y;
    int mouseClickX;
    int mouseClickY;
    int sideCounter;
    int colorCounter;
    int timeSinceExp;
    bool ascending;
    bool mouseClick;
    vector <ofVec2f>positions;
    vector <Particle> particles;
};
