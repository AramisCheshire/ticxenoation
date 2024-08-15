#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PMAX 80
#define PRINTS 0
#define MSG 1000


int notoi(char goo[]);

int maxprime(int *ptr);

int maxdepth(int *primes);

void factorise(int input,int *ptr);

int tex(int numbr,int *pttr);

void makeempty(int *mp);

int is2fac(float number);

void funnyprint(int *p,int *prm);

int earthify(char c[],int *ptr);

int mydigitcheck(char c);

//void memorymanage(int sp);

int main(int argc, char *argv[]){

	if (argc>1){
	
		
		//okay, lets interpret expressions
		//

		char *xepies[MSG];

		char c;
		int u=0;
		int oper=0;
		xepies[0]=&argv[1];
		while ((c=argv[1][u])!='\0'){
			
			if (c=='+'){oper=1;}
			else if (c=='-'){oper=2;}
			else if (c=='*'){oper=3;}
			else if (c=='/'){oper=4;}

			
			if (oper>0){
			

			}

			
			u++;
		}
		


		int primes[PMAX] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409};//80
		int *ptr;
		ptr = &primes[0];
			
		//printf("maximum layering we can do is %d\n", maxdepth(ptr));

		if (mydigitcheck(argv[1][0])){
		
			int unum = notoi(argv[1]);
	
		
			tex(unum,ptr);	
	
	
		}
		else{
		
			char msg[MSG];
			sprintf(msg,"%s",argv[1]);
			int earthnum;
		       	earthnum = earthify(msg,ptr);
			printf("earthnumber is %d\n",earthnum);
		
		}
	
		


	
		
	
	}

	else {
		printf("not enough args entered, bozo!\n");
		return -1;
	}

	return 0;
}



int earthify(char msg[], int *p){

	//a function for turning tec xenotation back to earth digits.
	

	char c;
	int i=0;
	int EarthDigit=1;
	int layer=0;

	int bracs[MSG];
	
	int maxlayer = maxdepth(p);

	int irrelevantshit[MSG];

	int *uline;
	uline = &irrelevantshit[0];
	*uline = 1;
	
	bracs[0]=1;




	while ((c=msg[i])!='\0'){
		
		if (c==':'){
			
			bracs[layer]=bracs[layer]*2;
			EarthDigit = EarthDigit*bracs[layer];
			*uline=(*uline)*2;
		}

		else if (c=='('){
			layer++;
			if (layer>maxlayer){
			
				printf("error! tec-xenotation layering exceeds maximum permitted (%d). Returning -1\n", maxlayer);
				return -1;

			}
			bracs[layer]=1;
			uline++;	
			*uline=1;
		}

		else if (c==')'){
			

			//close brackets, convert *uline into a prime
			//
			if (layer==0){
			
				printf("invalid tec-xenotation entered. Returning -1\n");
				return -1;
			}
			layer=layer-1;
				
			bracs[layer]=bracs[layer]*(*(p+bracs[layer+1]-1));
			
			EarthDigit=EarthDigit*bracs[layer];

			//bracs[0]=bracs[0]*bracs[layer]; //this results in errors when layer goes back to 0


			uline=uline-1;
			//3 is the 2nd prime, but in the array {2,3,} it is the 1st element so must add -1 
			*uline = *(p+*(uline+1)-1); 
			
			
		
		}

		



		i++;	
	
	}


	if (layer!=0){
	
		printf("invalid tec-xenotation entered. Returning -1\n");
		return -1;
	}
	return bracs[0];


}	











int tex(int unum,int *ptr){
	if (unum <=  *(ptr+PMAX-1)){

		factorise(unum,ptr);
	
		putchar('\n');	
		
		return 0;			


	}
	else{
	
		printf("number requested exceeds maximum prime. terminating\n");
		return -1;
	}

}



int mydigitcheck(char c){

	if ((c<=57)&&(c>=48)){
		return 1;
	}
	else {
		return 0;
	}

}


int notoi(char hark[]){
	int  res=0;
	char c;
	int i=0;
	while ((c=hark[i])!='\0'){		
		res = (c-'0')+res*10;
		i++;
	}
	return res;
}




int maxdepth(int *p){

	//check what maximum number of brackets is allowed
	//work through primes
	
	int gag=0;
	int i=0;
	while (gag<*(p+PMAX-1)){
		//printf("the %dth prime is: ",gag);
		gag=*(p+gag); //so gag becomes 2, then we find the 2nd prime, then the 3rd, then the 5th, etc..
		//printf("%d\n",gag);
		i++;
	}
	return (i-1);


}

void makeempty(int *mp){
	int i;
	for (i=0;i<(2*PMAX);i++){
		*mp=0;
		mp++;
	}
}


void funnyprint(int *p,int *prm){
	//this links to the heat map, we want to print 
	//print rows of 100
	//
	//
	char blank[100];
	for (int a=0;a<100;a++){
		blank[a]='0';
	}

	for (int i=0;i<PMAX;i++){
		if (*(p+(2*i))==1){
			if (*(prm+i)<100){
				blank[*(prm+i)]=32;
			}	//(ascii code for space)
			//(*prm+i) probably goes to over 100, overfilling blank[]
			//blank starts at 0, but 
		}
	}
	for (int b=1;b<100;b++){

		putchar(blank[b]);

		

	}
	
	
	
	putchar('\n');


}



int is2fac(float number){
	double w;
	w = log(number)/log(2);
	if (w==round(w)){
		return 1;
	
	}
	else {
		return 0;
	}
	
}





int searchprime(int prime, int *prm){


	int i =0;
	while (i<(PMAX)){
		if (prime!=(*prm)){
			i++;
			prm++;

		}
		else {
		
			return (i+1);

		}
	}

	if (i>=PMAX){
		i=-1;
	}
	return (i+1);


}







