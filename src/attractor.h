//
//  attractor.h
//  Strange Attractor
//
//  Created by reziov. on 2017/12/08.
//

#ifndef attractor_h
#define attractor_h

#include "ofMain.h"

#endif /* attractor_h */

class attractor{
public:
    double s, b, r;
    int n;
    
    attractor(double as, double ab, double ar, int an);
    
    void drawAttractor();
    
    void setSigma(double as);
    void setBeta(double ab);
    void setRyo(double ar);
};
