#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetDepthTest(true);

    for(int y=50; y<ofGetHeight(); y+=100){
        for(int x=50; x<ofGetWidth(); x+=100){
            ofPtr<gradationBox> b(new gradationBox());
            b->setup(x,y /*, ofRandom(-10,0)*/);
            box.push_back(b);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(auto &b: box){
        b->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(255), ofColor(180), OF_GRADIENT_CIRCULAR);
    for(auto &b: box){
        b->draw();
    }
}
