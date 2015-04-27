//============================================================================
// Name        : Dynamic.cpp
// Author      : Jakc Mayo
// Version     :
// Copyright   : don't use this, is mine.
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * main.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jmayo
 */


//In retarded astro units that we made up.
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;


int main(void){

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
//
//intialise and open file for writing results

FILE *resultssev;
resultssev=fopen("Stellarevolutiontimescale","w");

FILE *resultsdts;
resultsdts=fopen("Dynamictimescale","w");


//SI UNITS all
//Initialise r_0 inital radis of cluster
//M_0 initial mass of cluster 3.6*10^4
//R_0 10 pc
//t_rlx relaxation time
//t_cross crossing time 1000 Myr
//M_sun
//M_avg average mass of star
//t time current
//delta_t time step
//delta_M_evol mass loss form stellar evolution
//delta_M_evap mass loss form evaporation
//R_gal radius from centre of galaxy
//v_avg average velocity of stars in cluster at time t
//M_t mass of cluster at time t
//r_t radius at time t
//G Newtons grav const
//t_age
//t_start
//atro unit converion pc-->m, solar masses-->kg



//double v2,t_start, t_age, G, r_t, M_t, v_avg, r_0, M_0, t_rlx, t_cross, M_avg, t, delta_t, delta_M_evol, delta_M_evap, R_gal;


//N_0number of stars in cluster initial
//N number of stars in cluster time 't'
//double N_0,N;
//declare variables static and initial


double t,a_ev, b_ev,c_ev ,delta_t , log_t_a_ev,a,b,old_mass,t_0,new_mass,mass_step,t2;

double x,y,z;



//G=6.67*pow(10,-11);
t_0=12.5*pow(10,6);
t=t_0;

new_mass=1.0;

mass_step=0.99;

while (new_mass>=0.12)//placeholder death age 3e10 for stellar timescale only
{


			 a_ev=7.0;
			 b_ev=0.255;
			 c_ev=-1.805;





			log_t_a_ev= log10(t)-a_ev;

		a=pow(log_t_a_ev , b_ev);

		b=a+c_ev;

		old_mass =1-pow(10,b);

		new_mass=old_mass*mass_step;


		x=log10(1-new_mass)-c_ev;
		y=pow(x,1/b_ev);
		z=y+a_ev;
		t2=pow(10,z);
		delta_t=t2-t;


fprintf(resultssev,"%lf %lf \n",t,delta_t);
printf("%lf %lf %lf \n",t,delta_t, new_mass);


t=t+delta_t;


}

double N_0,M_avg, M_0, v_0_avg , v_0_avg_2 ,G,r_0,t_cross_0,t_rlx_0,t_rlx_new,t_rlx_old, N;

double t_cond;

G=4.518e-17;	//two orders of magnitude out should be -15


M_0= 3.6e4;
r_0=100;
M_avg=0.4;
N_0= M_0 / M_avg;

v_0_avg_2=(G*M_0)/(r_0);

v_0_avg=sqrt(v_0_avg_2);

t_cross_0=r_0/v_0_avg;

t_rlx_0=(N_0*t_cross_0)/8*log(N_0);

t_rlx_old=t_rlx_0;

N=N_0;

t2=12.5e6;

t_cond=t2;

//printf("%lf\n",t_rlx_0);


while (t2>=t_cond)//placeholder death age 3e10 for dynamic timescale only
{
		t_cond=t2;

		t_rlx_new=log(N)*t_rlx_old*pow(mass_step,3/2)/(log(mass_step*N));


//
fprintf(resultsdts,"%lf %lf \n",t2,t_rlx_new);
//printf("%lf %lf \n",t2,t_rlx_new);

N=mass_step*N;

t_rlx_old=t_rlx_new;

t2=t2+t_rlx_new;


}







//
//
////dynamic variables
//
//
//
//



//Initial r0 M0 Trlx Tcross set conditions
//Trlx & Tcross functions of r(T) M(T)
//setup inital mass function Chabrier
//time step T+deltaT


//timestep function




fclose(resultssev);
fclose(resultsdts);

return 0;

}

