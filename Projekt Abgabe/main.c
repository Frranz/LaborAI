#include "header.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int input;
	int runLoop = 1;
	
	while(runLoop){
		printf("=====================\n");
		printf("Willkommen in Shop\n");
		printf("Bitte wählen sie eine Option aus\n");
		printf("[1] Shop als Verkäufer\n");
		printf("[2] Shop als Käufer\n");
		printf("[3] Shop verlasesn\n");
		scanf("%1d",&input);
		fflush(stdin);
		
		if(input==1){
			shopVerkaufer();
		}else if(input==2){
			shopKaufer();
		}else if(input==3){
			printf("Shop wird verlassen\n");
			runLoop = 0;
		}else{
			printf("ungueltige Eingabe\n");
		}
		
	}
	
	return 0;
}

void shopVerkaufer(){
	int input;
	int runLoop = 1;
	
	while(runLoop){
		printf("=====================\n");
		printf("Wählen sie eine Option aus\n");
		printf("[1] Prdukt hinzufügen\n");
		printf("[2] Produket bearbeiten\n");
		printf("[3] Produket entfernen\n");
		printf("[4] Verkäuferseite verlassen\n");
		scanf("%1d",&input);
		fflush(stdin);
		
		switch(input){
			case 1:
				menuProduktHinzufuegen();
				break;
			case 3:
				artikelLoschen();
				break;
			case 4:
				printf("Verkaeuferseite wird verlassen\n");
				runLoop = 0;
				break;
			default:
				printf("ungueltige Eingabe\n");
		}
	}
}

void shopKaufer(){
	int input;
	int runLoop = 1;
	
	while(runLoop){
		printf("=====================\n");
		printf("Willkommen im Kaufershop\n");
		printf("[1] Katalog\n");
		printf("[2] Artikel suchen\n");
		printf("[3] Warenkorb anzeigen\n");
		printf("[4] Warenkorb leeren\n");
		printf("[5] Kaufershop verlassen\n");
		scanf("%d",&input);
		fflush(stdin);
		printf("\n");
		
		switch(input){
			case 1:
				kauferKatalog();
				break;
			case 2:
				artikelSuchen();
				break;
			case 3:
				warenkorbAnzeigen();
				break;
			case 4:
				warenkorbLeeren();
				break;
			case 5:
				runLoop = 0;
				break;
			default:
				printf("ungultige Eingabe\n");
		}
	}
}

void menuProduktHinzufuegen(){
	char eingabe[20+1];
	char datensatz[63+1];
	strcpy(datensatz,"                                                            ");
	srand(time(NULL));
	unsigned int artikelNummer = 10000+(rand()%900000);
	sprintf(datensatz,"%6d",artikelNummer);
	datensatz[6] = ' ';
	
	printf("Artikelbezeichnung:\n");
	scanf("%20s",eingabe);
	fflush(stdin);
	
	if(1){//alreadyExists(eingabe)){
		sprintf(datensatz+7,"%-20s",eingabe);
		datensatz[27] = ' ';
		
		printf("Preis:\n");
		scanf("%10s",eingabe);
		fflush(stdin);
		
		sprintf(datensatz+28,"%10s",eingabe);
		datensatz[38] = ' ';
		sprintf(datensatz+39,"Euro",eingabe);
		datensatz[43] = ' ';
		
		printf("Bestand:\n");
		scanf("%10s",eingabe);
		fflush(stdin);
		
		sprintf(datensatz+50,"%-10s",eingabe);
		datensatz[60] = '\n';		
		datensatz[61] = '\0';		
		printf("hier ist der Datensatz:%s\n",datensatz);
		
		FILE *file = fopen("daten.txt","a");
		if(file){
			fprintf(file,datensatz);
			fclose(file);
		}else{
			printf("Error, konnte daten.txt nicht öffnen\n");
		}
				
	}else{
		printf("Artikelbezeichnung existiert bereits: Bitte versuchen sie es erneut\n");
	}	
}

void menuProduktEntfernen(){
	
}

void dateiLesen(char* dateiName, int showIndex){
	int counter = 0;
	char buffer[80+1];
	FILE *file = fopen(dateiName,"r");
	if(file){
		fgets(buffer,80,file);
		while(!feof(file)){
			if(showIndex){
				printf("(%2d)  ",counter);
			}
			
			printf("%s",buffer);
			fgets(buffer,80,file);
			counter++;
		}
		fclose(file);
	}else{
		printf("Datei konnte nicht eingelesen werden\n");
	}
}

