#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle("fps:"+ofToString(ofGetFrameRate(),2) + " circlesSize:"+to_string(circles.size()));

    for(int i=0; i<circles.size(); i++){
        if(circles[i]->isDead()) circles.erase(circles.begin()+i);
        else circles[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto &c:circles) c->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='c'){
        circles.clear();
        return;
    }

    ofPtr<dotoutCircle> c = ofPtr<dotoutCircle>(new dotoutCircle);
    ofFloatColor col;
    col.setHsb(ofRandom(1.),0.75,1.0);
    c->init(vec2(ofRandomWidth(),ofRandomHeight()),ofRandom(50,200), col);
    circles.push_back(c);


}
