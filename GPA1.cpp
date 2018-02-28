#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdlib.h>
#define sd(x) scanf("%d",&x)
using namespace std;

char subject[82];
int credits[6];
bool flag = false;double points = 0.0;
double as[5];int total = 0;
double att;
			
int main() {
	int t,test = 0;
	sd(t);
	while(t--) {
		flag = false;
		points = 0;
		test++;
		total = 0;
		scanf("%d %d %d %d %d %d",&credits[0],&credits[1],&credits[2],&credits[3],&credits[4],&credits[5]);
		total = credits[0] + credits[1] + credits[2] + credits[3] + credits[4] + credits[5];
		for(int l = 0; l < 6; l++) {
			char sub1[10],sub2[10],sub3[10],sub4[10],sub5[10];
			scanf("%s %s %s %s %s",sub1,sub2,sub3,sub4,sub5);
    		as[0] = atof(sub1);
    		as[1] = atof(sub2);
    		as[2] = atof(sub3);
    		as[3] = atof(sub4);
    		as[4] = atof(sub5);
			double internel;
			sort(as,as+3);
			internel = as[1] + as[2];
			internel = (internel * 9) / 8;
			att = as[4];
			if(att < 51) 
				internel += 5;
			else if(att < 61) 
				internel += 4;
			else if(att < 71) 
				internel += 3;
			else if(att < 81) 
				internel += 2;
			else if(att < 91) 
				internel += 1;
			double final = as[3] / 2;
			internel += final;
			double pt = 0;
			
			if(internel >= 91) 
				pt = (10 * credits[l]);
			else if(internel >= 81) 
				pt = (9 * credits[l]);
			else if(internel >= 71) 
				pt = (8 * credits[l]);
			else if(internel >= 61) 
				pt = (7 * credits[l]);
			else if(internel > 50) 
				pt = (6 * credits[l]);
			else if(internel == 50) 
				pt = (5 * credits[l]);
			else flag = true;
			if(pt == 0) 
				flag = true;
			else 
				points += pt;
		}
		if(flag) printf("FAILED, %.2lf\n",points/total);
		else printf("PASSED, %.2lf\n",points/total);
	}
	return 0;
}