#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    for(int i=0; i<10; i++){
        ofPtr<gradationAmeba> a(new gradationAmeba());
        ofFloatColor start, end;
        start.setHsb(ofRandom(1), 0.3, 1);
        end.setHsb(ofRandom(1), 0.3, 1);
        float spd = ofRandom(0.05,0.25);
        a->setup((int)ofRandomWidth(), (int)ofRandomHeight(), ofRandom(50,200), start, end, spd);
        ameba.push_back(a);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(to_string(ofGetFrameRate()) + " / " + to_string(ameba.size()));
    for(auto& a:ameba){ a->update(); }
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(255), ofColor(180), OF_GRADIENT_CIRCULAR);
    for(auto& a:ameba){ a->draw(); }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //ofSaveScreen("screen.png");
    if(key=='c'){ ameba.clear();  }
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
    ofPtr<gradationAmeba> a(new gradationAmeba());
    ofFloatColor start, end;
    start.setHsb(ofRandom(1), 0.3, 1);
    end.setHsb(ofRandom(1), 0.3, 1);
    float spd = ofRandom(0.05,0.2);
    a->setup(ofRandomWidth(), ofRandomHeight(), ofRandom(50,200), start, end, spd);
    ameba.push_back(a);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

