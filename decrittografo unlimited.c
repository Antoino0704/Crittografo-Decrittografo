/*Antonino Buscarino*/
#include <stdio.h>		//richiama libreria standard di input-output		
#include <stdlib.h>		//richiama libreria standard
#include <string.h>		//richiama libreria stringhe
#include <windows.h>	//richiama libreria windows
main()				//definisci funzione main
{
	char uscita;			//dichiara variabile uscita di tipo cararttere
	int veram=0;			//dichiara variabile veram di tipo intero
	do{
	char frase[100000];			//dichiara variabile frase di tipo array
	int key;				//dichiara variabile key di tipo intero
	int i, salto=0;			//dichiara variabili i e salto di tipo intero
	printf("inserisci frase da decifrare: ");			//stampa a schermo c'ho che c'è tra parentesi
	gets(frase);			//la variabile frase assume valore da tastiera
	do {
	printf("\n\ninserisci chiave di decifratura: ");		//stampa a schermo c'ho che c'è tra parentesi
	scanf("%d", &key);		//la variabile key assume valore da tastiera
	getchar();			//la funzione getchar blocca schermata dos
	}
	while(key<1 || key>100000);			//mentre il valore della variabile key è compreso tra 1 e 100000
	if (key==71004)
	{
		if (veram==0)				//se la variabile veram è 0 quindi chiave amministratore non attivata precedentemente
		{
		  system("color 9C");			//cambia sfondo e colore caratteri
		  printf("\nCHIAVE AMMINISTRATORE ATTIVA\n");			//stampa a schermo c'ho che c'è tra parentesi
		  MessageBox(0, "HAI ATTIVATO LA CHIAVE AMMINISTRATORE", "CHIAVE AMMINISTRATORE ATTIVA", MB_OK | MB_ICONWARNING);		//crea interfaccia di attivazione	
		  veram=1;				//la variabile veram assume valore 1 indicando che la chiave amministratore è stata attiva almeno una volta
		}
		else if(veram==1)				//se la variabile veram è 1 quindi chiave amministratore è stata attivata precedentemente
		{
			printf("\nCHIAVE AMMINISTRATORE ATTIVATA PRECEDENTEMENTE\n");			//stampa a schermo c'ho che c'è tra parentesi
		}
	}
	if(veram==1 && key!=71004)				//se la variabile veram è 1 e la variabile key non è 71004 quindi chiave amministratore è stata attivata almeno una volta ma ora è stata disattivata
	{
		system("color F");				//il colore dello sfondo e caratteri torna di default
		printf("\nCHIAVE AMMINISTRATORE DISATTIVATA\n");			//stampa a schermo c'ho che c'è tra parentesi
		veram=0;						//la variabile veram assume valore 0 è torna di default
	}
	printf("\n\n-------------------------------\nfrase decrittografata:\n");		//stampa a schermo c'ho che c'è tra parentesi
	for(i=0; i<strlen(frase); i++, salto=0)
	{
		if(frase[i]<32+key)			//se il valore  della variabile frase è maggiore dal risultato dell'operazione 126-key
		{
			salto=95;					//la variabile salto assume valore 95
		}
		printf("%c", frase[i]-key+salto);			//stampa a schermo la frase crittografata
	}
	printf("\n\nvuoi criptare altri messaggi?  si=y no=n\n");				//stampa a schermo c'ho che c'è tra parentesi
	scanf("%c", &uscita);					//la variabile uscita assume valore da tastiera
	printf("\n\n\nProgramma offerto da Antonino Buscarino :)\n\n\n");			//stampa a schermo c'ho che c'è tra parentesi
	getchar();				//la funzione getchar blocca schermata dos
	}
	while(uscita=='y');			//mentre uscita=y allora ripeti
}
