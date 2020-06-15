#pragma once

#include "ofMain.h"
#include "fractalFunction.h"
#include "ofxAssimpModelLoader.h"

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
		
    fractalFunction fFunc = fractalFunction(1);
    
    int meshSize;
    ofImage img;
    ofFbo pg;
    ofPixels pix;
    ofTexture tex;
    
    ofxAssimpModelLoader model;
    
    ofMesh mesh;
    
    void meshSetup(ofMesh* m);
    void textureUpdate(ofMesh* m, ofPixels* p);
};
