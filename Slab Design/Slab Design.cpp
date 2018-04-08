//Slab Design Program


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.141592654



double CaNegShor[11][9] = { 
{0.000,	0.086,	0.000,	0.094,	0.090,	0.097,	0.000,	0.089,	0.088},
{0.000,	0.084,	0.000,	0.092,	0.089,	0.096,	0.000,	0.085,	0.086},
{0.000,	0.081,	0.000,	0.089,	0.088,	0.095,	0.000,	0.080,	0.085},
{0.000,	0.077,	0.000,	0.085,	0.087,	0.093,	0.000,	0.074,	0.083},
{0.000,	0.074,	0.000,	0.081,	0.086,	0.091,	0.000,	0.068,	0.081},
{0.000,	0.069,	0.000,	0.076,	0.085,	0.088,	0.000,	0.061,	0.078},
{0.000,	0.065,	0.000,	0.071,	0.083,	0.086,	0.000,	0.055,	0.075},
{0.000,	0.060,	0.000,	0.066,	0.082,	0.083,	0.000,	0.049,	0.072},
{0.000,	0.055,	0.000,	0.060,	0.080,	0.079,	0.000,	0.043,	0.068},
{0.000,	0.050,	0.000,	0.055,	0.079,	0.075,	0.000,	0.038,	0.065},
{0.000,	0.045,	0.000,	0.050,	0.075,	0.071,	0.000,	0.033,	0.061}
};


double CbNegLong[11][9]={
{0.000,	0.006,	0.022,	0.006,	0.000,	0.000,	0.014,	0.100,	0.003},
{0.000,	0.007,	0.028,	0.008,	0.000,	0.000,	0.019,	0.014,	0.005},
{0.000,	0.010,	0.035,	0.011,	0.000,	0.000,	0.024,	0.018,	0.006},
{0.000,	0.014,	0.043,	0.015,	0.000,	0.000,	0.031,	0.024,	0.008},
{0.000,	0.017,	0.050,	0.019,	0.000,	0.000,	0.038,	0.029,	0.011},
{0.000,	0.022,	0.056,	0.024,	0.000,	0.000,	0.044,	0.036,	0.014},
{0.000,	0.027,	0.061,	0.029,	0.000,	0.000,	0.051,	0.041,	0.017},
{0.000,	0.031,	0.065,	0.034,	0.000,	0.000,	0.057,	0.046,	0.021},
{0.000,	0.037,	0.070,	0.040,	0.000,	0.000,	0.062,	0.052,	0.025},
{0.000,	0.041,	0.072,	0.045,	0.000,	0.000,	0.067,	0.056,	0.029},
{0.000,	0.045,	0.076,	0.050,	0.000,	0.000,	0.071,	0.061,	0.033},
};


double CaPosDLS[11][9]={
{0.095,	0.037,	0.080,	0.059,	0.039,	0.061,	0.089,	0.056,	0.023},
{0.088,	0.035,	0.071,	0.056,	0.038,	0.058,	0.081,	0.052,	0.024},
{0.081,	0.034,	0.062,	0.053,	0.037,	0.056,	0.073,	0.048,	0.026},
{0.074,	0.032,	0.054,	0.050,	0.036,	0.054,	0.065,	0.044,	0.028},
{0.068,	0.030,	0.046,	0.046,	0.035,	0.051,	0.058,	0.040,	0.029},
{0.061,	0.028,	0.040,	0.043,	0.033,	0.048,	0.051,	0.036,	0.031},
{0.056,	0.026,	0.034,	0.039,	0.032,	0.045,	0.045,	0.032,	0.029},
{0.050,	0.024,	0.029,	0.036,	0.031,	0.042,	0.040,	0.029,	0.028},
{0.045,	0.022,	0.025,	0.033,	0.029,	0.039,	0.035,	0.025,	0.026},
{0.040,	0.020,	0.021,	0.030,	0.028,	0.036,	0.031,	0.022,	0.024},
{0.036,	0.018,	0.018,	0.027,	0.027,	0.033,	0.027,	0.020,	0.023},
};


