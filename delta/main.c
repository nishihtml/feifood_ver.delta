#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"



void main (){
	FILE *cadastro;
	FILE *login;
	FILE *registro;
	FILE *historico;
	char linha[255];
	
	char x[255] = "x";
	char string_2[255] = "";//prato
	char string_3[255];//quantidade
	char string_4[255] = "";//valor
	char string_5[255];//valor total
	float valor_total_1 = 0;
	float valor_total_2 = 0;
	float valor_total_3 = 0;
	
	char dest[255];
	
	char comprovante_final[3][255] = {"", "", ""};
	
	char pedido_de[255] = "Pedido de ";
	
	int restaurante;
	int prato;
	int quantidade;
	int pagamento;
	int avaliacao = 0;
	
	int i;
	
	int checkout_check = 0;
	
	int reply;
	int check = 0;
	int usuario_check = 0;
	int senha_check = 0;
	
	char cadastro_senha[3] = " : ";
	
	char usuario[255];
	char senha[255];
	
	float valor_final = 0;
	
	sleep(1);
	printf(RED "====================" RESET "\n");
	printf(RED " __ __    _         " RESET "\n");
	printf(RED "|_ |_  | (_ _  _  _|" RESET "\n");
	printf(RED "|  |__ | | (_)(_)(_|" RESET "\n");
	printf(RED "====================" RESET "\n");
	sleep(3);
	system("CLS");
	
	do{
		do{
			printf("============ \n");
			printf(YELLOW "[1]" RESET "Cadastrar \n");
			printf(YELLOW "[2]" RESET "Logar \n");
			printf("============ \n \n");
			printf("RESPOSTA: ");
			scanf("%d", &reply, "\n");
			system("CLS");
		}while(!(reply >= 1 && reply <= 2));
		switch(reply){
			case 1:
				cadastro = fopen("arquivo.txt", "a");
				printf("Usuario: ");
				scanf("%s", &usuario, "\n");
				printf("Senha: ");
				scanf("%s", &senha, "\n");
				fprintf(cadastro, "%s \n", usuario);
				fprintf(cadastro, "%s \n", senha);
				system("CLS");
				fclose(cadastro);
				break;
			case 2:
				login = fopen("arquivo.txt", "r");
				printf("Usuario: ");
				scanf("%s", &usuario, "\n");
				printf("Senha: ");
				scanf("%s", &senha, "\n");
				while (!feof(login)){
 					fscanf(login, "%s", linha);
 					if(strcmp(linha, usuario) == 0){
 						usuario_check = 1;
					}
					if(strcmp(linha, senha) == 0){
 						senha_check = 1;
					}
				}
				if(usuario_check == 1 && senha_check == 1){
					check = 1;
				}
				usuario_check = 0;
		        senha_check = 0;
				system("CLS");
				break;
				rewind(login);
				fclose(login);
			
		}
	}while(check == 0);
	
	printf(YELLOW "Ola %s \n" RESET, usuario);
	sleep(3);
	system("CLS");
	strcat(pedido_de, usuario);
	
	do{
		do{
			printf("=============== \n");
			printf(YELLOW"[1]"RESET"Fazer pedido \n");
			printf(YELLOW"[2]"RESET"Historico \n");
			printf("=============== \n \n");
			printf("RESPOSTA: ");
			scanf("%d", &reply, "\n");
			system("CLS");
		}while(!(reply >= 1 && reply <= 2));
		if(reply == 1){
			do{
                printf("======Restaurantes====== \n");
				printf(YELLOW"[1]"RESET"Frango Atropelado \n");
				printf(YELLOW"[2]"RESET"Burger King \n");
				printf(YELLOW"[3]"RESET"Hachi Crepe & Taiyaki \n");
				printf(RED"[4]"RESET"Sair \n");
				printf("======================== \n");
				printf("RESPOSTA: ");
				scanf("%d", &reply, "\n");
				system("CLS");
			}while(!(reply >= 1 && reply <= 4));
			switch(reply){
				case 1:
					do{
						restaurante = 1;
						printf("Frango Atropelado \n");
						printf("================================= \n");
						printf(YELLOW"[1]"RESET"Parmediana de Frango : R$19.99 \n");
						printf("Uma marmita que contem arroz, feijao, batata frita, farofa e parmediana de frango \n \n");
						printf(YELLOW"[2]"RESET"Macarrao Italiano    : R$16.99 \n");
						printf("Uma marmita que contem macarrao ao molho de tomate \n \n");
						printf(YELLOW"[3]"RESET"Salada               : R$ 7.99 \n");
						printf("Uma pequena porcao de salada com tomate \n \n");
						printf(YELLOW"[4]"RESET"Sair \n");
						printf("================================= \n \n");
						printf("RESPOSTA: ");
						scanf("%d", &prato, "\n \n");
						if(prato >= 1 && prato <= 3){
							printf("Quantos?(de 0 ate 9) \n");
							printf("RESPOSTA: ");
							scanf("%d", &quantidade, "\n \n");
							if(!(quantidade >= 0 && quantidade <= 9)){
								printf("Quantidade excedida/negativa \n");
								sleep(5);
								quantidade == 0;
								for (i = 0; i <= 255; i++) {
									string_2[i] = '\0';
									string_4[i] = '\0';
									comprovante_final[prato][i] = '\0';
								}
								switch(prato){
									case 1:
										valor_total_1 = 0;
										break;
									case 2:
										valor_total_2 = 0;
										break;
									case 3:
										valor_total_3 = 0;
										break;	
								}
							}else{
								switch(prato){
									case 1:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[1][i] = '\0';
											}
											valor_total_1 = 0;
										}else{
											strcat(string_2, "Parmediana de Frango ");
											sprintf(string_3, "%d", quantidade);
											strcat(string_4, "19.99: ");
											valor_total_1 = quantidade * 19.99;
											sprintf(string_5, "%.2f", valor_total_1);
											//strcat(string_2, espaco, string_3, x, string_4, espaco, string_5);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcat(comprovante_final[1], string_2);
										}
										break;
									case 2:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[2][i] = '\0';
											}
											valor_total_2 = 0;
										}else{
											strcpy(string_2, "Macarro Italiano ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "16.99: ");
											valor_total_2 = quantidade * 16.99;
											sprintf(string_5, "%.2f", valor_total_2);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[2], string_2);
										}
										break;
									case 3:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[3][i] = '\0';
											}
											valor_total_3 = 0;
										}else{
											strcpy(string_2, "Salada ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "7.99: ");
											valor_total_3 = quantidade * 7.99;
											sprintf(string_5, "%.2f", valor_total_3);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[3], string_2);
										}
										break;
									default:
										break;    			
								}
							}
						}
						system("CLS");
					}while(!(prato == 4));
					break;
				case 2:
					do{
						restaurante = 2;
						printf("Burger King \n");
						printf("==========================\n");
						printf(YELLOW"[1]"RESET"Combo Whopper : R$25.99 \n");
						printf("Um hamburger acompanhado com batata frita \n \n");
						printf(YELLOW"[2]"RESET"Batata Frita  : R$10.99 \n");
						printf("Uma porcao de batata frita \n \n");
						printf(YELLOW"[3]"RESET"Onion Ring    : R$ 9.99 \n");
						printf("Uma porcao de aneis de cebola frita \n \n");
						printf(RED"[4]"RESET"Sair \n");
						printf("========================== \n \n");
						printf("RESPOSTA: ");
						scanf("%d", &prato, "\n");
						system("CLS");
				    	if(prato >= 1 && prato <= 3){
							printf("Quantos?(de 0 ate 9) \n");
							printf("RESPOSTA: ");
							scanf("%d", &quantidade, "\n \n");
							if(!(quantidade >= 0 && quantidade <= 9)){
								printf("Quantidade excedida/negativa \n");
								sleep(5);
								quantidade == 0;
							}else{
								switch(prato){
									case 1:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[1][i] = '\0';
											}
											valor_total_1 = 0;
										}else{
											strcat(string_2, "Combo Whopper ");
											sprintf(string_3, "%d", quantidade);
											strcat(string_4, "25.99: ");
											valor_total_1 = quantidade * 25.99;
											sprintf(string_5, "%.2f", valor_total_1);
											//strcat(string_2, espaco, string_3, x, string_4, espaco, string_5);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcat(comprovante_final[1], string_2);
										}
										break;
									case 2:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[2][i] = '\0';
											}
											valor_total_2 = 0;
										}else{
											strcpy(string_2, "Batata Frita ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "10.99: ");
											valor_total_2 = quantidade * 10.99;
											sprintf(string_5, "%.2f", valor_total_2);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[2], string_2);
										}
										break;
									case 3:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[3][i] = '\0';
											}
											valor_total_3 = 0;
										}else{
											strcpy(string_2, "Onion Ring ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "9.99: ");
											valor_total_3 = quantidade * 9.99;
											sprintf(string_5, "%.2f", valor_total_3);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[3], string_2);
										}
										break;
									default:
										break;    			
								}
							}
						}
						system("CLS");
					}while(!(prato == 4));
				    break;
				case 3:
					do{
						restaurante = 3;
						printf("Hachi Crepe & Taiyaki \n");
						printf("============================= \n");
						printf(YELLOW"[1]"RESET"Crepe de Morango : R$15.99 \n");
						printf("Um doce feito de morango, banana, cobertura de chocolate e sorvete de morango enrolado em uma massa \n \n");
						printf(YELLOW"[2]"RESET"Crepe de Matcha  : R$15.99 \n");
						printf("Um doce feito de morango, banana, cobertura de chocolate e sorvete de matcha enrolado em uma massa \n \n");
						printf(YELLOW"[3]"RESET"Taiyaki          : R$ 9.99 \n");
						printf("Um doce feito de sorvete e chocolate em formato de um peixe \n \n");
						printf(RED"[4]"RESET"Sair \n");
						printf("============================= \n \n");
						printf("RESPOSTA: ");
						scanf("%d", &prato, "\n");
						system("CLS");	  
						if(prato >= 1 && prato <= 3){
							printf("Quantos?(de 0 ate 9) \n");
							printf("RESPOSTA: ");
							scanf("%d", &quantidade, "\n \n");
							if(!(quantidade >= 0 && quantidade <= 9)){
								printf("Quantidade excedida/negativa \n");
								sleep(5);
								quantidade == 0;
							}else{
								switch(prato){
									case 1:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[1][i] = '\0';
											}
											valor_total_1 = 0;
										}else{
											strcat(string_2, "Crepe de Morango ");
											sprintf(string_3, "%d", quantidade);
											strcat(string_4, "15.99: ");
											valor_total_1 = quantidade * 15.99;
											sprintf(string_5, "%.2f", valor_total_1);
											//strcat(string_2, espaco, string_3, x, string_4, espaco, string_5);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcat(comprovante_final[1], string_2);
										}
										break;
									case 2:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[2][i] = '\0';
											}
											valor_total_2 = 0;
										}else{
											strcpy(string_2, "Crepe de Matcha ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "15.99: ");
											valor_total_2 = quantidade * 15.99;
											sprintf(string_5, "%.2f", valor_total_2);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[2], string_2);
										}
										break;
									case 3:
										if(quantidade == 0){
											for (i = 0; i <= 255; i++) {
												string_2[i] = '\0';
												string_4[i] = '\0';
												comprovante_final[3][i] = '\0';
											}
											strcpy(comprovante_final[3], "");
											valor_total_3 = 0;
										}else{
											strcpy(string_2, "Taiyaki ");
											sprintf(string_3, "%d", quantidade);
											strcpy(string_4, "9.99: ");
											valor_total_3 = quantidade * 9.99;
											sprintf(string_5, "%.2f", valor_total_3);
											strcat(string_4, string_5);
											strcat(x, string_4);
											strcat(string_3, x);
											strcat(string_2, string_3);
											strcpy(comprovante_final[3], string_2);
										}
										break;
									default:
										break;    			
								}
							}
						}
						system("CLS"); 
					}while(!(prato == 4));
					break;
			}
			if(!(strcmp(comprovante_final[1], "") == 0 && strcmp(comprovante_final[2], "") == 0 && strcmp(comprovante_final[3], "") == 0)){
				valor_final = valor_total_1 + valor_total_2 + valor_total_3;
				do{
					printf("Valor total: %.2f \n", valor_final);
					printf("Gostaria de finalizar o pedido? \n");
					printf(GREEN"[1]"RESET"Sim \n");
					printf(RED"[2]"RESET"Nao \n");
					printf("RESPOSTA: ");
				    scanf("%d", &reply, "\n");
				}while(!(reply >= 1 && reply <= 2));
				if(reply == 1){
					
					do{
						printf("Selecione o metodo de pagamento \n");
						printf(YELLOW"[1]"RESET"Debito \n");
						printf(YELLOW"[2]"RESET"Credito \n");
						printf(YELLOW"[3]"RESET"Dinheiro \n");
						printf(YELLOW"[4]"RESET"PIX \n");
						printf("RESPOSTA: ");
					    scanf("%d", &pagamento, "\n");
					    system("CLS");
					}while(!(pagamento >= 0 && pagamento <= 5));
					
					registro = fopen("arquivo.txt", "a");
					fprintf(registro, "Pedido de %s \n", usuario);
					switch(restaurante){
						case 1:
							fprintf(registro, "Frango Atropelado \n");
							break;
						case 2:
							fprintf(registro, "Burger King \n");
							break;
						case 3:
							fprintf(registro, "Hachi Crepe & Taiyaki \n");
							break;
						default:
						    fprintf(registro, "NULL");
							break;			
					}
					fprintf(registro, "%s \n", comprovante_final[1]);
					fprintf(registro, "%s \n", comprovante_final[2]);
					fprintf(registro, "%s \n", comprovante_final[3]);
					fprintf(registro, "Total: %.2f \n", valor_final);
					switch(pagamento){
						case 1:
							fprintf(registro, "Pagamento: Debito \n");
							break;
						case 2:
							fprintf(registro, "Pagamento: Credito \n");
							break;
						case 3:
							fprintf(registro, "Pagamento: Dinheiro \n");
							break;
						case 4:
							fprintf(registro, "Pagamento: PIX \n");
							break;
						default:
						    fprintf(registro, "Pagamento: NULL \n");
							break;			
					}
					switch(avaliacao){
						case 1:
							fprintf(registro, "Avaliacao: 1 estrela \n");
							break;
						case 2:
							fprintf(registro, "Avaliacao: 2 estrelas \n");
							break;
						case 3:
							fprintf(registro, "Avaliacao: 3 estrelas \n");
							break;
						case 4:
							fprintf(registro, "Avaliacao: 4 estrelas \n");
							break;
						case 5:
							fprintf(registro, "Avaliacao: 5 estrelas \n");
							break;
						default:
						    fprintf(registro, "Avaliacao: NULL \n");
							break;						
					}
					fclose(registro);
					
					printf("Pedido enviado \n");
					sleep(4);
					system("CLS");
					printf("Preparando pedido... \n");
					sleep(4);
					system("CLS");
					printf("Pedido a caminho... \n");
					sleep(4);
					system("CLS");
					printf(GREEN"Seu pedido chegou!! \n" RESET);	
					sleep(4);
					system("CLS");
					do{
						printf("Avalie o seu pedido \n");
						printf(YELLOW"[1]"RESET"1 estrela \n");
						printf(YELLOW"[2]"RESET"2 estrelas \n");
						printf(YELLOW"[3]"RESET"3 estrelas \n");
						printf(YELLOW"[4]"RESET"4 estrelas \n");
						printf(YELLOW"[5]"RESET"5 estrelas \n");
						printf("[0]Nao avaliar \n");
						printf("RESPOSTA: ");
					    scanf("%d", &avaliacao, "\n");
					    system("CLS");
					}while(!(avaliacao >= 0 && avaliacao <= 5));
					
					sleep(1);
					switch(restaurante){
						case 1:
							printf("Frango Atropelado \n");
							break;
						case 2:
							printf("Burger King \n");
							break;
						case 3:
							printf("Hachi Crepe & Taiyaki \n");
							break;
						default:
						    printf("NULL");
							break;			
					}
					printf("%s \n", comprovante_final[1]);
					printf("%s \n", comprovante_final[2]);
					printf("%s \n", comprovante_final[3]);
					printf("Total: %.2f \n", valor_final);
					switch(pagamento){
						case 1:
							printf("Pagamento: Debito \n");
							break;
						case 2:
							printf("Pagamento: Credito \n");
							break;
						case 3:
							printf("Pagamento: Dinheiro \n");
							break;
						case 4:
							printf("Pagamento: PIX \n");
							break;
						default:
						    printf("Pagamento: NULL \n");
							break;			
					}
					switch(avaliacao){
						case 1:
							printf("Avaliacao: 1 estrela \n");
							break;
						case 2:
							printf("Avaliacao: 2 estrelas \n");
							break;
						case 3:
							printf("Avaliacao: 3 estrelas \n");
							break;
						case 4:
							printf("Avaliacao: 4 estrelas \n");
							break;
						case 5:
							printf("Avaliacao: 5 estrelas \n");
							break;
						default:
						    printf("Avaliacao: NULL \n");
							break;						
					}
					system("pause");
				}
				avaliacao = 0;
				valor_total_1 = 0;
				valor_total_2 = 0;
				valor_total_3 = 0;
				for (i = 0; i <= 255; i++) {
					string_2[i] = '\0';
					string_4[i] = '\0';
					comprovante_final[1][i] = '\0';
					comprovante_final[2][i] = '\0';
					comprovante_final[3][i] = '\0';
				}
				system("CLS");
			}
		}else if(reply == 2){
			historico = fopen("arquivo.txt", "r");
			while (!(feof(historico))){
 				fscanf(historico, "%s", linha);
				if(strcmp(pedido_de, linha) == 0){
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					fscanf(historico, "%s", &linha);
					printf("%s \n", linha);
					printf("\n");
				}	
			}
			system("pause");
			rewind(historico);
			fclose(historico);
			system("CLS");
		}
	}while(check == 1);
	
	system("pause");
}

