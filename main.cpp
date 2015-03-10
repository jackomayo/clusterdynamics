/*
 * main.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: jmayo
 */
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;


int main(void){

//intialise and open file for writing results

FILE *results;
results=fopen("SimulationResults","w");


//Initialise r_0 inital radis of cluster
//M_0 initial mass of cluster
//t_rlx relaxation time
//t_cross crossing time
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
//G newtons grav const
//t_age
//t_start

double v2,t_start, t_age, G, r_t, M_t, v_avg, r_0, M_0, t_rlx, t_cross, M_avg, t, delta_t, delta_M_evol, delta_M_evap, R_gal;

//stellat evolution constants

double a_ev, b_ev,c_ev,log_q_ev, q_ev, log_t_a_ev;

//N_0number of stars in cluster initial
//N number of stars in cluster time 't'
double N_0,N;
//declare variables static and initial

G=6.67*pow(10,-11);

M_0=;
r_0=;
t_start=pow(10,6);
M_avg=0.4


//dynamic variables

// Mass loss due  to stellar evolution
log_t_a_ev=log10(delta_t)-a_ev;

log_q_ev=pow(log_t_a_ev,b_ev)+c_ev;

q_ev=pow(10,log_q_ev);




v2=(G*M_t/r_t);

v_avg=pow(v2,0.5);

t_cross=r_t/v_avg;


delta_M_evol;

delta_M_evap;

M_t=M_0-delta_M_evol- delta_M_evap;

t_rlx=N/8*log(N)*t_cross;

N=M_0/M_avg;

t_rlx=N/8*ln(N);


//Initial r0 M0 Trlx Tcross set conditions
//Trlx & Tcross functions of r(T) M(T)
//setup inital mass function Chabrier
//time step T+deltaT


//timestep function
double timestep()

//inputting M_0


return 0;

}