double CbPosDLL[11][9]={
{0.006,	0.002,	0.007,	0.004,	0.001,	0.003,	0.007,	0.004,	0.002},
{0.008,	0.003,	0.009,	0.005,	0.002,	0.004,	0.009,	0.005,	0.003},
{0.010,	0.004,	0.011,	0.007,	0.003,	0.006,	0.012,	0.007,	0.004},
{0.013,	0.006,	0.014,	0.009,	0.004,	0.007,	0.014,	0.009,	0.005},
{0.016,	0.007,	0.016,	0.011,	0.005,	0.009,	0.017,	0.011,	0.006},
{0.019,	0.009,	0.018,	0.013,	0.007,	0.013,	0.020,	0.013,	0.007},
{0.023,	0.011,	0.020,	0.016,	0.009,	0.015,	0.022,	0.015,	0.010},
{0.026,	0.012,	0.022,	0.019,	0.011,	0.017,	0.025,	0.017,	0.013},
{0.029,	0.014,	0.024,	0.022,	0.013,	0.021,	0.028,	0.019,	0.015},
{0.033,	0.016,	0.025,	0.024,	0.015,	0.024,	0.031,	0.021,	0.017},
{0.036,	0.018,	0.027,	0.027,	0.018,	0.027,	0.033,	0.023,	0.020},
};

double CaPosLLS[11][9]={
{0.095,	0.066,	0.088,	0.077,	0.067,	0.078,	0.092,	0.076,	0.067},
{0.088,	0.062,	0.080,	0.072,	0.063,	0.073,	0.085,	0.070,	0.063},
{0.081,	0.058,	0.071,	0.067,	0.059,	0.068,	0.077,	0.065,	0.059},
{0.074,	0.053,	0.064,	0.062,	0.055,	0.064,	0.070,	0.059,	0.054},
{0.068,	0.049,	0.057,	0.057,	0.051,	0.060,	0.063,	0.054,	0.050},
{0.061,	0.045,	0.052,	0.052,	0.047,	0.055,	0.056,	0.049,	0.046},
{0.056,	0.041,	0.048,	0.048,	0.044,	0.051,	0.051,	0.044,	0.042},
{0.050,	0.037,	0.043,	0.043,	0.041,	0.046,	0.045,	0.040,	0.039},
{0.045,	0.034,	0.039,	0.039,	0.037,	0.042,	0.040,	0.035,	0.036},
{0.040,	0.030,	0.035,	0.035,	0.034,	0.038,	0.036,	0.031,	0.032},
{0.036,	0.027,	0.032,	0.032,	0.032,	0.035,	0.032,	0.028,	0.030},
};


double CbPosLLL[11][9]={
{0.006,	0.004,	0.007,	0.005,	0.004,	0.005,	0.007,	0.005,	0.004},
{0.008,	0.006,	0.009,	0.007,	0.005,	0.006,	0.009,	0.007,	0.006},
{0.010,	0.007,	0.011,	0.009,	0.007,	0.008,	0.011,	0.009,	0.007},
{0.013,	0.010,	0.014,	0.011,	0.009,	0.010,	0.014,	0.011,	0.009},
{0.016,	0.012,	0.016,	0.014,	0.011,	0.013,	0.017,	0.014,	0.011},
{0.019,	0.014,	0.018,	0.016,	0.013,	0.016,	0.020,	0.016,	0.013},
{0.023,	0.017,	0.020,	0.020,	0.016,	0.019,	0.023,	0.019,	0.017},
{0.026,	0.019,	0.022,	0.023,	0.019,	0.022,	0.026,	0.022,	0.020},
{0.029,	0.022,	0.024,	0.026,	0.021,	0.025,	0.029,	0.024,	0.022},
{0.033,	0.025,	0.025,	0.029,	0.024,	0.029,	0.032,	0.027,	0.025},
{0.036,	0.027,	0.027,	0.032,	0.027,	0.032,	0.035,	0.030,	0.028},
};

double DECE[9][4]={
{1.0,	0.0,	1.0,	0.0},	
{0.0,	1.0,	0.0,	1.0},	
{1.0,	0.0,	0.0,	1.0},	
{1.0,	1.0,	1.0,	1.0},	
{0.0,	1.0,	1.0,	0.0},	
{1.0,	1.0,	1.0,	0.0},	
{1.0,	0.0,	1.0,	1.0},	
{1.0,	1.0,	0.0,	1.0},	
{0.0,	1.0,	1.0,	0.0},	
};



double k[11]={0.50,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95,1.0};


int i, e, g, mmin, mmax;
double b=1000.0;
double rhomin=0.002;
double cc=20.0;
double Ab,hmin,dshort,dlong,smaxm,smaxt,m;
double CaNS, CaPDS, CaPLS, CbNL, CbPDL, CbPLL;
char slabmark[4];

