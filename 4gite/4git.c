#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>



//strcat(char* chaine1,char* chaine2) concatene les 2 chaines dans la chaine 1
//strcpy(char* chaine1,char* chaine2) copie la 2eme chaine dans la 1ere
//strncpy(char* chaine1,char* chaine2,NCmax) copie mais limite au nombre max donné
//int strcmp(char* chaine1,char* chaine2) compare les 2 au sens alphabetique renvoie un nombre positif si la 1ere est superieur negatif si la 2 eme et 0 s elles sont egaux
//int strlen(char *chaine) renvoie la longueur de la chaine

//***************************
//int atoi(const char *s) convertit l argument s en un int
//***************************



int P[2][20];//polynome principale
int A[2][20],B[2][20];//des polynomes auxiliaires les reinitialiser avec des 0 avant de commencer a chaque fois

//poly[1]: coefficient  poly[0]:  degre
int comparPoly();//initialise les poly A et B par des 0 avant de prendre les poly et les comparer
int entrerPoly(int poly[][20],int nbreCoef);
int afficherPoly(int poly[][20],int nbreCoef);
int calculerImage(int poly[][20],int nbreCoef,int x);
int degrePoly(int poly[][20],int nbreCoef);
void multiplePoly(int Poly[][20],int a);
void multipleMonomePoly(int poly[][20],int a,int deg);
void trierPoly(int poly[][20]);
void initialiserPoly(int poly[][20]);//initialise les poly par des 0






int entrerPoly(int poly[][20],int nbreCoef){
	int i =0;
	
	
	for(i=0;i<nbreCoef;i++){
		printf("donnez le coefficient %d:  ",i);
		scanf("%d",&poly[1][i]);
		
		printf("donnez le degres %d:  ",i);
		scanf("%d",&poly[0][i]);
	}
}

int afficherPoly(int poly[][20],int nbreCoef){//dans la fct main le polynome est trié puis affiché et n affiche pas les monome avec le coefficient 0
	int i = 0,f=0;
	
	
	if(poly[1][0]==0){
		printf("P(x)=0");
	}else{
	
	
	if(poly[0][0] == 0)
		printf("P(x)= %d",poly[1][0]);
		
	if(poly[0][0]== 1)
		printf("P(x) = %dx",poly[1][0]);
		
	if(poly[0][0]>1 )
		printf("P(x)= %dx^%d",poly[1][0],poly[0][0]);
	}
	
	for(i=1;i<nbreCoef;i++){
		if(poly[1][i]==0){
			printf("");
		}else{
		
		
		if(poly[0][i] == 0 )
			printf(" +%d",poly[1][i]);
			
		if(poly[0][i] == 1)
			printf(" +%dx",poly[1][i]);
			
		if(poly[0][i]>1)
			printf(" +%dx^%d",poly[1][i],poly[0][i]);
		}	
	}
}



int calculerImage(int poly[][20],int nbreCoef,int x){
	int i = 0,S=0;
	
	for(i=0;i<nbreCoef;i++){
		S+= poly[1][i]*pow(x,poly[0][i]);
	}
	return S;
}

int degrePoly(int poly[][20],int nbreCoef){
	int degreMax,i=0;
	
	degreMax=poly[0][0];
	for(i=1;i<nbreCoef;i++){
		if(degreMax<poly[0][i])
			degreMax=poly[0][i];
	}
	
	return degreMax;
}

void multiplePoly(int poly[][20],int a){
	int i=0;
	for(i=0;i<20;i++){
		poly[1][i]*=a;
	}
}

void multipleMonomePoly(int poly[][20],int a,int deg){
	int i=0;
	for(i=0;i<20;i++){
		poly[1][i]*=a;
		poly[0][i]+=deg;
	}
}


void trierPoly(int poly[][20]){//additionne les coefficients qui ont les memes degres et les trie du plus grand au plus petit
	int degre=0,i=0,j=0,k=0, L[2][20];
	degre=degrePoly(poly,20);
	
	for(i=0;i<20;i++){
		L[0][i]=0;
		L[1][i]=0;
	}
	
	
	for(i=degre;0<=i;i--){
		for(j=0;j<20;j++){
			if(poly[0][j] == i){
				L[0][k]=poly[0][j];
				L[1][k]+=poly[1][j];
			}
		}
		
		if(L[1][k] !=0){
			k++;
		}else{
			L[0][k]=0;
		}
		
	}
	
	for(i=0;i<20;i++){
		poly[0][i]=L[0][i];
		poly[1][i]=L[1][i];
	}
	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
int comparPoly(){
	int i,f= 0,NC1,NC2,j=0,max=0,V0,V1 ;
	for(i=0;i<20;i++){
		A[0][i] = 0;
		A[1][i] = 0;
	} 
	for(i=0;i<20;i++){
		B[0][i] = 0;
		B[1][i] = 0;
	} 
	printf("donnez le nombre de coefficients du 1er polynome  ");
	scanf("%d",&NC1);
	for(i=0;i<NC1;i++){
		printf("donnez le coefficient %d   du polynome A(x):		",i);
		scanf("%d",&A[1][i]);
	
	
	
		printf("donnez le degres   %d   du polynome A(x):		",i);
		scanf("%d",&A[0][i]);
		
	}
		

	printf("donnez le nombre de coefficients du 2eme polynome  ");
	scanf("%d",&NC2);
	
	
	for(i=0;i<NC2;i++){
		printf("donnez le coefficient %d  du polynome B(x):		",i);
		scanf("%d",&B[1][i]);
	
	
	
		printf("donnez le degres   %d	du polynome B(x):	",i);
		scanf("%d",&B[0][i]);
		
	}
	
	
	trierPoly(A);
	
	trierPoly(B);
	
	
	if ( NC1<NC2){
		NC1=NC2;
	}
	i=0;
	
	for(i=0;i<NC1;i++){
		if(A[0][i]<B[0][i]){
			return -1;
		}
		if(B[0][i]<A[0][i]){
			return 1;
		}
		if(A[1][i]<B[1][i]){
			return -1;
		}
		if(B[1][i]<A[1][i]){
			return 1;
		}
		
	}
	return 0;	
}
void initialiserPoly(int poly[][20]){//initialise le poly par des  0
	int i =0;
	for(i=0;i<20;i++){
		poly[0][i]=0;
		poly[1][i]=0;
	}
}




