#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(12345);
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    colorCounter = 0;
    sideCounter = 3;
    ascending = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    //This is going to look for just the accelerometer data
    
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
            if(m.getAddress() == "/mrmr/accelerometerX/33/Clays-6"){

                x = m.getArgAsInt(0);
            
            }
            if(m.getAddress() == "/mrmr/accelerometerY/33/Clays-6"){
                
                y = m.getArgAsInt(0);
                
            }

        }
    if(colorCounter == 255){
        colorCounter = 0;
    }else{
        colorCounter++;
    }
    if(sideCounter == 63){
        ascending = false;
    }
    if(sideCounter == 3){
        ascending = true;
    }
    if(ascending){
        sideCounter++;
    }else{
        sideCounter--;
    }
    ofVec2f curPos;
    curPos.x = x;
    curPos.y = y;
    positions.push_back(curPos);
    if(positions.size() > 20){
        positions.erase(positions.begin()+1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c = ofColor::fromHsb(colorCounter, 255, 255);
    ofColor c2 = ofColor::fromHsb(255-colorCounter, 255, 255);
    ofSetBackgroundColor(c2);
    ofSetCircleResolution(sideCounter);
    for (int i = 0; i < positions.size(); i++) {
        ofSetColor(c, i*5);
        ofDrawCircle(positions[i].x, positions[i].y, sideCounter*2.5);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
