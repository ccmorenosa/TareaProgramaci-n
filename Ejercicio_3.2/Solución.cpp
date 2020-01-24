#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

std::vector<double> Y(std::vector<double> X, std::function<double(double)> F);

double f1(double x);
double f2(double x);
double f3(double x);

double d5_f1(double x);
double d5_f2(double x);
double d5_f3(double x);

int main(){
  std::vector<double> x(5);
  x[0]=-1;
  for(int i=1;i<x.size();i++){
    x[i]=x[0]+0.5*i;
  }
  
  std::vector<double> d5_y=Y(x,d5_f1);

  double Ef=std::abs(d5_y[0])*std::pow(0.5,5)/(4*5);

  std::cout<<"max|f1(x)|= "<<std::abs(d5_y[0])<<"\t max|E_f1(x)|= "<<Ef<<'\n';
  
  d5_y=Y(x,d5_f2);

  Ef=std::abs(d5_y[0])*std::pow(0.5,5)/(4*5);

  std::cout<<"max|f2(x)|= "<<std::abs(d5_y[0])<<"\t max|E_f2(x)|= "<<Ef<<'\n';

  Ef=2*(1/std::pow(2,0.5))*std::pow(std::acos(-1)/4,5)/(4*5);

  std::cout<<"max|f3(x)|= "<<2*(1/std::pow(2,0.5))<<"\t max|E_f3(x)|= "<<Ef<<'\n';

  
  
  return 0;
}

std::vector<double> Y(std::vector<double> X, std::function<double(double)> F){
  std::vector<double> y(X.size());
  for(int i=0;i<X.size();i++){
    y[i]=F(X[i]);
  }
  return y;
}

double f1(double x){
  return std::cosh(x);
}

double f2(double x){
  return std::sinh(x);
}

double f3(double x){
  return std::cos(x)+std::sin(x);
}

double d5_f1(double x){
  return std::sinh(x);
}

double d5_f2(double x){
  return std::cosh(x);
}

double d5_f3(double x){
  return std::cos(x)-std::sin(x);
}
