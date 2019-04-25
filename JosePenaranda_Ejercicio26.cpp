#include <iostream>
#include <fstream>
using namespace std;


void euler(float t_init, float t_end, float delta_t, float omega, string filename);
void RK4(float t_init, float t_end, float delta_t, float omega, string filename);
void leap_frog(float t_init, float t_end, float delta_t, float omega, string filename);

float f(float y, float v, float x, float omega){
    return -omega*omega*y;
}



int main(){
  float omega=1;
  euler(0.0, 10000, 0.5/omega, omega, "euler.dat");
  RK4(0.0, 10000, 0.5/omega, omega, "RK4.dat");
  leap_frog(0.0, 10000, 0.5/omega, omega, "leap_frog.dat");

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

void RK4(float t_init, float t_end, float h, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float v = 0;
  double k1, k2, k3, k4, l1, l2, l3, l4;
  ofstream outfile;
  outfile.open(filename);
  outfile << t << " " << y << " " << v << endl;
    
  while(t<t_end){    
    k1=h*v;
    l1=h*f(y, v, t, omega);
    k2=h*(v+l1/2);
    l2=h*f(y+k1/2, v+l1/2, t+h/2, omega);
    k3=h*(v+l2/2);
    l3=h*f(y+k2/2, v+l2/2, t+h/2, omega);
    k4=h*(v+l3);
    l4=h*f(y+k3, v+l3, t+h, omega);
    y+=(k1+2*k2+2*k3+k4)/6;
    v+=(l1+2*l2+2*l3+l4)/6;
    t += h;
    outfile << t << " " << y << " " << v << endl;
  }
  outfile.close();
}

void leap_frog(float t_init, float t_end, float delta_t, float omega, string filename){
  float t=t_init;
  float y=1.0;
  float v = 0;
  float v_prime;
  ofstream outfile;
  outfile.open(filename);
  outfile << t << " " << y << " " << v << endl;
    while(t<t_end){    
    v_prime = v + f(y,v,t,omega)*delta_t/2;
    y = y + v_prime*delta_t;
    v = v_prime + f(y,v,t,omega)*delta_t/2;
    t = t + delta_t;
    outfile << t << " " << y << " " << v << endl;
  }
  outfile.close();

}

