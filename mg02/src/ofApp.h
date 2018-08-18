#pragma once

#include "ofMain.h"


class gradationAmeba{
private:
    int x,y;
    float radius, targetRadius;
    float noise;
    float rot, rotSpeed;

    ofPolyline poly;
    ofVboMesh vboMesh;
    ofFloatColor c;
    vector<ofFloatColor> cols;

public:
    void setup(int x, int y, float r, const ofFloatColor &startColor, const ofFloatColor &endColor ,float rotSpeed=0.1){
        this->x = x;
        this->y = y;
        radius = 1.0;
        targetRadius  = r;
        this->rotSpeed = rotSpeed;
        rot = ofRandom(360);
        cols.resize(360);
        for(int i=0; i<cols.size(); i++){
            float f = (cos(i/(float)cols.size()* PI)+1) /2.; // 1~0
            cols[i].set(endColor.getLerped(startColor, f));
            cols[i].a = 0.75;
        }
        ofSetLineWidth(1);
    }

    void update(){
        radius = radius<targetRadius ? radius+1 : targetRadius;
        rot += rotSpeed;

        poly.clear();
        for(int i=0; i<360;i+=1){
            ofPoint p = ofPoint(radius * cos(i * DEG_TO_RAD), radius * sin(i * DEG_TO_RAD));
            float noise = ofMap(ofNoise(p.x*0.001+x, p.y*0.001+y, ofGetFrameNum()*0.005), 0, 1, 0.2, 1.2);
            p *= noise;
            poly.addVertex(p);
        }
        poly.close();

        ofTessellator tess;
        tess.tessellateToMesh(poly, ofPolyWindingMode::OF_POLY_WINDING_ODD, vboMesh);
        vboMesh.addColors(cols);
    }

    void draw(){
        ofPushStyle();
        ofPushMatrix();
        ofEnableAlphaBlending();
        ofTranslate(x,y);
        ofRotate(rot);
        vboMesh.draw();
        poly.draw();
        ofPopMatrix();
        ofPopStyle();
    }
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

    vector<ofPtr<gradationAmeba> > ameba;
};
