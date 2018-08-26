#include "ofApp.h"

float size = 77;
//--------------------------------------------------------------
void ofApp::setup(){
    for(int y=0;y<ofGetHeight()+size; y+=size*2){
        vector<ofVec2f> pos;
        for(int x=0;x<ofGetWidth()+size; x+=cos(DEG_TO_RAD*30)*size*2){
            pos.push_back(ofVec2f(x,y));
        }
        random_shuffle(pos.begin(),pos.end());
        for(auto &p:pos){
            ofPtr<flatCube> c(new flatCube());
            c->setup(p.x,p.y, size);
            cube.push_back(c);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    static float counter;
    ofSetWindowTitle(ofToString(ofGetFrameRate(),2));

    counter += 0.01;
    float noise = (sin(counter*0.5)+1)/2;

    for(int i=0; i<cube.size(); i++){
        float n = ofNoise(counter+i);
        cube[i]->setSize(size + noise * n * size*2);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(255), ofColor(180), OF_GRADIENT_CIRCULAR);
    for(auto &c:cube){ c->draw(); }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
