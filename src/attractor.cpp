//
//  attractor.cpp
//  Strange Attractor
//
//  Created by Masahito H. on 2017/12/08.
//

#include "attractor.h"

attractor :: attractor(double as, double ab, double ar, int an): s(as), b(ab), r(ar), n(an){
    
}

void attractor :: drawAttractor(){
    double x = 1;
    double y = 1;
    double z = 1;
    double dt = 0.001;
    
    double dx, dy, dz;
    ofFill();
    for(int i = 0; i < n; i++){
        dx = s * (y - x);
        dy = x * (r - z) - y;
        dz = x * y - b * z;
        
        x += dt * dx;
        y += dt * dy;
        z += dt * dz;
        
        ofDrawCircle(x * 8, y * 8, z * 8, 1);
    }
    ofNoFill();
}

void attractor :: setSigma(double as){
    s = as;
}

void attractor :: setBeta(double ab){
    b = ab;
}

void attractor :: setRyo(double ar){
    r = ar;
}
