#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofLoadImage(tex, "tex0.png");
    ofLoadImage(tex, "tex256mono.jpg");

    float size = 30;
    vector<ofVec2f> pos;
    for(int y=0;y<ofGetHeight()+size; y+=size*2){
        for(int x=0;x<ofGetWidth()+size; x+=cos(DEG_TO_RAD*30)*size*2){
            pos.push_back(ofVec2f(x,y));
        }
    }
    random_shuffle(pos.begin(),pos.end());
    for(auto &p:pos){
        ofPtr<flatCube> c(new flatCube());
        c->setup(p.x,p.y, size, tex);
        cube.push_back(c);
    }
    bgCube.setup(ofGetWidth()*.5, ofGetHeight()*.5, size*5, tex);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));

    int time = ofGetElapsedTimeMillis();
    for(auto &c:cube){ c->randomOrder(time, 1000); }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(100), ofColor(10), OF_GRADIENT_CIRCULAR);
    tex.bind();
    for(auto &c:cube){ c->draw(); }
    tex.unbind();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
