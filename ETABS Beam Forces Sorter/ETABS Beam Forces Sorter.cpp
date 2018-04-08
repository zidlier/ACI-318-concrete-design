//Beam Design Program 


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

#define PI 3.141592654

char story[7],beammark[4],loadcase[10];
int ok;
int p,s,q,r,n;

double location, shear, moment, tor;
double P[12], V[12],M[12],loc[12],V3[12], T[12],M2[12];
double MomentSupport1, MomentMidspan, MomentSupport2, ShearSupport1, ShearSupport2, ShearMidspan, Torsion,span;

int main(void)
{
	printf("ETAB Frame Output txt Sorter \n");
	printf("Gets beam clear span");
	printf("Moment on support 1, midspan, support 2\n");
	printf("Shear on support 1, midspan, support 2 \n\n\n");
	printf("Created by Aylsworth \n\n\n");
	
	printf("Read input data guideline. First data should be repeated \n");
	printf("How many beam data to be sorted?:");
	scanf("%d",&n);
	
	printf("\n\n\n");
	
	FILE* fptr=fopen("etabsbeamforces.txt","r");
	FILE* output=fopen("etabsbeamforces_sorted.txt","w+");

	//STORY	BEAM	LOAD	LOC	P	V2	V3	T	M2	M3
	//fprintf(output,"STORY\t BEAMMARK\t SPAN\t V2\t M3\n");
	
	for(r=1;r<=n;r++) {
	
	fscanf(fptr, "%s\t	%s\t 	%s\t  ", story, beammark,loadcase);
	
		for(p=0;p<=r;p++){
		fscanf(fptr, "%lf\t %lf\t %lf\t	%lf\t %lf\t %lf\t %lf\t", &location,&P[p],&shear,&V3[p],&tor,&M2[p],&moment);
			
				loc[p]=location;
				V[p]=shear;
				M[p]=moment;
				T[p]=tor;
				
			if(fscanf(fptr, "%lf\t %lf\t %lf\t	%lf\t %lf\t %lf\t %lf\t", &location,&P[p],&shear,&V3[p],&tor,&M2[p],&moment) == NULL)
	    	{
				span=loc[p];
				ShearSupport2=V[p];
				MomentSupport2=M[p];
				Torsion=T[p];
				
				if((p+1)/2 == 0){
					s=((p+1)/2);
					if(M[s] > M[s-1]){
						MomentMidspan=M[s];
						ShearMidspan=V[s];
					}else{
						MomentMidspan=M[s-1];
						ShearMidspan=V[s-1];
					}
				} if((p+1)/2 > 0){
					s=(p/2);
					ShearMidspan=V[s];
					MomentMidspan=M[s];
				}
								
				break;
	   		}
		}
			ShearSupport1=V[0];
			MomentSupport1=M[0];

	fprintf(output,"%s\t %s\t %s\t %3.3lf\t %5.2lf\t %5.2lf\t %5.2lf\t %5.2lf\t %5.2lf\t%5.2lf\t %5.2lf\t\n",story, beammark,loadcase,span, MomentSupport1, MomentMidspan, MomentSupport2, ShearSupport1,ShearMidspan,ShearSupport2,Torsion);
	//printf("%s\t %s\t %s\t %3.3lf\t %5.2lf\t %5.2lf\t %5.2lf\t %5.2lf\t %5.2lf\t%5.2lf\t \n",story, beammark,loadcase,span, MomentSupport1, MomentMidspan, MomentSupport2, ShearSupport1,ShearMidspan,ShearSupport2);	

    }
	
	printf("Sorting done. Output created. Check etabsbeamforces_sorted.txt \n");
	printf("Disregard first 2 lines");
return 1;

}
