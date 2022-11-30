#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{
    int bilgi;
    struct node* link;
};
struct node* start = NULL;


void BasinaEkle()
{
    int x;
    struct node* var;
    var = malloc(sizeof(struct node));
    
    
    printf("\nGirilecek Numarayi yaz: ");
    scanf("%d", &x);
    
    
    var->bilgi = x;
    var->link = start;
    start = var;
}


void SonunaEkle()
{
    int x;
    struct node *var, *head;
    var = malloc(sizeof(struct node));
  
  
    printf("\nGirilecek numarayi yaz: ");
    scanf("%d", &x);
  

    var->link = 0;
    var->bilgi = x;
    head = start;
    while (head->link != NULL) 
	{
        head = head->link;
    }
    head->link = var;
}


void OrtayaEkle()
{
    struct node *var, *newnode;
    int yer, x, counter = 1;
    newnode = malloc(sizeof(struct node));
  

    printf("\nIndexi gir:");
    scanf("%d", &yer);
    printf("\nGirilecek numarayi gir:");
    scanf("%d",&x);
    
  

    var = start;
    newnode->bilgi = x;
    newnode->link = 0;
    while (counter < yer - 1) 
	{
        var = var->link;
        counter++;
    }
    newnode->link = var->link;
    var->link = newnode;
}

void Goster()
{
    struct node* var;
  
    if (start == NULL)
	{
		printf("\nListe Bos\n");
	}
        
  
    else 
	{
        var = start;
        while (var != NULL) 
		{
            printf(" %d ", var->bilgi);
            var = var->link;
        }
    }
}

int main()
{
	int secim;
    while (true) 
	{
  
        printf("\n1  Listeyi goruntule:\n");
        printf("2  Listenin basina ekle:\n");
        printf("3  Listenin sonuna ekle:\n");
        printf("4  Listede herhangi bir yere ekle:\n");
        printf("5  Cik:\n");
        printf("Girdi: ");
        scanf("%d", &secim);
  
        if(secim == 1)
		{
        	Goster();
		}
		
		else if(secim == 2)
		{
			BasinaEkle();
		}
		
		else if(secim == 3)
		{
			SonunaEkle();
		}
		
		else if(secim == 4)
		{
			OrtayaEkle();
		}
		
		else if(secim == 5)
		{
			exit(1);
		}
		
		else
		{
			printf("Gecersiz Islem\n");
		}
		
    }
    return 0;
}
