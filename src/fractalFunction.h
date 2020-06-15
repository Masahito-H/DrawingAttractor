//
//  fractalFunction.h
//  Sierpinski Gasket
//
//  Created by reziov. on 2017/12/05.
//

#ifndef fractalFunction_h
#define fractalFunction_h

#include "ofMain.h"
#include "attractor.h"

#endif /* fractalFunction_h */

class fractalFunction{
public:    
    ofFbo pGraphics;
    ofPixels pix;
    
    int fractal;
    attractor* att;
    
    fractalFunction(int f);
    
    ofFbo drawFractal();
    
    attractor* getAttractor();
};
