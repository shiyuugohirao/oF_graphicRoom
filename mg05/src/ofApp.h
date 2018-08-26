#pragma once

#include "ofMain.h"

const ofVec2f dest[4] ={
    ofVec2f( cos(DEG_TO_RAD*30), sin(DEG_TO_RAD*30)),
    ofVec2f(-cos(DEG_TO_RAD*30), sin(DEG_TO_RAD*30)),
    ofVec2f(0,1),
    ofVec2f(0,-1)
};

class flatCube{
private:
    ofVec2f pos,prePos,endPos;
    ofVboMesh vbo[3];
    float size;
    ofTexture tex;
    bool bInit = true;
    int startTime = 0;

public:
    void setup(float x, float y, float size, const ofTexture &_tex){
        pos.x = x;
        pos.y = y;
        prePos = ofVec2f(x,y);
        this->size = size;
        tex = _tex;

        ofVec2f v = ofVec2f( cos(DEG_TO_RAD*30), sin(DEG_TO_RAD*30));
        ofVec2f t = ofVec2f( tex.getWidth(), tex.getHeight());

        //--- TOP
        float b = ofRandom(0,0.3);
        float e = ofRandom(0.7,1);
        vbo[0].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[0].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[0].addVertex(ofVec2f( 1,-1) * v * size);
        vbo[0].addVertex(ofVec2f(-1,-1) * v * size);
        vbo[0].addVertex(ofVec2f( 0,-1) * 1 * size);
        vbo[0].addTexCoord(ofVec2f(e,e) * t);
        vbo[0].addTexCoord(ofVec2f(e,b) * t);
        vbo[0].addTexCoord(ofVec2f(b,e) * t);
        vbo[0].addTexCoord(ofVec2f(b,b) * t);

        //--- RIGHT
        vbo[1].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[1].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[1].addVertex(ofVec2f( 0, 1) * 1 * size);
        vbo[1].addVertex(ofVec2f( 1,-1) * v * size);
        vbo[1].addVertex(ofVec2f( 1, 1) * v * size);
        vbo[1].addTexCoord(ofVec2f(b,b) * t);
        vbo[1].addTexCoord(ofVec2f(e,b) * t);
        vbo[1].addTexCoord(ofVec2f(b,e) * t);
        vbo[1].addTexCoord(ofVec2f(e,e) * t);

        //--- LEFT
        vbo[2].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        vbo[2].addVertex(ofVec2f( 0, 0) * 1 * size);
        vbo[2].addVertex(ofVec2f( 0, 1) * 1 * size);
        vbo[2].addVertex(ofVec2f(-1,-1) * v * size);
        vbo[2].addVertex(ofVec2f(-1, 1) * v * size);
        vbo[2].addTexCoord(ofVec2f(b,b) * t);
        vbo[2].addTexCoord(ofVec2f(e,b) * t);
        vbo[2].addTexCoord(ofVec2f(b,e) * t);
        vbo[2].addTexCoord(ofVec2f(e,e) * t);

        for(auto &V:vbo){
            V.clearColors();
            for(int i=0; i<V.getNumVertices(); i+=2){
                ofFloatColor c;
                c.setHsb(ofRandom(1), .3, 1., 1);
                //c.set(ofRandom(0.5,1.0),1);
                V.addColor(c);
                V.addColor(c);
            }
        }
    }

    void randomOrder(int time, int span){
        if(bInit){
            startTime = time + ofRandom(span);
            bInit=false;
            endPos = dest[(int)ofRandom(4)] * size;
        }
        float f = ofMap(time-startTime, 0,span,0,1,true);
        float e = pow(f,5);
        pos.x = prePos.x + endPos.x*e;
        pos.y = prePos.y + endPos.y*e;
        if(f>=1){
            prePos = prePos + endPos;
            bInit = true;
        }
    }

    void draw(){
        ofPushMatrix();
        ofTranslate(pos.x, pos.y);
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

    ofTexture tex;
    flatCube bgCube;
    vector<ofPtr<flatCube> > cube;
};
