#include <bits/stdc++.h>

using namespace std;
typedef 	pair<int,int> 		ii;

/**
* Brent's algorithm for cycle-finding
* f(x) must be defined previously!
*/

ii brentCycleFinding(int x0) {
	int tortoise = x0, hare = f(x0), lambda, power;
	lambda = power = 1; 
	while (tortoise != hare) {
		if(lambda == power){
			tortoise = hare;
			power *= 2;
			lambda = 0;
		}
		hare = f(hare);
		lambda++;
	} 
	int mu = 0;  tortoise = hare = x0; 
	for(int k = 0; k < lambda; k++) hare = f(hare);
	while (tortoise != hare) { tortoise = f(tortoise), hare = f(hare), mu++; } 
	return ii(mu, lambda); 
}