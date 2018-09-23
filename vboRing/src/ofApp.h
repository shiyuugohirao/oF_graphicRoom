#pragma once

#include "ofMain.h"

using namespace glm;

class dotoutCircle {
private:
    ofVboMesh vbo;
    ofFloatColor col;
    vec2 pos;
    float sRadius, eRadius;
    float circleRes;
    int lifeCounter;
    int lifeSpd;
    bool bDead;

public:
    void init(vec2 pos, float radius, ofFloatColor color, float circleRes = 360.){
        this->pos = pos;
//        sRadius = 0; //[*]start center of circle
        sRadius = radius*ofRandom(0.7,0.85);
        eRadius = radius;
        this->col = color;
        this->circleRes = circleRes;
        lifeCounter = 0;
        lifeSpd = 100;
        bDead = false;
        
        updateVertices();
    }

    void update(){
        lifeCounter++;

        float n = ofMap(lifeCounter, 0,lifeSpd, 0,1);
        sRadius = eRadius * pow(n,5);
        bDead = (sRadius == eRadius);
        updateVertices();
    }

    void updateVertices(){
        vbo.clearVertices();
        vbo.clearColors();
        vbo.setMode(OF_PRIMITIVE_POINTS);
        float maxDeg = 360+.01;
        float unit = maxDeg/circleRes;

        for(float r=sRadius; r<eRadius; r+=1){
            float alpha = ofMap(r, 0,eRadius, 1.,0.);
            col.a = alpha;
            for(float deg=0; deg<maxDeg; deg+=unit){
                vec3 v = vec3(cos(DEG_TO_RAD*deg)*r, sin(DEG_TO_RAD*deg)*r, 0);
                vbo.addVertex(v);
                vbo.addColor(ofColor(col));
            }
        }
    }

    void draw(){
        ofPushMatrix();
        ofPushStyle();
        ofTranslate(pos);
        ofSetColor(255);
        vbo.draw(OF_MESH_POINTS);
        ofPopStyle();
        ofPopMatrix();
    }

    bool isDead(){ return bDead; }
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    vector<ofPtr<dotoutCircle>> circles;
};