void kauferKatalog(){
	int eingabe;
	char line[100+1];
	int counter = 0;
	int zeileGefunden = 0;
	printf("=======================\n");
	printf("Willkommen im Katalog");
	printf("folgende Produkte sind vorhanden:\n");
	
	
	dateiLesen("daten.txt",1);
	
	printf("Wahlen Sie ein Produkt aus:\n");
	scanf("%3d",&eingabe);
	fflush(stdin);
	
	int buffer[100+1];
	FILE *file = fopen("daten.txt","r");
	if(file){
		fgets(buffer,80,file);
		while(!feof(file)){
			if(counter==eingabe){
				zeileGefunden = 1;
				break;
			}
			counter++;
			fgets(buffer,80,file);
		}
	}else{
		printf("Datei konnte nicht eingelesen werden\n");
	}
	
	if(zeileGefunden){
		FILE *file = fopen("warenkorb.txt","a");
		if(file){
			fprintf(file,buffer);
			fclose(file);
		}else{
			printf("Datei konnte nicht eingelesen werden\n");
		}
	}else{
		printf("der aufgewahlte Artikel wurde nicht gefunden\n");
	}
	
}

void warenkorbLeeren(){
	FILE *file = fopen("warenkorb.txt","w");
	fprintf(file,"");
	fclose(file);
}

void warenkorbAnzeigen(){
	dateiLesen("warenkorb.txt",1);
}

void artikelSuchen(){
	char save;
	int artikelNameLength;
	int artikelGefunden = 0;
	int inWarenkorbLegen;
	char buffer[100+1];
	char artikelName[30+1];
	
	printf("Nach welchem Artikel soll gesucht werden?\n");
	scanf("%30s",artikelName);
	
	FILE *file = fopen("daten.txt","r");
	if(file){
		fgets(buffer,100,file);
		
		while(!feof(file)){
			
			artikelNameLength = strlen(artikelName);
			save = buffer[7+artikelNameLength];
			buffer[7+artikelNameLength] = 0;
			
			if(strcmp(artikelName,buffer+7)==0){
				artikelGefunden = 1;
				printf("folgender Artikel wurde gefunden:\n");
				printf("%s",buffer);
				buffer[7+artikelNameLength] = save;
				break;
			}
			buffer[7+artikelNameLength] = save;
			fgets(buffer,100,file);
		}
		fclose(file);
		
		if(artikelGefunden){
					
			printf("\n Soll der Artikel in der Warenkorb gelegt werden?\n");
			printf("[1] ja\n");
			printf("[2] nein\n");
			
			scanf("%d",&inWarenkorbLegen);
			fflush(stdin);
			
			if(inWarenkorbLegen==1){
				FILE *file = fopen("warenkorb.txt","a");
				if(file){
					fprintf(file,buffer);
					fclose(file);
				}else{
					printf("Datei konnte nicht eingelesen werden\n");
				}
			}
		}else{
			printf("Artikel konnte nicht gefunden werden\n");
		}


	}else{
		printf("Error, konnte daten.txt nicht öffnen\n");
	}
}

void artikelLoschen(){
	int eingabe;
	int counter = 0;
	char buffer[100+1];
	
	dateiLesen("daten.txt",1);
	
	printf("Welcher Artikel soll gelöscht werden?\n");
	scanf("%d",&eingabe);
	fflush(stdin);	
	
	FILE *file = fopen("daten.txt","r");
	FILE *temp = fopen("temp.txt","w");
	fclose(temp);
	
	temp = fopen("temp.txt","a+");
	
	fgets(buffer,100,file);
	while(!feof(file)){
		printf("write in temp\n");
		if(eingabe!=counter){
			fprintf(temp,"%s",buffer);
		}
		fgets(buffer,100,file);
		counter++;
	}
	
	fseek(temp, 0, SEEK_SET);
	file = fopen("daten.txt","w");
	fclose(file);
	file = fopen("daten.txt","a");
	if(file){
		fgets(buffer,100,temp);
		while(!feof(temp)){
			fprintf(file,"%s",buffer);
			fgets(buffer,100,temp);
		}
		fclose(file);
	}
}
