#include "ofApp.h"

double c = 0;
double s = 10;
double b = 8 / 3;
double r = 28;

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    fFunc = fractalFunction(50000);
    meshSize = 350;
    
//    mesh = ofSpherePrimitive(1, 500).getMesh();
    model.loadModel("hand.obj");
    mesh = model.getMesh(0);
    meshSetup(&mesh);
}

void ofApp::meshSetup(ofMesh* m){
    m -> clearColors();
    m -> clearTexCoords();
    
    for(int i = 0; i < m -> getVertices().size(); i++){
        ofVec3f v = m -> getVertex(i);
        v.x *= meshSize;
        v.y *= meshSize;
        v.z *= meshSize;
        m -> setVertex(i, v);
        
        ofVec3f n = m -> getNormal(i);
        ofVec2f e(n.x, n.z), e0(1, 0);
        e.normalize();
        double sita = acos(e.dot(e0) / (e.length() * e0.length()));
        double tx = cos(sita / 2);
        double ty = (v.y + 350) / 700;
        
        m -> addTexCoord(ofVec2f(tx, ty));
        m -> addColor(ofColor(0, 0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    c++;
    
    s += 0.01;
    b += 0.01;
    r += 0.01;
    fFunc.getAttractor() -> setSigma(s);
//    fFunc.getAttractor() -> setBeta(b);
//    fFunc.getAttractor() -> setRyo(r);
}

//--------------------------------------------------------------
void ofApp::draw(){
    pg = fFunc.drawFractal();
    
    pg.readToPixels(pix);
    tex.loadData(pix);

    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    ofRotateZDeg(180);
    ofRotateYDeg(c);
    
    textureUpdate(&mesh, &pix);
    mesh.draw();
    ofPopMatrix();
}

void ofApp::textureUpdate(ofMesh* m, ofPixels* p){
    for(int i = 0; i < m -> getTexCoords().size(); i++){
        ofVec2f co = m -> getTexCoord(i);
        int x = (int)(co.x * p -> getWidth());
        int y = (int)(co.y * p -> getHeight());
        ofColor col = p -> getColor(x, y);
        
        m -> setColor(i, col);
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
