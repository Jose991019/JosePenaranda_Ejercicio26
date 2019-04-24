#include <iostream>
#include <fstream>
using namespace std;


void euler(float t_init, float t_end, float delta_t, float omega, string filename);
//void runge_kutta(float t_init, float t_end, float delta_t, float omega, string filename);


int main(){
  float omega=1;
  euler(0.0, 30, 0.001/omega, omega, "euler_0001.dat");
  //runge_kutta(0.0, 4.0/omega, 0.01/omega, omega, "implicit_001.dat");
  return 0;
}

void euler(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float ysig = 1.0;
  float yant=1.0;
  float z=0;
  ofstream outfile;
  outfile.open(filename);

  while(t<t_end){    
    outfile << t << " " << ysig << " " << z << endl;
    yant = ysig;
    ysig = yant + delta_t * z;
    z = z + delta_t*(-omega*omega*yant);
    t = t + delta_t;
  }
  outfile.close();
}

//void runge_kutta(float t_init, float t_end, float delta_t, float omega, string filename){
//  float t=t_init;
//  float y=1.0;
//  ofstream outfile;
//  outfile.open(filename);
//
//  while(t<t_end){    
//    outfile << t << " " << y << endl;
//    y = y/(1+delta_t*omega);
//    t = t + delta_t;
//  }
//  outfile.close();
//}
