#include <stdio.h>
#include <stdlib.h>

///Parte do deque(Pessoa)
typedef struct Pessoa{
  char *email;
  char *nome;
  int numero;
  int id;
  struct Pessoa* proximo;
  struct Pessoa* anterior;
	struct Stack* stack;
}Pessoa;

///Parte do deque(O dito cujo)

typedef struct{
  	Pessoa* cabeca;
    Pessoa* cauda;
} Deque;


//Backup 
typedef struct Backup{
 struct Backup* anterior; //ponteiro para o nó anterior
 struct Pessoa* pessoa; //valor do nó
} Backup;


///Stack
typedef struct Stack{
	Pessoa* cabeca;
}Stack;


void lixo(void) {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}



void limpar(void)
{
    #ifdef __linux__
        system("clear");

    #elif _WIN32
        system("cls");
    #else

    #endif
}

Deque* criar() {
    Deque* deque = malloc(sizeof(Deque));
    deque->cabeca = NULL;
    deque->cauda = NULL;

    return deque;
}

Stack* criarS(){
	Stack* stack = malloc(sizeof(Stack));
  stack->cabeca = NULL;


  return stack;
	
}

int vazia(Deque* deque) {
    return deque->cabeca == NULL && deque->cauda == NULL;
}

void adicionar(Deque* deque, char *email, int numero, char *nome, int id) 
{
    Pessoa* pessoa = malloc(sizeof(Pessoa));
    pessoa->nome =  malloc(strlen(nome)+1);
		strcpy(pessoa->nome, nome);
    pessoa->email = malloc(strlen(email)+1);
		strcpy(pessoa->email, email);
    pessoa->id = id;
		pessoa->numero = numero;
	

    pessoa->proximo = NULL;
    pessoa->anterior = (struct Pessoa*) deque->cauda;

    if (vazia(deque)) {
        deque->cabeca = pessoa;
    } else {        
        deque->cauda->proximo = (struct Pessoa*) pessoa;
    }

    deque->cauda = pessoa;
}


void percorrer(Deque* deque)
{
	Pessoa* pessoa = deque->cabeca;
	printf("######### Contatos ############");
	
	while(pessoa != NULL)
		{	
			printf("\n");
			printf("ID#%d", pessoa->id);
			printf("\n");
			printf("Nome: %s", pessoa->nome);
			printf("\n");
			printf("Email: %s", pessoa->email);
			printf("\n");
			printf("Numero: %d", pessoa->numero);
			printf("\n");
			pessoa = (Pessoa*) pessoa->proximo;
			printf("\n");
			
		}
	printf("\n");
	printf("######### Opcoes ############");
	
	
}


void remover(Deque* deque, int id)
{	
	
	Pessoa* pessoa = deque->cabeca;
	

	Pessoa*  remove = NULL;
	if(deque->cabeca != NULL && deque->cabeca->id == id)
	{
		remove = deque->cabeca;
		deque->cabeca = (Pessoa *)deque->cabeca->proximo;
	}
		else
		{
			while(pessoa != NULL && pessoa->proximo !=NULL && pessoa->proximo->id == id)
			{
				remove = pessoa->proximo;
				pessoa->proximo =remove->proximo;
			}
		}
		if(remove)
		{
			free(remove);
		}
	printf("\n");
	
}



Pessoa* capturar(Deque* deque, int id)
{	
	int num;
	Pessoa* aux;
	

	aux = deque->cabeca;
	while(aux && aux->id != id)
	{
		aux = aux->proximo;
	}
	if(aux)
	{
		return(aux);
	}
	else
	return (aux);
}

void backup(Deque* deque, Pessoa* pessoa)
{
	if (pessoa->stack != NULL)
	{	
		Backup* beckup = malloc(sizeof(Backup));
		pessoa->stack->cabeca->email = pessoa->email;
		pessoa->stack->cabeca->nome	= pessoa->nome;
		pessoa->stack->cabeca->numero	= pessoa->numero;
		
	}
	else
	{
		Stack* stack = criarS();
		
		
	}
}

void editar(Deque* deque, Pessoa* pessoa)
{
	int num;
	printf("Deseja mudra qual dado?\n1. Nome\n2.Email\n3.Numero\n");
	scanf("%d",&num);
	lixo();
	switch(num)
      {
      	case 1 :
					printf("Nome: ");
					scanf("%[^\n]c", pessoa->nome);
					lixo();
					printf("\n");
        break;

        case 2 :
					printf("Email: ");
					scanf("%[^\n]c", pessoa->email);
					lixo();
					printf("\n");

        break;  

				case 3 :
					printf("numero: ");
					scanf("%d\n", &pessoa->numero);
					lixo();
					printf("\n");
        break;

				default :
          printf("Funcionalidade inexistente, tente novamente.\n");
        break;
		}

}


int main() {
				char email[100], nome[100];
				int numero, id= 0, menu, num;

				Deque* deque = criar();
		    while(1)
    {		

        printf("\n");
				printf("1. Buscar pessoas por nome\n");
        printf("2. Buscar aniversariantes do mes\n");
        printf("3. Buscar aniversariantes do dia\n");
        printf("4. Adicionar registro de pessoa\n");
        printf("5. Remover registro de pessoa\n");
        printf("6. Imprimir todos os registros\n");
        printf("0. Encerrar programa\n");
        printf("\n");
        printf("Escolha uma funcionalidade: ");
        scanf("%d", &menu);
				limpar();
        lixo();
        printf("\n");
			
			if(menu == 1)
			{
				id ++;
			}

        switch(menu)
        {
            case 0 :
                printf("Encerrando o programa.");
                return 0;
            break;

            case 1 :
								limpar();
								printf("Nome: ");
								scanf("%[^\n]c", nome);
							  lixo();
							
								printf("Email: ");
								scanf("%[^\n]c", email);
								lixo();

								printf("numero: ");
								scanf("%d\n", &numero);
								lixo();
								
								
                adicionar(deque, email, numero, nome, id);
								limpar();
					
            break;  

					  case 2 :
                percorrer(deque);

            break; 

						case 3 :
								limpar();
								printf("\nQual id deseja excluir? ");
								scanf("%d", &num);
								lixo();
                remover(deque, num);
            break; 
            
						case 4 :
								limpar();
								printf("\nQual id deseja editar? ");
								scanf("%d", &num);
								lixo();
                editar(deque, capturar(deque, num));
            break;          
					
            default :
								limpar();
                printf("Funcionalidade inexistente, tente novamente.\n");
            break;
            
        }

		}

	}
