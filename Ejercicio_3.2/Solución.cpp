#include <iostream>
#include <cmath>
#include <vector>

double phi(double x, std::vector<double> X, int j);
double LP(double x, std::vector<double> X, std::vector<double> Y);
double f1(double x);
double f2(double x);
double f3(double x);

int main(){

  return 0;
}


double phi(double x, std::vector<double> X, int j){
  double p=1;
  for(int i=0;i<X.size();i++){
    if(i==j){
      continue;
    }else{
      p*=(x-X[i])/(X[j]-X[i]);
    }
  }
  return p;
}

double LP(double x, std::vector<double> X, std::vector<double> Y){
  double lp=0;
  for(int i=0;i<=Y.size();i++){
    lp+=Y[i]*phi(x,X,i);
  }
  return lp;
}

double f1(double x){

}

double f2(double x){

}

double f3(double x){

}
