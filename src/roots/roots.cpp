#include <iostream>
#include "roots.hpp"
#include <cmath>

bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root) {
    
    double tol = 1e-6;
    int iters = 1000;
    
    double fa = f(a);
    double fb = f(b);
    
    if (fa * fb > 0)  
        return false;
    
    for (int i = 0; i < iters; i++) {
        double c = (a + b) / 2.0;
        double fc = f(c);
        
        if (fabs(fc) < tol || (b - a) / 2.0 < tol) {
            *root = c;
            return true;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } 
        
        else {
            a = c;
            fa = fc;
        }
    }
    
    return false;
}



bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {
                
    double c = 0;
    double tol = 1e-6;
    int iters = 1000;
    
    double fa = f(a);
    double fb = f(b);
    
       if (fa * fb >= 0) {
            return false;
        }
    
    for (int i = 0; i < iters; i++) {

        

        c = (a * fb - b * fa) / (fb - fa);
        double fc = f(c);

        
        if (fabs(fc) < tol) {
            *root = c;
            return true;
        }
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } 
        
        else {
            a = c;
            fa = fc;
        }

    }

    return false;
}


// Newton Raphson 
bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root){
    

    double tol = 1e-6;
    int iters = 1000;
    double c_new = 0;

    for (int i = 0; i < iters; i++) {
        if (g(c) < 0) {
            return false;
        }
        
        c_new = c - (f(c)/g(c));

        if (c_new < a || c_new > b) {
            return false;
        
        }

        if (c_new - c <= tol) {
            *root = c_new;
            return true;
        }

        c = c_new;
    }
         
    return false;
}




bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root){
    
    double tol = 1e-6;
    int iters = 1000;
    double c_p1 = c + 1;
    double c_m1 = c - 1;

    for (double i = 0; i < iters; i++) {

        c_p1 = c - f(c)*(c-c_m1) / (f(c)- f(c_m1));

                if (c_p1 < a || c_p1 > b) {
                return false;
        
        }

        if (c_p1 - c <= tol) {
            *root = c_p1;
            return true;
        }

        c = c_p1;
    }
         
    return false;
}


