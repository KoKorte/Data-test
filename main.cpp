#include "mbed.h"
#include <aani.h>
#include <alipaasto_kertoimet.h>
#include <twiddle.h>
//#include <ylipaasto_kertoimet.h>

#define SLOTX 2
#define CYCLEX 4
#define ADBUFFER 100
#define TS 0.000125   //8000


volatile int TimeToStartAgain = 0;
int slot = 0;
int cycle = 0;

float ympyraBufferi1[ADBUFFER]={0};
float ympyraBufferi2[ADBUFFER]={0};

int kirjoitusOsoite1 = 0;
int lukuOsoite1 = 0;
int kirjoitusOsoite2 = 0;
int lukuOsoite2 = 0;

float muisti[3][3]={{0}};
float tulos_cos[16]={0};
float tulos_sin[16]={0};
float tulos_abs[16]={0};
float input[16]={0};
Serial pc (USBTX,USBRX);

DigitalOut led1(LED1);
Ticker slottiKello;
Ticker aDDaKello;
AnalogIn AnalogToDigital(A0);
AnalogOut DigitalToAnalog(A2);
float IIR_suodatin(float, int);
void fft(float * input, float * real, float * imag, float * abs);
void print_task1(void);


void suodata(void)
{
	int naytteita = 0;
	if(kirjoitusOsoite1 >= lukuOsoite1)
	{
		naytteita = kirjoitusOsoite1-lukuOsoite1;
	}
	else
	{
		naytteita = kirjoitusOsoite1 + ADBUFFER - lukuOsoite1;
	}
	for(int i = 0;i<naytteita;i++)
	{
		float nayte = ympyraBufferi1[lukuOsoite1];
		nayte = IIR_suodatin(nayte,0);
		nayte = IIR_suodatin(nayte,1);
		nayte = IIR_suodatin(nayte,2);
		ympyraBufferi2[kirjoitusOsoite2] = nayte;
		//ympyraBufferi2[kirjoitusOsoite2] = ympyraBufferi1[lukuOsoite1];
		kirjoitusOsoite2 = (kirjoitusOsoite2 + 1)%ADBUFFER;
		lukuOsoite1 = (lukuOsoite1 + 1)%ADBUFFER;
	}
}

void burn(void)
{
	//pc.printf("burn printtaa\r\n");
	//sleep();
}
void kopioi(void)
{
	// kopioidaan viimeiset 16 näytettä ympyraBufferi1:stä
	int osoite = kirjoitusOsoite1 - 16;
	if(osoite < 0)
	{
		osoite = osoite + ADBUFFER;
	}
	for(int i = 0;i<16; i++)
	{
		input[i] = ympyraBufferi1[osoite];
		osoite = (osoite + 1)%ADBUFFER;
	}
}

void laskeFFT(void)
{
	fft(input,tulos_cos,tulos_sin,tulos_abs);
}



void (*funktioTaulukko[SLOTX][CYCLEX])() = {
{suodata, kopioi, laskeFFT, burn},
{suodata, kopioi, laskeFFT, burn}
};



int indeksi = 0;


void slottiKello_isr(void)
{
	slot = (slot + 1)%SLOTX;
	TimeToStartAgain = 1;  // tämä kertoo, että taas on aika lähteä hommmiin 
	//pc.printf("keskeytys printtaa\r\n");
}
void aDDaKello_isr(void)
{
	indeksi = (indeksi + 1)%80000;
	//DigitalToAnalog = taulukko[indeksi];
    ympyraBufferi1[kirjoitusOsoite1] = taulukko[indeksi];
	DigitalToAnalog = ympyraBufferi2[lukuOsoite2];
	kirjoitusOsoite1 = (kirjoitusOsoite1 + 1)%ADBUFFER;
	lukuOsoite2 = (lukuOsoite2 + 1)%ADBUFFER;
}

int main() {
	slottiKello.attach(&slottiKello_isr, 50*TS);
	aDDaKello.attach(&aDDaKello_isr, TS);
	while (1) 
	{
		//pc.printf("TimeToStartAgain = %d\r\n",TimeToStartAgain);
		//pc.printf("true = %d\r\n",true);
		//pc.printf("false = %d\r\n",false);
		if(TimeToStartAgain == 1)
		{
			//pc.printf("tanne mentiin\r\n");
			TimeToStartAgain = 0;
			for(cycle=0; cycle<CYCLEX; cycle++)
			{
				(*funktioTaulukko[slot][cycle])(); // dispatch next task
			}
			
		}
	}
	

}



float IIR_suodatin(float nayte,int suodatin)
{
	float tulos = 0;
	
    muisti[suodatin][2]=muisti[suodatin][1];
	muisti[suodatin][1]=muisti[suodatin][0];
	muisti[suodatin][0]= nayte - SOS[suodatin][4]*muisti[suodatin][1] - SOS[suodatin][5]*muisti[suodatin][2];

    tulos = SOS[suodatin][0]*muisti[suodatin][0] + SOS[suodatin][1]*muisti[suodatin][1] + SOS[suodatin][2]*muisti[suodatin][2];

    return tulos;	
}


void fft(float * input, float * real, float * imag, float * abs)
{
	int N = 16;
	for(int I = 0; I < N ; I++)
	{
		real[I]= 0;
		imag[I]= 0;
	}
	
	//for(int m = 1 ; m<6 ; m++) // lasketaan vain 1 = 500, 2=1000, 3=1500, 4=2000, 5 = 2500 Hz
	for(int m = 0 ; m<16 ; m++) // lasketaan kaikki taajuuskomponentit
	{
		for(int n = 0 ; n < N ; n++)
		{
			real[m] = real[m] + input[n]*kosini[m][n];
			imag[m] = imag[m] + input[n]*sini[m][n];
		}
		abs[m] = sqrt(real[m]*real[m] + imag[m]*imag[m]);
	}
}

void print_task1(void)
{
	for(int i = 0;i<16;i++)
	{
		//pc.printf("%f\r\n",tulos_cos[i]);
		pc.printf("Kosiniarvo = %f\r\n",tulos_cos[i]);
		pc.printf("Siniarvo   = %f\r\n",tulos_sin[i]);
		pc.printf("Abs arvo   = %f\r\n\n",tulos_abs[i]);
	}
}





