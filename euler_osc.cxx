#include <iostream>;
#include <cmath>;

using namespace std;

int main() {
  
  const double dt = M_PI/10;
  const double tmin = 0;
  const double tmax = 20* M_PI;
  const int N = tmax/dt;
  
  //each 2-d vector contains  {x(t), x'(t)} at one specific time instance t
    //Euler forward
    double y0_f[2] = {1,0}	//initial conditions
    double y1_f[2];
    
    //Euler backward
    double y0_b[2] = {1,0}	//initial conditions
    double y1_b[2];
  
  for( int i=0; i<N; i++){
    
    //Euler forward
    y1_f[0] = y0_f[0] + y0_f[1]*dt;
    y1_f[1] = y0_f[1] - y0_f[0]*dt;
  }
  
  return 0;
}

