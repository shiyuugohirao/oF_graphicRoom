#pragma once

#include "ofMain.h"


class gradationBox{
private:
    int x,y,z;
    ofVboMesh vbo;
    float rot,rotX,rotY,rotZ;

public:
    void setup(float x, float y, float z=0, float w=50,float h=50,float d=50){
        this->x = x;
        this->y = y;
        this->z = z;
        vbo = ofMesh::box(w,h,d,1,1,1);
        vbo.clearColors();
        for(int i=0; i<vbo.getNumVertices(); i++){
            ofFloatColor c;
            c.setHsb(ofRandom(1), .6, 1., 0.75);
            //c.set(ofRandom(1),1);
            vbo.addColor(c);
        }
    }
    void update(){
        rot+=0.1;
        float r = sin(DEG_TO_RAD*rot);
        cout<<r<<endl;
        rotX= ofSignedNoise(r,  x);
        rotY= ofSignedNoise(r , y);
        rotZ= ofSignedNoise(r , z);
    }

    void draw(){
        ofPushMatrix();
        ofTranslate(x,y,z);
        ofRotate(60, rotX, rotY, rotZ);
        vbo.draw();
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
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    vector<ofPtr<gradationBox> > box;
};