void factorise(int unum,int *prm){
		//one number in, result is printouts of many numbers
	int mp[2*PMAX];

	int *map;
	map = &mp[0];


	makeempty(map);
		
		//factorise(unum,mp,ptr);
		//now mp should point to a filled out array
		
		/*for (int i=0;i<2*PMAX;i++){
		
			printf("%d",*(mp+i));
		
		}*/



		//this map, pointed to by mp, needs to be reused by each layer.


		//structure:
		//-factorise first number, into primes.
		//-find out number of those primes.
		//-if its a prime, add (). if its not a prime, factorise it, repeat the whole fnc.
		//stop until you've reached 2s, then print :'s.
	





	//convert numbers to tec-xenononation strings
	//first - factorise input number into primes

	
	//Factors may repeat. how to represent this?
	//could do {2,x,3,x,5,x,7,x}etc...
	//or more likely {1,x,0,x,1,x} etc. to mark if the factor is present or not
	


	/*int map[2*PMAX];
	



	
	//
	printf("just checking that prm is %d and mp is %d\n",prm-firstprm,map-firstmp);
	for (int h=0;h<(2*PMAX);h++){
		map[h]=0;
	}*/
	
	int i=0;
	int pow=0;
	int firstprm=prm;
	int firstmp=map;
	//try keep map always =0



	while (i<PMAX){
	
	//	printf("%d: currently unum is %d and the prime is %d\n",i,unum,(*prm));
		if ((unum!=0)&&((unum%(*prm))==0)){
			//if *prm is a factor of unum
			*(map+(2*i))=1;
			pow++;
			unum=unum/(*prm);

		}
		else{	
			//the prime is not a factor
			*(map+(2*i)+1)=pow;
			pow=0;
			prm++;
			i++;
		}
	}
	int j=0;
	prm=prm-PMAX;
	//
	//printf("just checking that prm is %d, savedprm is %d, mp is %d and saved mp is %d\n",prm,firstprm,map,firstmp);

	
	//this whole block is just for printing
	while ((j<(PMAX-1))&&(PRINTS==1)){
	
		if ((*(map+j*2))==1){
			printf("%d",(*(prm+j)));
			if (*(map+(j*2)+1)>1){
				printf("^%d",*(map+(j*2)+1));
			}
			printf(" is a factor\n");
		}
		
		//printf("%d",*(map+j*2));

		j++;

	}



	//at this point map is filled out with the factors of the number. now ,we can proceed to find the number of the prime.
	//can separate into 2s already at this stage or keep it general.
	//
	//
	int primN;
	int subj;

	for (int yoc=0;yoc<PMAX;yoc++){
		subj= *(map+(yoc*2));
		if (subj==1){





			primN=searchprime(*(prm+yoc),prm);//*prm+yoc is the actual prime
			if (PRINTS==1){
				printf("prime number is: %d\n",primN);
			}
			//okay, now we know the number of each prime. if it is a factor of two, it can be replaced with ::::'s. if it is something else, gotta check if its prime or not. if its prime, add (), if not, factorise it.
			if (is2fac(*(prm+yoc))==1){
				//this branch is if the prime number itself is 2	
				//printf("one of the prime numbers is two\n");
				for (int pwp=0;pwp<*(map+(2*yoc)+1);pwp++){
				
					putchar(':');
				}
			}
			else if (is2fac(primN)==1){
				//this branch is if the prime number's number is a factor of two
				//e.g. 3 is the 2nd number, so it would be picked up here
				//
				for (int pwp=0;pwp<*(map+(2*yoc)+1);pwp++){ //problem with this statement: it adds a : for every prime, but it should be adding (...) instead. the number of :'s inside the bracked should depend on how many 2's the number factorises into.
					putchar('(');
						
						factorise(primN,prm); //this is a bit of an overkill, consider replacing with a log	
					putchar(')');
				}
			}
			else if(0){
			
				//need a test for whether the prime's number is prime.
			}
			
			else{
				for (int pwp=0;pwp<*(map+(2*yoc)+1);pwp++){
					putchar('(');
				
					factorise(primN,prm);
					putchar(')');
				}
			}



			if (PRINTS==1){
				;//printf("%d is the %dth prime\n",*(prm+yoc),primN);//search prime works
			}
		}	
	}

	//funnyprint(map,prm);





}
/* void someshit(){
	 
	//map now contains all of the factors
	//for e.g. 20 it will look like
	//{1,2,0,0,1,1,0...}
	//they are all prime
	//we need to know their number in the prime list 
	//if 2 = print :
	//if 3 = 3 is the 2nd prime number, so print (:)
	//if 5 = 3rd number so print ((:))
	//if 7 - 4th number, 4th isnt prime so call fnc again and print its contents inside brackets ()
	//
	
	int ps=0;
	for (int a=0;a<PMAX;a=a+1){
		

		if (map[2*a]==1){
			//okay, we know all a's are prime, so no need for checking return from sarchprime
			//this for loop goes through the factors, the rest is figuring out how to display them
			//apply searchprime to each factor. if 1--> print a 2. if not 1--> find the prime's number. feed it into search prime again, if its not a prime factorise it and go again, noting down how many times you need to do this, until you reach a factor of 2. 


			for (int u=1;u<=map[(2*a)+1];u++){
				
				printf("%d is the %dth prime\n",*(prm+a),searchprime(*(prm+a),prm)); 
			
			}
		
		
		}

	
	
	}
	
	
		


}
*/
/*
int maxprime(int *ptr){

	int i=0;
	int product=1;
	while (i<3){
	
		product=product*(*ptr);
		ptr++;

		i++;

	}
	printf("ptr is now %d\n",*ptr);
	return product;



////unnecessary function
}
*/

