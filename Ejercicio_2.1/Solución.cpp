#include <iostream>
#include <cmath>
#include <functional>
#include <cstdlib>

double f(double x, int g);

bool sign(double a, double b);

double search(std::function<double(double,int)> f, double a, int g);

int main(){

  for(int g=2;g<5;g++){
    double a=1/(std::rand()%100)+rand()%10;
    double b=search(f,a,g);
    if(b>a){
      std::cout<<"El cero de f se encuentra en ["<<a<<","<<b<<"] con gamma="<<g<<". f(a)="<<f(a,g)<<" f(b)="<<f(b,g)<<" \n";
    }else if(b<a){
      std::cout<<"El cero de f se encuentra en ["<<b<<","<<a<<"] con gamma="<<g<<". f(a)="<<f(a,g)<<" f(b)="<<f(b,g)<<" \n";
    }
  }
  
  return 0;
}

double f(double x,int g){
  double a=std::cosh(x);
  double b=std::cos(x);
  return a+b-g;
}

bool sign(double a, double b){
  if(a*b<0){
    return true;
  }else if(a*b>0){
    return false;
  }else{
    return false;
  }
}

double search(std::function<double(double,int)> f, double a, int g){
  double ya=f(a,g);
  double bs,bi;
  bs=a;
  bi=a;
  do{
    bs+=0.1;
    bi-=0.1;
    std::cout<<a<<"\t"<<bs<<"\t"<<bi<<"\n";
    if(sign(ya,f(bs,g))){
      return bs;
    }else if(sign(ya,f(bi,g))){
      return bi;
    }
  }while(true);
}
