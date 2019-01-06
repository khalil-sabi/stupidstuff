#include"4git.c"

int P[2][20];//polynome principale
int A[2][20],B[2][20];//des polynomes auxiliaires les reinitialiser avec des 0 avant de commencer a chaque fois

int main(){
	int f=0,nbreCoef = 20,nbreCoef2=20, i=0, x=0, image=0, degreMax=0, a=1, degre,test,position = 0,deg=0,coef=0;
	//initialiser tout les polynomes par des 0
	for(i=0;i<20;i++){
		P[0][i]=0;
		P[1][i]=0;
		A[0][i]=0;
		A[1][i]=0;
		B[0][i]=0;
		B[1][i]=0;
	}
	//
	printf("P(x) = 0");
	do{
		printf("\n\n");
		printf("***************************************************MENU*****************************************************************\n");
		printf("1- entrer les coefficients et les degres du polynome\n");
		printf("2- afficher le polynome\n");
		printf("3- calculer l image d un entier\n");
		printf("4- chercher le degre du polynome\n");
		printf("5- comparer 2 polynomes\n");
		printf("6- multiplier le polynome par un nombre\n");
		printf("7- multiplier le polynome par un monome\n");
		printf("8- inserer un monome\n");
		printf("9- deriver le polynome\n");
		printf("0-QUITTER");
		printf("\n");
		printf("  -->");
		scanf("%d",&f);
		
		
		
		switch(f){
			
			case 1 :{
				initialiserPoly(P);//le renitialiser par des 0 pour que les anciennes valeurs soient effacées sinon on risque d avoir de fausses valeurs
				printf("donnez le nombre de coefficients  ");
				scanf("%d",&nbreCoef);
				entrerPoly(P,nbreCoef);
				break;
			}
			case 2 :{
				trierPoly(P);//trie le monome de la plus grande puissance a la plus petite et additionne les coefficients des monomes qui ont la meme puissance 
				afficherPoly(P,20);//n affiche pas les monome avec le coefficient 0
				break;
			}
			case 3:{
				printf("donnez un entier pour calculer son antecedant:  ");
				scanf("%d",&x);
				
				image=calculerImage(P,nbreCoef,x);
				printf("\nP(%d) = %d\n\n",x,image);
				break;
			}
			case 4:{
				degreMax=degrePoly(P,nbreCoef);
				printf("\n\nle plus grand degres est %d\n\n",degreMax);
				break;
			}
			case 5:{
				test=comparPoly();
				if(test==1){
				
					afficherPoly(A,20);
					printf(" est plus grand que ");
					afficherPoly(B,20);
				}	
				if(test==-1){
					afficherPoly(B,20);
					printf("est plus grand que");
					afficherPoly(A,20);
				}
				if(test==0){
					printf("les 2 polynomes sont egaux");
				}
				break;
			}
			case 6:{
				printf("vous voulez multiplier le polynome par:  ");
				scanf("%d",&a);
				multiplePoly(P,a);
				break;
			}
			case 7:{
				printf("le coefficient du monome:  ");
				scanf("%d",&a);
				
				printf("le degre du monome:  ");
				scanf("%d",&degre);
				
				multipleMonomePoly(P,a,degre);
				break;
			}
			case 8:{
				printf("donnez sa position");
				scanf("%d",&position);
				printf("donnez le degre");
				scanf("%d",&deg);
				printf("donnez le coefficient");
				scanf("%d",&coef);
				insererMonome(P,position,deg,coef);
				break;
			}
			case 9:{
				derivePoly(P);
				break;
			}
		}
		
		
		
	}while(f!=0);
	
	
	
}