double NegMomS,PosMomSDL, PosMomSLL, NegMomL, PosMomLDL,PosMomLLL;
double AsNegShort, AsPosShort, AsNegLong, AsPosLong;
double stopshortcont, smidshort, stopshortdiscont, stoplongcont, smidlong, stoplongdiscont;
double a1,a2,a3,a4, a5, a6, AsDisconShort, AsDisconLong;

double la,lb,h,db,fc,fy,dl,ll;
double dlf,llf,tlf;
int c, r,n;
//struct Slab {
   
	
//}


int main(void)
{

	FILE* fptr=fopen("slabinput.txt","r");
	FILE* output=fopen("slabdesign_output.txt","w+");

	fprintf(output,"\t\t\tRebar parallel to  Short Span\tRebar parallel to Long Span \n");
	fprintf(output,"\t\t\tTop Bars\tBottom Bars\tTop Bars\tTop Bars\tBottom Bars\tTop Bars \n");
	fprintf(output,"SlabMark\tThickness\tDia\tDiscont.\tMidspan\tContiuous\tDiscont.\tMidspan\tContiuous\n");

	fscanf(fptr, "%d \n",&n);
	for(r=1;r<=n;r++) {
	
	fscanf(fptr, "%s	%lf	%lf	%lf	%lf	%lf	%lf	%lf	%lf	%d \n", slabmark, &la, &lb, &h, &db, &fc, &fy, &dl, &ll, &c);
	
	//ratio of short to long span
	m=la/lb;
	
	//area on one dia. bar
	Ab = 0.25*PI*db*db;
	
	printf("%s %f %f %f %f %f %f %f %f %d \n",slabmark, la, lb, h, db, fc, fy, dl, ll, c );
	//hmin
	if((1.0/180.0)*(la+la+lb+lb) > 90.0){
	hmin = (1.0/180.0)*(la+la+lb+lb);
	} else{
	hmin = 90.0;
	}
	
	if(h <hmin){
	printf("ERROR on h, must be greater that %4.2f", hmin);
	}
	
	//effective depth on short and long span
	dshort = h - cc-(0.5*db);
	dlong = h - cc-(1.5*db);	

	//max spacing for main bars
	if( 3*b > 450.0){
	smaxm = 450.0;
	} else {
	smaxm = 3*b;
	}
   	
	//max spacing for temp bars
	if( 5*b > 450.0){
	smaxt = 450.0;
	} else {
	smaxt = 3*b;
	}

	//factored load
	dlf= 1.2*dl;
	llf=1.6*ll;
	tlf = dlf+llf;

	for(g=0;g<=10;g++){
		if(m>=k[g] && m<=k[g+1]){
		mmin = g;
		mmax = g+1;
		}
	}
	
	printf("%d %d\n", mmin, mmax);
	
	//Shortspan
	CaNS = CaNegShor[mmin][c-1]+((CaNegShor[mmax][c-1]-CaNegShor[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);
	CaPDS = CaPosDLS[mmin][c-1]+((CaPosDLS[mmax][c-1]-CaPosDLS[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);
	CaPLS = CaPosLLS[mmin][c-1]+((CaPosLLS[mmax][c-1]-CaPosLLS[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);
	
	printf("%lf 	%lf %lf \n\n", CaNS, CaPDS, CaPLS);	
	
	
	PosMomSDL = CaPDS*la*la*(0.001*0.001)*dlf;
	PosMomSLL = CaPLS*la*la*(0.001*0.001)*llf;	
	NegMomS = CaNS*la*la*(0.001*0.001)*tlf;
	
	printf("NegMomS=%lf 	PosMomS=%lf \n\n", NegMomS, PosMomSDL+PosMomSLL);	
	
	//Longspan
	CbNL = CbNegLong[mmin][c-1]+((CbNegLong[mmax][c-1]-CbNegLong[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);
	CbPDL = CbPosDLL[mmin][c-1]+((CbPosDLL[mmax][c-1]-CbPosDLL[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);
	CbPLL = CbPosLLL[mmin][c-1]+((CbPosLLL[mmax][c-1]-CbPosLLL[mmin][c-1])/(k[mmax] - k[mmin]))*(m-k[mmin]);

	printf("%lf 	%lf %lf \n\n", CbNL, CbPDL, CbPLL);	

	PosMomLDL = CbPDL*lb*lb*(0.001*0.001)*dlf;
	PosMomLLL = CbPLL*lb*lb*(0.001*0.001)*llf;
	NegMomL = CbNL*lb*lb*(0.001*0.001)*tlf;
	
	printf("NegMomL=%lf 	PosMomL=%lf \n\n", NegMomL, PosMomLDL+PosMomLLL);	
	
	a1=50.0;
	for(e=1;e<=10;e++){
	AsNegShort = (NegMomS*1000000.0)/(0.9*fy*(dshort - 0.5*a1));
	a1=(AsNegShort*fy)/(0.85*fc*b);
	}
	
	
	a2=50.0;
	for(e=1;e<=10;e++){
	AsPosShort = ((PosMomSDL+PosMomSLL)*1000000.0)/(0.9*fy*(dshort - 0.5*a2));
	a2=(AsPosShort*fy)/(0.85*fc*b);
	}
	
	
	a3=50.0;	
	for(e=1;e<=10;e++){
	AsNegLong = (NegMomL*1000000.0)/(0.9*fy*(dlong - 0.5*a3));
	a3=(AsNegLong*fy)/(0.85*fc*b);
	}
	
	a4=50.0;
	for(e=1;e<=10;e++){
	AsPosLong = ((PosMomLDL+PosMomLLL)*1000000.0)/(0.9*fy*(dlong - 0.5*a4));
	a4=(AsPosLong*fy)/(0.85*fc*b);	
	}
		
		if(AsNegShort < 0.002*b*h){
		AsNegShort = 0.002*b*h;
		}
		if(AsNegLong < 0.002*b*h){
		AsNegLong = 0.002*b*h;
		}
		if(AsPosShort < 0.002*b*h){
		AsPosShort = 0.002*b*h;
		}
		if(AsPosLong < 0.002*b*h){
		AsPosLong = 0.002*b*h;
		}

	printf("AsNegShort = %f\n", AsNegShort);
	printf("AsPosShort = %f\n", AsPosShort);
	printf("AsNegLong = %f\n", AsNegLong);
	printf("AsPosLong = %f\n", AsPosLong);
	
	
	stopshortcont = ((Ab*b)/AsNegShort)*DECE[(c-1)][1];
	smidshort= (Ab*b)/AsPosShort;

	if(stopshortcont > smaxm){
		stopshortcont = smaxm;
	}
	if(smidshort > smaxm){
		smidshort = smaxm;
	}
	
	
	
	a5=50.0;
	for(e=1;e<=10;e++){
	AsDisconShort = ((1/3)*(PosMomSDL+PosMomSLL)*1000000.0)/(0.9*fy*(dshort - 0.5*a5));
	a5=(AsDisconShort*fy)/(0.85*fc*b);	
	}
		if(AsDisconShort < 0.002*b*h){
		AsDisconShort= 0.002*b*h;
		}
	stopshortdiscont = ((Ab*b)/AsDisconShort)*DECE[(c-1)][0] ;
	if(stopshortdiscont > smaxm){
		stopshortdiscont = smaxm;
	}	


	stoplongcont = ((Ab*b)/AsNegLong)*DECE[(c-1)][3];
	smidlong = (Ab*b)/AsPosLong;
	if(stoplongcont > smaxt){
		stoplongcont = smaxt;
	}
	if(smidlong > smaxt){
		smidlong = smaxt;
	}

	a6=50.0;
	for(e=1;e<=10;e++){
	AsDisconLong = ((1/3)*(PosMomLDL+PosMomLLL)*1000000.0)/(0.9*fy*(dlong - 0.5*a6));
	a6=(AsDisconLong*fy)/(0.85*fc*b);	
	}
		if(AsDisconLong < 0.002*b*h){
		AsDisconLong= 0.002*b*h;
		}
	stoplongdiscont = ((Ab*b)/AsDisconLong)*DECE[(c-1)][2];	
	if(stoplongdiscont > smaxt){
		stoplongdiscont = smaxt;
	}

	printf("%s	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf	%5.2lf \n\n\n",slabmark,h,db,stopshortdiscont,smidshort,stopshortcont,stoplongcont,smidlong,stoplongdiscont);	
	
	fprintf(output,"%s\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t%5.2lf\t \n",slabmark,h,db,stopshortdiscont,smidshort,stopshortcont,stoplongcont,smidlong,stoplongdiscont);
}
	//fclose(fptr);
    //fclose(output);
    
return 0;

}
