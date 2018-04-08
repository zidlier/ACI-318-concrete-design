//Beam Design Program 


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.141592654

int i, e, g;
double cc=40.0;
char beammark[5];
double b,h,ln,db,ds,fc,fy,fyt;
double rhomin, rhomax, beta1;
double MomSupport1Top, MomSupport1Bot, MomMidspanTop, MomMidspanBot, MomSupport2Top, MomSupport2Bot, ShearSupport1, ShearSupport2, ShearMidspan, Torsion;
double Ab,hmin,d,dprime, maxbarperlayer, AsSupport1Top,AsSupport1Bottom, AsSupport2Bottom,AsSupport2Top, AsMidspanBottom, AsMidspanTop;
double a1, a2, a3, a4, a5, a6;

double support1top, support1bot, midspantop, midspanbot, support2top, support2bot;
int c, r,n, ok;


int main(void)
{

	FILE* fptr=fopen("beaminput.txt","r");
	FILE* output=fopen("beamdesign_output.txt","w+");

	//fprintf(output,"\t\t\tTop Bars\tBottom Bars\tTop Bars\tTop Bars\tBottom Bars\tTop Bars \n");
	fprintf(output,"BeamMark\tWidth\tDepth\tDia\tSupport1Top\tSupport1Bot\tMidTop\tMidBot\tSupport2Top\tSupport2Bot\tds\tSpacing\tRemarks \n");

	fscanf(fptr, "%d \n",&n);
	for(r=1;r<=n;r++) {
	
	//fscanf(fptr, "%s	%lf	%lf	%lf	%lf	%lf	%lf	%lf	%lf	%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", beammark, &b, &h,&ln, &db, &ds, &fc, &fy, &fyt, &MomSupport1Top, &MomSupport1Bot, &MomMidspanTop, &MomMidspanBot, &MomSupport2Top,&MomSupport2Bot , &ShearSupport1, &ShearMidspan, &ShearSupport2,&Torsion);
	fscanf(fptr, "%s	%lf	%lf	%lf	%lf	%lf	%lf	%lf %lf %lf %lf %lf %lf %lf %lf %lf\n", beammark, &b, &h,&ln, &db, &ds, &fc, &fy, &fyt, &MomSupport1Top, &MomMidspanBot, &MomSupport2Top, &ShearSupport1, &ShearMidspan, &ShearSupport2,&Torsion);
	
	
	
	dprime = cc + ds+ (0.5*db);
	d = h-dprime;
	
	if(fc<=28.0){
		beta1=0.85;
	}else{ if(fc>=56.0){
			beta1=0.65;
			} else {
			beta1=0.85*(fc/fy)*beta1*(fc-28)*(1/7);
			}
	}
	
	if(1.4/fy < sqrt(fc)/(4*fy)){
		rhomin =  sqrt(fc)/(4*fy);
	} else{
		rhomin = 1.4/fy;
	}
	rhomax= 0.85*beta1*(fc/fy)*(3.0/7.0);
	
	//area on one dia. bar
	Ab = 0.25*PI*db*db;

	hmin = (0.4+(fy/700))/(ln/16);	
	
	if(h <hmin){
	printf("ERROR on h, must be greater that %4.2f", hmin);
	return 1;
	}
	
	maxbarperlayer=floor((b-2*cc-2*ds+25)/(db+25));
	
	
	
	
	
	
	//For Support1 Design moment -top
	a1=50.0;
	for(e=1;e<=20;e++){
	AsSupport1Top = (fabs(MomSupport1Top)*1000000.0)/(0.9*fy*(d-0.5*a1));
	a1=(AsSupport1Top*fy)/(0.85*fc*b);
	}
	printf("%5.2lf	 \n",AsSupport1Top);
	
	if(AsSupport1Top > (rhomax*b*d)){
		AsSupport1Top = rhomax*b*d;

	}
	 if(AsSupport1Top < (rhomin*b*d)){
		AsSupport1Top = rhomin*b*d;
	
		}
	
	
	support1top = (AsSupport1Top/Ab);
	
	
	
	//MomSupport1Bot=0.5*MomSupport1Top;
	//For Suppor 1 Design Moment Bottom

	AsSupport1Bottom = 0.5*AsSupport1Top;
	
	printf("%5.2lf	 \n",AsSupport1Bottom);
	
	if(AsSupport1Bottom > (rhomax*b*d)){
		AsSupport1Bottom = rhomax*b*d;
	
	}
	if(AsSupport1Bottom < (rhomin*b*d)){
		AsSupport1Bottom = rhomin*b*d;
		
		}
	
	support1bot = ((AsSupport1Bottom)/Ab);
	
	
	
		
	
	
	
	
	
	
	
	//For Midspan Design Moment - positive	
	a2=50.0;
	for(e=1;e<=20;e++){
	AsMidspanBottom = (fabs(MomMidspanBot)*1000000.0)/(0.9*fy*(d - 0.5*a2));
	a2=(AsMidspanBottom*fy)/(0.85*fc*b);
	}
	
	if(AsMidspanBottom > (rhomax*b*d)){
		AsMidspanBottom = rhomax*b*d;
	
	} 
	if(AsMidspanBottom < (rhomin*b*d)){
		AsMidspanBottom = rhomin*b*d;
		
		}
	
	midspanbot = (AsMidspanBottom/Ab);
	
	//Midspan Moment Top
	//MomMidspanTop=0.5*MomMidspanBot;
	//a5=50.0;
	//for(e=1;e<=20;e++){
	//AsMidspanTop = (fabs(0.5*MomMidspanBot)*1000000.0)/(0.9*fy*(d-0.5*a4));
	//a5=(AsMidspanTop*fy)/(0.85*fc*b);
	//}
	//printf("%5.2lf	 \n",AsMidspanTop);
	
	AsMidspanTop = 0.5*AsMidspanBottom;
	
	if(AsMidspanTop > (rhomax*b*d)){
		AsMidspanTop = rhomax*b*d;
		
	}
	 if(AsMidspanTop < (rhomin*b*d)){
		AsMidspanTop = rhomin*b*d;
		
		}
	
		midspantop = (AsMidspanTop/Ab);
	












	a3=50.0;
	for(e=1;e<=20;e++){
	AsSupport2Top = (fabs(MomSupport2Top)*1000000.0)/(0.9*fy*(d-0.5*a3));
	a3=(AsSupport2Top*fy)/(0.85*fc*b);
	}
	printf("%5.2lf	 \n",AsSupport2Top);
	
	if(AsSupport2Top > (rhomax*b*d)){
		AsSupport2Top = rhomax*b*d;
		
	}
	 if(AsSupport2Top < (rhomin*b*d)){
		AsSupport2Top = rhomin*b*d;
		
		}
	
	
	support2top = (AsSupport2Top/Ab);
	
	
	//For Suppor 1 Design Moment Bottom
//	MomSupport2Bot=0.5*MomSupport2Top;
	
//	a6=50.0;
//	for(e=1;e<=20;e++){
///	AsSupport1Bottom = (fabs(MomSupport2Bot)*1000000.0)/(0.9*fy*(d-0.5*a6));
//	a6=(AsSupport1Bottom*fy)/(0.85*fc*b);
//	}
//	printf("%5.2lf	 \n",AsSupport2Bottom);
	
	AsSupport2Bottom = 0.5*AsSupport2Top;
	
	if(AsSupport2Bottom > (rhomax*b*d)){
		AsSupport2Bottom = rhomax*b*d;
	}
	 if(AsSupport2Bottom < (rhomin*b*d)){
		AsSupport2Bottom = rhomin*b*d;
		}
	
	
	support2bot = ((AsSupport2Bottom)/Ab);	
	
	
	
	
	
	
	
	//Shear Reinforcement
	
	double phis = 0.75;
	double Vc = 0.17*sqrt(fc)*b*d*0.001;
	double Av=0.25*PI*ds*ds*2;
	double Vs[2], s[2];
	double w = (fabs(ShearSupport1) - fabs(ShearMidspan))/(0.5*ln);
		

	Vs[0] = ((fabs(ShearSupport1)-d*w)/phis)-Vc;
	s[0] = (Av*fyt*d)/Vs[0]; 		
	
	Vs[1]=  ((fabs(ShearSupport1)-2*h*w)/phis)-Vc;
	s[1]= (Av*fyt*d)/Vs[1];
	
	if(s[0]>=100 || s[0]<=0) {
	//	printf("Shear reinforcement OK!\n");
	ok = 1;
	}
	if(s[1]>=100 || s[1]<=0) {
		//printf("Shear reinforcement OK!\n");
		ok = 1;
	}

	printf("%s	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	1@50,%2.2lf@100mm, rest@200 %d \n\n\n",beammark,b,h,db,support1top, support1bot, midspantop, midspanbot, support2top, support2bot,ds,h/50.0,ok);	
	
	fprintf(output,"%s\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t1@50,%2.0lf@100mm, rest@200\t %d \n",beammark,b,h,db,support1top, support1bot, midspantop, midspanbot, support2top, support2bot,ds,h/50,ok);
}
	//fclose(fptr);
    //fclose(output);
    
return 0;

}
