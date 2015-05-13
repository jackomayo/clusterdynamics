//============================================================================
// Name        : Dynamic.cpp
// Author      : Jack Mayo
// Version     :
// Copyright   : don't use this, is mine.
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * main.cpp
 *
 *  Created on: Mar 9, 2015
 *
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

//dynamic file naming
	double M_0,r_0;


	M_0= 1e4;
	r_0=2;


char sz1filename[255]={0};
char sz2filename[255]={0};
char sz3filename[255]={0};
char sz4filename[255]={0};


sprintf(sz1filename, "EvolutionScale_M_%.0e_R_%3.3lf_pc", M_0,r_0);
sprintf(sz2filename, "DynamicScale_M_%.0e_R_%3.3lf_pc", M_0,r_0);
sprintf(sz3filename, "MassLoss_M_%.0e_R_%3.3lf_pc", M_0,r_0);
sprintf(sz4filename, "TimescaleComparison_M_%.0e_R_%3.3lf_pc", M_0,r_0);


FILE *resultssev;
resultssev=fopen(sz1filename,"w");

FILE *resultsdts;
resultsdts=fopen(sz2filename,"w");

FILE *resultsfinal;
resultsfinal=fopen(sz3filename,"w");

FILE *resultsts;
resultsts=fopen(sz4filename,"w");

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


//N_0number of stars in cluster initial
//N number of stars in cluster time 't'
//double N_0,N;
//declare variables static and initial


double t,a_ev, b_ev,c_ev ,delta_t , log_t_a_ev,a,b,old_mass,t_0,new_mass,mass_step,t2;

double x,y,z;



//G=6.67*pow(10,-11);
t_0=12.5e6; //Myrs
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
//printf("%lf %lf %lf \n",t,delta_t, new_mass);


t=t+delta_t;


}

double N_0,M_avg, v_0_avg , v_0_avg_2 ,G, t_cross_0,t_rlx_0,t_rlx_new,t_rlx_old, N;

double t_cond, t_cond2;

G=4.518e-15;	//two orders of magnitude out should be -15


//M_0= 1000;
		//need radius function r proportional to M^-1/3 possibly half mass radius
M_avg=0.4;
N_0= M_0 / M_avg;

v_0_avg_2=(G*M_0)/(r_0);

v_0_avg=sqrt(v_0_avg_2);

t_cross_0=sqrt((r_0*r_0*r_0)/(G*M_0)); //for some reason this is wrong!!!!

//t_cross_0=10e6;

printf("t_cross= %lf\n",t_cross_0);

t_rlx_0=(N_0*t_cross_0)/(8*log(N_0));

printf("t_rlx_0= %lf\n",t_rlx_0);


t_rlx_old=t_rlx_0;

N=N_0;

t2=12.5e6;
//run time conditions
t_cond=1;
t_cond2=1e100;

//printf("%lf\n",t_rlx_0);


while (t_cond2>=t_cond)//placeholder death age 3e10 for dynamic timescale only
{


		t_rlx_new=log(N)*t_rlx_old*pow(mass_step,7/2)/(log(mass_step*N));

t_cond=t_rlx_new;

if(t_cond2>=t_cond){
//
fprintf(resultsdts,"%lf %lf \n",t2,t_rlx_new);
//printf("%lf %lf \n",t2,t_rlx_new);
}

N=mass_step*N;

t_cond2=t_rlx_old;
t_rlx_old=t_rlx_new;

t2=t2+t_rlx_new;


}


double delta_t_evol,delta_t_dynamic,mass_delta,M_total,M_previous,time_step,big_time;

double M_other;

t=12.5e6;
old_mass=M_0=1;

M_total=M_previous=1;

mass_step=0.99;
t_rlx_old=t_rlx_0;

N=N_0;

printf("t		M_total	 M_other delta_t_evol	delta_t_dynamic\n");

while(M_total>0)
{

	//work out timescale for stellar evolution

			log_t_a_ev= log10(t)-a_ev;



			a=pow(log_t_a_ev , b_ev);

			b=a+c_ev;

			old_mass =1-pow(10,b);

			new_mass=old_mass*mass_step;


			x=log10(1-new_mass)-c_ev;
			y=pow(x,1/b_ev);
			z=y+a_ev;
			t2=pow(10,z);

			delta_t_evol=t2-t;


			//dynamics time scale with feedback mass loss

			mass_delta=M_total/M_previous;

			N=M_total*N_0;

			delta_t_dynamic=log(N_0)*t_rlx_0*pow(M_total,7/2)/(log(M_total*N));


			if (M_total>0)
			{
				  fprintf(resultsts,"%lf %lf %lf\n",t,delta_t_evol,delta_t_dynamic);
			}

			if (delta_t_evol<delta_t_dynamic )//sort the timescales into biggest and smallest
			{
				time_step=delta_t_evol;
				big_time=delta_t_dynamic;
			}
			else{
				time_step=delta_t_dynamic;
				big_time=delta_t_evol;
			}

		M_previous=M_total;

		M_other=(time_step/big_time);

	  M_total=M_total-(1-mass_step)-(1-mass_step)*(time_step/big_time);


if (M_total>0)
{
	  printf("%lf %lf %lf %lf %lf\n",t,M_total, M_other,delta_t_evol,delta_t_dynamic);
//	  printf("%lf %lf\n",t,M_total);
	  fprintf(resultsfinal,"%lf %lf \n",t,M_total);
}

t=t+time_step;



}




fclose(resultssev);
fclose(resultsdts);
fclose(resultsfinal);
return 0;

}

