//
//  fractalFunction.cpp
//  Sierpinski Gasket
//
//  Created by reziov. on 2017/12/05.
//

#include "fractalFunction.h"

fractalFunction :: fractalFunction(int f){
    fractal = f;
    
    att = new attractor(10, 8 / 3, 28, fractal);
    
    ofDisableArbTex();
    pGraphics.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
}

ofFbo fractalFunction :: drawFractal(){
    pGraphics.begin();
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    ofBackground(0, 0, 0);
    ofSetColor(255, 0, 0);

    ofFill();
    att -> drawAttractor();
    ofNoFill();
    
    ofPopMatrix();
    pGraphics.end();

    pGraphics.draw(0, 0);
    
    return pGraphics;
}

attractor* fractalFunction :: getAttractor(){
    return att;
}
