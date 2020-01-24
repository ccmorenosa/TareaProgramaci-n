#include <iostream>
#include <cmath>
#include <functional>

double s(double t, double w);
double W(double w);
double root(std::function<double(double)> F, double wi);

int main(){
  double r=root(W,0.5);
  double S=s(1.0,r);
    std::cout<<"El valor de omega es: "<<r<<" y s(1,omega)="<<S<<"\n";
  return 0;
}

double root(std::function<double(double)> F, double wi){
  double r=wi;
  double h=1e-10;
  double tolerance=1e-5;
  while(std::abs(F(r))>=tolerance){
    r-=F(r)*h/(F(r+h)-F(r));
  }
  return r;
}

double W(double w){
  return s(1.0,w)-1;
}

double s(double t, double w){
  double g=9.8;
  return g*(std::sinh(w*t)-std::sin(w*t))/(2*w*w);
}
