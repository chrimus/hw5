#include <iostream>
#include <cmath>

using namespace std;

int main() {
  
  const double dt = M_PI/10;
  const double tmin = 0;
  const double tmax = 20* M_PI;
  const int N = (tmax-tmin)/dt;
  
  //each 2-d vector contains  {x(t), x'(t)} at one specific time instance t
    //Euler forward
    double y0_f[2] = {1,0};	//initial conditions (inital value at n)
    double y1_f[2];			//result after iteration step (value at n+1)
    
    //Euler backward
    double y0_b[2] = {1,0};	//initial conditions
    double y1_b[2];
	
	//Analytic solution
	double y0_a;			//save just x(t), x'(t) is not needed
	
  //print initial values
  cout << tmin << "\t" << 1 << "\t" << 1 << "\t" << 1 << endl;
  for( int i=1; i<=N; i++){
    
    //Euler forward
    y1_f[0] = y0_f[0] + y0_f[1]*dt;		// y1(n+1) = y1(n) + y1'(n)*dt
    y1_f[1] = y0_f[1] - y0_f[0]*dt;		// y2(n+1) = y2(n) + y2'(n)*dt
    
    y0_f[0] = y1_f[0];
	y0_f[1] = y1_f[1];
	
	
	//Euler backward
	y1_b[0] = (y0_b[0]+y0_b[1]*dt)/(1+dt*dt);		// y1(n+1) = (y1(n) + y2(n)*dt) / (1+dt²)
	y1_b[1] = (y0_b[1]-y0_b[0]*dt)/(1+dt*dt);		// y2(n+1) = (y2(n) - y1(n)*dt) / (1+dt²)
	
	y0_b[0] = y1_b[0];
	y0_b[1] = y1_b[1];
	
	//Analytic solution
	// x(t) = y0_a(t) = cos(t)
	y0_a = cos(tmin + dt*i);
	
	//Print all results for current timeinstance t_i = tmin + dt*i
	cout << tmin + dt*i << "\t" << y1_f[0] << "\t" << y1_b[0] << "\t" << y0_a << endl;
  }
  
  return 0;
}

