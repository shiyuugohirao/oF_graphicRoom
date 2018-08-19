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

    //--- TOP
//    vbo.addVertex(ofVec2f( 0, 0));
//    vbo.addVertex(ofVec2f( cos(r), sin(r)));
//    vbo.addVertex(ofVec2f( 0, r));
//    vbo.addVertex(ofVec2f( -cos(r), sin(r)));
//
//    //--- RIGHT
//    vbo.addVertex(ofVec2f( 0, 0));
//    vbo.addVertex(ofVec2f( cos(r), sin(r)));
//    vbo.addVertex(ofVec2f( cos(r), -sin(r)));
//    vbo.addVertex(ofVec2f( 0, -r));
//
//    //--- LEFT
//    vbo.addVertex(ofVec2f( 0, 0));
//    vbo.addVertex(ofVec2f( -cos(r), sin(r)));
//    vbo.addVertex(ofVec2f( -cos(r), -sin(r)));
//    vbo.addVertex(ofVec2f( 0, -r));


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
