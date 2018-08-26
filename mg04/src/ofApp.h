#pragma once

#include "ofMain.h"

class flatCube{
private:
    float x,y;
    ofVboMesh vbo[3];
    float size;

public:
    void setup(float x, float y, float size){
        this->x = x;
        this->y = y;
        this->size = size;
        ofVec2f v = ofVec2f( cos(DEG_TO_RAD*30), sin(DEG_TO_RAD*30));
        //--- TOP
        vbo[0].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[0].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[0].addVertex(ofVec2f( 1,-1) * v * size);
        vbo[0].addVertex(ofVec2f(-1,-1) * v * size);
        vbo[0].addVertex(ofVec2f( 0,-1) * 1 * size);

        //--- RIGHT
        vbo[1].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[1].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[1].addVertex(ofVec2f( 0, 1) * 1 * size);
        vbo[1].addVertex(ofVec2f( 1,-1) * v * size);
        vbo[1].addVertex(ofVec2f( 1, 1) * v * size);

        //--- LEFT
        vbo[2].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[2].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[2].addVertex(ofVec2f( 0, 1) * 1 * size);
        vbo[2].addVertex(ofVec2f(-1,-1) * v * size);
        vbo[2].addVertex(ofVec2f(-1, 1) * v * size);

        for(auto &V:vbo){
            V.clearColors();
            for(int i=0; i<V.getNumVertices(); i+=2){
                ofFloatColor c;
                c.setHsb(ofRandom(1), .6, 1., 0.75);
                //c.set(ofRandom(1),1);
                V.addColor(c);
                V.addColor(c);
            }
        }
    }

    void setSize(float size){
        this->size = size;
        ofVec2f v = ofVec2f( cos(DEG_TO_RAD*30), sin(DEG_TO_RAD*30));
        vbo[0].setVertex(0, ofVec2f( 0, 0) * 1 * size);
        vbo[0].setVertex(1, ofVec2f( 1,-1) * v * size);
        vbo[0].setVertex(2, ofVec2f(-1,-1) * v * size);
        vbo[0].setVertex(3, ofVec2f( 0,-1) * 1 * size);
        vbo[1].setVertex(0, ofVec2f( 0, 0) * 1 * size);
        vbo[1].setVertex(1, ofVec2f( 0, 1) * 1 * size);
        vbo[1].setVertex(2, ofVec2f( 1,-1) * v * size);
        vbo[1].setVertex(3, ofVec2f( 1, 1) * v * size);
        vbo[2].setVertex(0, ofVec2f( 0, 0) * 1 * size);
        vbo[2].setVertex(1, ofVec2f( 0, 1) * 1 * size);
        vbo[2].setVertex(2, ofVec2f(-1,-1) * v * size);
        vbo[2].setVertex(3, ofVec2f(-1, 1) * v * size);
    }

    void draw(){
        ofPushMatrix();
        ofTranslate(x,y);
        for(auto &V:vbo){ V.draw(); }
        ofPopMatrix();
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

    vector<ofPtr<flatCube> > cube;
};
