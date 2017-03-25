#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(12345);
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    colorCounter = 0;
    sideCounter = 3;
    timeSinceExp = 0;
    ascending = true;
    mouseClick = false;
    for (int i = 0; i < 250; i++){
        Particle myParticle;
        float vx = ofRandom(-4,4);
        float vy = ofRandom(-4,4);
        myParticle.setInitialCondition(300,300,vx, vy);
        // more interesting with diversity :)
        // uncomment this:
        myParticle.damping = ofRandom(0.01, 0.05);
        particles.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    timeSinceExp++;
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
            if(m.getAddress() == "/mrmr/mouseClickX/33/Clays-6"){
                mouseClickX = m.getArgAsInt(0);
            }
            if(m.getAddress() == "/mrmr/mouseClickY/33/Clays-6"){
                mouseClickY = m.getArgAsInt(0);
                mouseClick = true;
                timeSinceExp = 0;
                for (int i = 0; i < particles.size(); i++){
                    float vx = ofRandom(-4,4);
                    float vy = ofRandom(-4,4);
                    particles[i].setInitialCondition(mouseClickX,mouseClickY,vx, vy);
                }
            }
            else{
                mouseClick = false;
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
        positions.erase(positions.begin());
    }
    if(mouseClick){
        for (int i = 0; i < particles.size(); i++){
            particles[i].resetForce();
            particles[i].addForce(0,0);  // gravity
            particles[i].addDampingForce();
            particles[i].update();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor c = ofColor::fromHsb(colorCounter, 255, 255);
    ofColor c2 = ofColor::fromHsb(255-colorCounter, 255, 255);
    ofSetBackgroundColor(c2);
    ofSetCircleResolution(sideCounter);
    for (int i = 0; i < positions.size(); i++) {
        ofFill();
        ofSetColor(c, i*5);
        ofDrawCircle(positions[i].x, positions[i].y, sideCounter*2.5);
        ofNoFill();
        ofSetColor(255);
        ofSetLineWidth(1);
        ofDrawCircle(positions[i].x, positions[i].y, sideCounter*2.5);
    }
    if(mouseClick && timeSinceExp < 60){
        for (int i = 0; i < particles.size(); i++){
            ofFill();
            ofSetColor(c);
            particles[i].draw();
            ofNoFill();
            ofSetColor(255);
            ofSetLineWidth(1);
            ofDrawCircle(particles[i].pos.x, particles[i].pos.y, 3);
        }
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
