#include <stdio.h>
#include <stdlib.h>
#define max_size_account 30
#define max_size_name 14
#define max_size_fame 18

struct database {
		char name[max_size_name];
		char fame[max_size_fame];
		float balance_1;
		int number;
};



void new_users(char *name, char *name_2, float *balance_1, int *number);
void print_all_users(struct database *account, char *users);
void open_f(FILE *plik, struct database *buf);
void save_f(FILE *plik, struct database *account, char *users);

void main(){
		FILE *plik;
		struct database account[max_size_account];
		struct database buf[max_size_account];
		char question[2];
		char all_users[5];
		int n=0;
//		int all_users=4;

there: 	
		printf("___________________\nWhat do you want to do?\nChoose number or character:\n");
		printf("___________________\n1. Save in file?\n2. Open file?\nY. Add new users?\nN. Print all users?\n");
		scanf("%s", question);
		switch (question[0]){
			
				case 'Y':
						printf("How many users do you want to add?\n");
						scanf("%s", all_users);
						if((atoi(all_users)>0)){
							for(;n<(atoi(all_users));++n){
								new_users(account[n].name, account[n].fame, &(account[n].balance_1), &(account[n].number));
									};

						}else{
							printf("Error! You chose a bad number, try again  ");
							getchar();
							getchar();
						}
						save_f(plik, account, all_users);
						break;
				case 'N': 
						print_all_users(account, all_users);
						break;
				case '1': 
						save_f(plik, account, all_users);
						break;
				case '2':
						open_f(plik, buf);
						break;				
				case '3':
						break;	
		}
goto there; 
}

void new_users(char *name, char *name_2, float *balance_1, int *number){
	
		printf("Name: ");
		scanf("%s", name);
		printf("vorname: ");
		scanf("%s", name_2);
		printf("exp: ");
		scanf("%f", balance_1);
		printf("tel number: ");
		scanf("%d", number);
		printf("_________________\n");
}
void print_all_users(struct database *account, char *users){
		char question[2];
		int n;
		printf("Do you want print all members?  Y/N\n");
		scanf("%s", question);
		if(question[0]=='Y'){
			printf("NAME	| VORNAME	| EXP	| NUMBER\n");
			for(n=0;n<(atoi(users));n++)
				printf("%-5s %-5s %.2f %d\n", (account+n)->name, (account+n)->fame, (account+n)->balance_1, (account+n)->number);}
		else 
			printf("OK\n");
				
}

void open_f(FILE *plik, struct database *buf){ //2
	plik=fopen("data_users.txt", "r");
	int n, m=0;
		while((tex=getc(plik))!=EOF)
			if(tex=='\n')
				++m;
		fseek(plik,0,SEEK_SET);
	//	rewind(plik);
		for(n=0;n<m;++n){
			fscanf(plik, "%s", (buf+n)->name);
			fscanf(plik, "%s", (buf+n)->fame);
			fscanf(plik, "%f", &((buf+n)->balance_1));
			fscanf(plik, "%d", &((buf+n)->number));
			printf("%s %s %.2f %d\n", (buf+n)->name, (buf+n)->fame, (buf+n)->balance_1, (buf+n)->number);
		};
	fclose(plik);
}
void save_f(FILE *plik, struct database *account, char *users){
		plik=fopen("data_users.txt", "a");
		int n;
		if(plik==NULL)
				exit(0);	
		for(n=0;n<atoi(users);n++)
				fprintf(plik, "%s %s %f %d\n", (account+n)->name, (account+n)->fame, (account+n)->balance_1, (account+n)->number);
		fclose(plik);
}
	
