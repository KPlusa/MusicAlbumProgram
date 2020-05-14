#include "structures.h"






/**
*   Funkcja dodaje elementy do albumu
*   \param[in,out] Music_album_type **head wskaznik struktury
*   \param[in,out] char *artist wskaznik zmiennej artist
*   \param[in,out] char *type wskaznik zmiennej type
*   \param[in,out] char *title wskaznik zmiennej title
*   \param[in,out] char *state wskaznik zmiennej state
*   \param[in,out] char *heard wskaznik zmiennej heard
*   \param[in,out] int *year wskaznik zmiennej year
*   \param[in,out] int *id wskaznik zmiennej id
*/
//dodanie elementu do listy
void add_node(Music_album_type **head,char *artist,char *type,char *title,char *state,char *heard, int year,int* id){

    if(*head==NULL)
	{

		*head = (Music_album_type*)malloc(sizeof(Music_album_type));
        (*id)=0;
        strcpy((*head)->artist,artist);
        strcpy((*head)->type,type);
        strcpy((*head)->title,title);
        strcpy((*head)->state,state);
        strcpy((*head)->heard,heard);
        (*head)->year=year;
        (*head)->id=*id;
        (*head)->next = NULL;
        (*id)++;

	}else
	{
		Music_album_type *current=*head;
	    while (current->next != NULL) {
	        current = current->next;
	    }


	    current->next = (Music_album_type *)malloc(sizeof(Music_album_type));

        strcpy(current->next->artist,artist);
        strcpy(current->next->type,type);
        strcpy(current->next->title,title);
        strcpy(current->next->state,state);
        strcpy(current->next->heard,heard);
        current->next->year=year;
        current->next->id=*id;
        (*id)++;
        current->next->next = NULL;
	}

}
/**
*   Funkcja wyœwietla elementy albumu
*   \param[in,out] TYPE_type *hhhead wskaznik struktury TYPE_type
*   \param[in,out] ID_TYPE_type *hhead wskaznik struktury ID_TYPE_type
*   \param[in,out] Music_album_type *head wskaznik struktury Music_album_type
*   \param[in,out] ID_ARTIST_type *headd wskaznik struktury ID_ARTIST_type
*   \param[in,out] ARTIST_type *headdd wskaznik struktury ARTIST_type
*/
//wyswietlanie albumow
void show_album(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd)
{
    Music_album_type *current;
    current=head;
    TYPE_type *hhhelp;
    hhhelp=hhhead;
    ID_TYPE_type *hhelp;
    hhelp=hhead;
    ID_ARTIST_type *helpp;
    helpp=headd;
    ARTIST_type *helppp;
    helppp=headdd;
    int j;
    if(current==NULL) printf("Lista jest pusta\n");
    else
    {
        while (current != NULL)
        {
            printf("ID: %d\n",current->id);
            printf("Artysta: %s\n",current->artist);
            printf("Gatunek: %s\n",current->type);
            printf("Tytul: %s\n",current->title);
            printf("Kupiony: %s\n",current->state);
            printf("Przesluchany: %s\n",current->heard);
            printf("Rok: %d\n",current->year);
                        int i=current->id;
        helpp=headd;
        helppp=headdd;
        hhelp=hhead;
        hhhelp=hhhead;
        if(headd!=NULL)
        {
            while(helpp!=NULL)
        {
            if(helpp->id==i)
            {
            j=helpp->id_art;
            while(helppp->id_art!=j&&helppp->next!=NULL)
            {
                helppp=helppp->next;
            }
            printf("Artysta dodatkowy: %s\n",helppp->artist);
            helppp=headdd;
            helpp=helpp->next;
            }
           else
            helpp=helpp->next;
        }
        }
        if(hhead!=NULL)
        {
            while(hhelp!=NULL)
        {
            if(hhelp->id==i)
            {
            j=hhelp->id_type;
            while(hhhelp->id_type!=j&&hhhelp->type!=NULL)
            {
                hhhelp=hhhelp->next;
            }
            printf("Gatunek dodatkowy: %s\n",hhhelp->type);
            hhhelp=hhhead;
            hhelp=hhelp->next;
            }
           else
            hhelp=hhelp->next;
        }
        }
        helpp=headd;
        helppp=headdd;
        hhelp=hhead;
        hhhelp=hhhead;
        current = current->next;
        printf("\n");
        }
    }
}
/**
*   Funkcja usuwajaca struktury
*   \param[in,out] TYPE_type **hhhead wskaznik struktury TYPE_type
*   \param[in,out] ID_TYPE_type **hhead wskaznik struktury ID_TYPE_type
*   \param[in,out] Music_album_type **head wskaznik struktury Music_album_type
*   \param[in,out] ID_ARTIST_type **headd wskaznik struktury ID_ARTIST_type
*   \param[in,out] ARTIST_type **headdd wskaznik struktury ARTIST_type
*/
void delete_structures(TYPE_type **hhhead, ID_TYPE_type **hhead,Music_album_type **head, ID_ARTIST_type **headd, ARTIST_type **headdd)
{
    Music_album_type *tmp=NULL;
    while ((*head)!=NULL) {
   	 tmp=(*head)->next;
   	 free(*head);
   	 *head=tmp;
	}
    ID_ARTIST_type *tmpp=NULL;
	while ((*headd)!=NULL) {
   	 tmpp=(*headd)->next;
   	 free(*headd);
   	 *headd=tmpp;
	}
ARTIST_type *tmppp=NULL;
	while ((*headdd)!=NULL) {
   	 tmppp=(*headdd)->next;
   	 free(*headdd);
   	 *headdd=tmppp;
	}
	TYPE_type *tttmp=NULL;
    while ((*hhhead)!=NULL) {
   	 tttmp=(*hhhead)->next;
   	 free(*hhhead);
   	 *hhhead=tttmp;
	}
	ID_TYPE_type *ttmp=NULL;
    while ((*hhead)!=NULL) {
   	 ttmp=(*hhead)->next;
   	 free(*hhead);
   	 *hhead=ttmp;
	}
}
/**
*   Funkcja usuwajaca album
*   \param[in,out] Music_album_type **head wskaznik struktury Music_album_type
*/
//usuwanie albumu
void delete_first(Music_album_type **head)
{
    Music_album_type *tmp=NULL;
    if (*head!=NULL) {
   	 tmp=(*head)->next;
   	 free(*head);
   	 *head=tmp;
	}
    printf("Album zostal pomyslnie usuniety");
    Sleep(500);
}
// czyszczenie
/**
*   Funkcja usuwa album poprzez index
*   \param[in,out] Music_album_type **head wskzanik na strukture Music_album_type
*   \param[in,out] ID_TYPE_type **hhead wskaznik na strukture ID_TYPE_type
*   \param[in,out] ID_ARTIST_type **headd wskaznik na strukture ID_ARTIST_type
*   \param[in]  int index numer indexu
*/
//usuwanie poprzez index
void delete_node_by_index(Music_album_type **head,ID_TYPE_type **hhead,ID_ARTIST_type **headd, int index)
{

	if(index==0) delete_first(head);
	else
	{
		Music_album_type *current=*head;
	    Music_album_type *tmp=*head;
	    ID_TYPE_type *ccurrent=*hhead;
	    ID_TYPE_type *ttmp=*hhead;
	    ID_ARTIST_type *currentt=*headd;
	    ID_ARTIST_type *tmpp=*headd;

		int i=0;
		while (current->next != NULL && i<index) {
                tmp=current;
	        current=current->next;
			i++;
			}
        if(current->id==index)
        {
          tmp->next = current->next;
	    current->next =NULL;
	    free(current);
	        printf("Album zostal pomyslnie usuniety");
    Sleep(500);



 while (ttmp)
    {
        puts("aa");
        ID_TYPE_type *poprzedni=*hhead;
        ID_TYPE_type *nastepny=NULL;
        if (ttmp->id==index)
        {
            if ((*hhead)->id==index)
            {
                nastepny=(*hhead)->next;
                free(*hhead);
                *hhead=nastepny;
            }
            else
            {
                while (poprzedni)
                {
                    if (poprzedni->next->id==index)
                        break;
                    poprzedni=poprzedni->next;
                }
                nastepny = poprzedni->next;
                poprzedni->next=nastepny->next;
                free(nastepny);
            }
        }
        ttmp=ttmp->next;
    }

    while (tmpp)
    {
        ID_ARTIST_type *poprzedni=*headd;
        ID_ARTIST_type *nastepny=NULL;
        if (tmpp->id==index)
        {
            if ((*headd)->id==index)
            {
                nastepny=(*headd)->next;
                free(*headd);
                *headd=nastepny;
            }
            else
            {
                while (poprzedni)
                {
                    if (poprzedni->next->id==index)
                        break;
                    poprzedni=poprzedni->next;
                }
                nastepny = poprzedni->next;
                poprzedni->next=nastepny->next;
                free(nastepny);
            }
        }
        tmpp=tmpp->next;
    }
        }
		else
        {
            puts("Nie ma takiego albumu");
        Sleep(500);
		}

	}
}
/**
*   Funkcja zapisuje album do pliku txt
*   \param[in,out] TYPE_type *hhhead wskaznik na strukture TYPE_type
*   \param[in,out] ID_TYPE_type *hhead wskaznik na strukture ID_TYPE_type
*   \param[in,out] Music_album_type *head wskaznik na strukture Music_album_type
*   \param[in,out] ID_ARTIST_type *headd wskaznik na strukture ID_ARTIST_type
*   \param[in,out] ARTIST_type *headdd wskaznik na strukture ARTIST_type
*/
//zapis do pliku
void save(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd)
{
    FILE *save;
    Music_album_type *tmp;
    char name[]="album.txt";

     if(head == NULL)
    {
        printf("Nie ma elementow do zapisania");
        getchar();
    }
    else
    {
        save=fopen(name, "w");
        if(save == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmp = head;
            while (tmp != NULL)
            {
                fprintf(save,"%d",tmp->id);
                fprintf(save,"%s\n",tmp->artist);
                fprintf(save,"%s\n",tmp->type);
                fprintf(save,"%s\n",tmp->title);
                fprintf(save,"%s\n",tmp->state);
                fprintf(save,"%s\n",tmp->heard);
                fprintf(save,"%d",tmp->year);
                if(tmp->next){
                	fprintf(save,"\n");
				}
                tmp = tmp->next;
            }
            fclose(save);
        }
    }


    FILE *savee;
    ID_ARTIST_type *tmpp;
    char namee[]="id_art.txt";

     if(headd == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        savee=fopen(namee, "w");
        if(savee == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmpp = headd;
            while (tmpp != NULL)
            {
                fprintf(savee,"%d ",tmpp->id);
                fprintf(savee,"%d",tmpp->id_art);
                if(tmpp->next){
                	fprintf(savee,"\n");
				}
                tmpp = tmpp->next;
            }
            fclose(savee);
        }
    }


    FILE *saveee;
    ARTIST_type *tmppp;
    char nameee[]="Artist.txt";

     if(headdd == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        saveee=fopen(nameee, "w");
        if(saveee == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmppp = headdd;
            while (tmppp != NULL)
            {
                fprintf(saveee,"%d",tmppp->id_art);
                fprintf(saveee,"%s",tmppp->artist);
                if(tmppp->next){
                	fprintf(saveee,"\n");
				}
                tmppp = tmppp->next;
            }
            fclose(saveee);
        }
    }

        FILE *ssave;
    ID_TYPE_type *ttmp;
    char nname[]="id_type.txt";

     if(hhead == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        ssave=fopen(nname, "w");
        if(ssave == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            ttmp = hhead;
            while (ttmp != NULL)
            {
                fprintf(ssave,"%d ",ttmp->id);
                fprintf(ssave,"%d",ttmp->id_type);
                if(ttmp->next){
                	fprintf(ssave,"\n");
				}
                ttmp = ttmp->next;
            }
            fclose(ssave);
        }
    }


    FILE *sssave;
    TYPE_type *tttmp;
    char nnname[]="type.txt";

     if(hhhead == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        sssave=fopen(nnname, "w");
        if(sssave == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tttmp = hhhead;
            while (tttmp != NULL)
            {
                fprintf(sssave,"%d",tttmp->id_type);
                fprintf(sssave,"%s",tttmp->type);
                if(tttmp->next){
                	fprintf(sssave,"\n");
				}
                tttmp = tttmp->next;
            }
            fclose(sssave);
        }
    }
}


/**
*   Funkcja zapisuje album do pliku csv
*   \param[in,out] TYPE_type *hhhead wskaznik na strukture TYPE_type
*   \param[in,out] ID_TYPE_type *hhead wskaznik na strukture ID_TYPE_type
*   \param[in,out] Music_album_type *head wskaznik na strukture Music_album_type
*   \param[in,out] ID_ARTIST_type *headd wskaznik na strukture ID_ARTIST_type
*   \param[in,out] ARTIST_type *headdd wskaznik na strukture ARTIST_type
*/

void save_csv(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd)
{
    FILE *save;
    Music_album_type *tmp;
    char name[]="album.csv";

     if(head == NULL)
    {
        printf("Nie ma elementow do zapisania");
        getchar();
    }
    else
    {
        save=fopen(name, "w");
        if(save == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmp = head;
            while (tmp != NULL)
            {
                fprintf(save,"%d,",tmp->id);
                fprintf(save,"%s,",tmp->artist);
                fprintf(save,"%s,",tmp->type);
                fprintf(save,"%s,",tmp->title);
                fprintf(save,"%s,",tmp->state);
                fprintf(save,"%s,",tmp->heard);
                fprintf(save,"%d",tmp->year);
                if(tmp->next){
                	fprintf(save,"\n");
				}
                tmp = tmp->next;
            }
            fclose(save);
        }
    }


    FILE *savee;
    ID_ARTIST_type *tmpp;
    char namee[]="id_art.csv";

     if(headd == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        savee=fopen(namee, "w");
        if(savee == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmpp = headd;
            while (tmpp != NULL)
            {
                fprintf(savee,"%d,",tmpp->id);
                fprintf(savee,"%d",tmpp->id_art);
                if(tmpp->next){
                	fprintf(savee,"\n");
				}
                tmpp = tmpp->next;
            }
            fclose(savee);
        }
    }


    FILE *saveee;
    ARTIST_type *tmppp;
    char nameee[]="Artist.csv";

     if(headdd == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        saveee=fopen(nameee, "w");
        if(saveee == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tmppp = headdd;
            while (tmppp != NULL)
            {
                fprintf(saveee,"%d,",tmppp->id_art);
                fprintf(saveee,"%s",tmppp->artist);
                if(tmppp->next){
                	fprintf(saveee,"\n");
				}
                tmppp = tmppp->next;
            }
            fclose(saveee);
        }
    }

        FILE *ssave;
    ID_TYPE_type *ttmp;
    char nname[]="id_type.csv";

     if(hhead == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        ssave=fopen(nname, "w");
        if(ssave == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            ttmp = hhead;
            while (ttmp != NULL)
            {
                fprintf(ssave,"%d,",ttmp->id);
                fprintf(ssave,"%d",ttmp->id_type);
                if(ttmp->next){
                	fprintf(ssave,"\n");
				}
                ttmp = ttmp->next;
            }
            fclose(ssave);
        }
    }


    FILE *sssave;
    TYPE_type *tttmp;
    char nnname[]="type.csv";

     if(hhhead == NULL)
    {
        printf("Nie ma elementow do zapisania w tej strukturze");
        getchar();
    }
    else
    {
        sssave=fopen(nnname, "w");
        if(sssave == NULL)
        {
            printf("Blad otwarcia pliku");
            getchar();
        }
        else
        {
            tttmp = hhhead;
            while (tttmp != NULL)
            {
                fprintf(sssave,"%d,",tttmp->id_type);
                fprintf(sssave,"%s",tttmp->type);
                if(tttmp->next){
                	fprintf(sssave,"\n");
				}
                tttmp = tttmp->next;
            }
            fclose(sssave);
        }
    }
}
/**
*   Funkcja odczytuje albumy z pliku
*   \param[in,out] TYPE_type **hhhead wskaznik na strukture TYPE_type
*   \param[in,out] ID_TYPE_type **hhead wskaznik na strukture ID_TYPE_type
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*   \param[in,out] ID_ARTIST_type **headd wskaznik na strukture ID_ARTIST_type
*   \param[in,out] ARTIST_type **headdd wskaznik na strukture ARTIST_type
*   \param[in,out] int* id wskaznik zmiennej id
*/
//odczyt z pliku
void Read(TYPE_type **hhhead, ID_TYPE_type **hhead, Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id)
{
	delete_structures(hhhead,hhead,head,headd,headdd);
	char a;
	char v[100];
	int last;
	char c='\0';
	int i;
    FILE *read;
    char name[]="album.txt";
    Music_album_type *tmp;
    Music_album_type *pom;
    read = fopen(name, "r");
    if (read == NULL)
    {
        printf("Blad otwarcia pliku");
        getchar();
    }
    else
    {
        while (fgetc(read) != EOF)
        {
                tmp = (Music_album_type*)malloc(sizeof(Music_album_type));
                tmp->next = NULL;
                fscanf(read,"%d",&tmp->id);
                fgets(v,100,read);
                memmove(tmp->artist,v,strlen(v)-1);
                fgets(v,100,read);
                memmove(tmp->type,v,strlen(v)-1);
                fgets(v,100,read);
                memmove(tmp->title,v,strlen(v)-1);
                fgets(v,100,read);
                memmove(tmp->state,v,strlen(v)-1);
                fgets(v,100,read);
                memmove(tmp->heard,v,strlen(v)-1);
                fscanf(read,"%d",&tmp->year);
                (*id)++;


            if (*head == NULL){
                *head = tmp;
				}
            else
            {
                pom = *head;
                while (pom->next != NULL)
                    {
					pom = pom->next;
					}
                pom->next = tmp;
            }
        }
        fclose(read);
    }
    FILE *readdd;
    char nameee[]="Artist.txt";
    ARTIST_type *tmppp;
    ARTIST_type *pommm;

    readdd = fopen(nameee, "r");
    if (readdd == NULL)
    {
        printf("Blad otwarcia pliku");
        getchar();
    }
    else
    {
        while (fgetc(readdd) != EOF)
        {
                tmppp = (ARTIST_type*)malloc(sizeof(ARTIST_type));
                tmppp->next = NULL;
                fscanf(readdd,"%d",&tmppp->id_art);
                fscanf(readdd,"%[^\n]s",tmppp->artist);
            if (*headdd == NULL){
                *headdd = tmppp;
                (*headdd)->id_art=0;
				}
            else
            {
                pommm = *headdd;
                while (pommm->next != NULL)
                    {
					pommm = pommm->next;
					}
                pommm->next = tmppp;
            }
        }
        fclose(readdd);
    }
    FILE *readd;
    char namee[]="id_art.txt";
    //char hh[100];
    ID_ARTIST_type *tmpp;
    ID_ARTIST_type *pomm;

    readd = fopen(namee, "r");
    if (readd == NULL)
    {
        printf("Blad otwarcia pliku");
        getchar();
    }
    else
    {
        while (fgetc(readd) != EOF)
        {
                tmpp = (ID_ARTIST_type*)malloc(sizeof(ID_ARTIST_type));
                tmpp->next = NULL;
                fscanf(readd,"%d",&tmpp->id);
                fscanf(readd,"%d",&tmpp->id_art);
            if (*headd == NULL){
                *headd = tmpp;
                //(*headd)->id=0;
				}
            else
            {
                pomm = *headd;
                while (pomm->next != NULL)
                    {
					pomm = pomm->next;
					}
                pomm->next = tmpp;
            }
        }
        fclose(readd);
    }







    FILE *rrread;
    char nnname[]="type.txt";
    TYPE_type *tttmp;
    TYPE_type *pppom;

    rrread = fopen(nnname, "r");
    if (rrread == NULL)
    {
        printf("Blad otwarcia pliku");
        getchar();
    }
    else
    {
        while (fgetc(rrread) != EOF)
        {
                tttmp = (TYPE_type*)malloc(sizeof(TYPE_type));
                tttmp->next = NULL;
                fscanf(rrread,"%d",&tttmp->id_type);
                fscanf(rrread,"%[^\n]s",tttmp->type);
            if (*hhhead == NULL){
                *hhhead = tttmp;
                //(*hhhead)->id_type=0;
				}
            else
            {
                pppom = *hhhead;
                while (pppom->next != NULL)
                    {
					pppom = pppom->next;
					}
                pppom->next = tttmp;
            }
        }
        fclose(rrread);
    }
    FILE *rread;
    char nname[]="id_type.txt";
    ID_TYPE_type *ttmp;
    ID_TYPE_type *ppom;

    rread = fopen(nname, "r");
    if (rread == NULL)
    {
        printf("Blad otwarcia pliku");
        getchar();
    }
    else
    {
        while (fgetc(rread) != EOF)
        {
                ttmp = (ID_TYPE_type*)malloc(sizeof(ID_TYPE_type));
                ttmp->next = NULL;
                fscanf(rread,"%d",&ttmp->id);
                fscanf(rread,"%d",&ttmp->id_type);
            if (*hhead == NULL){
                *hhead = ttmp;
                (*hhead)->id=0;
				}
            else
            {
                ppom = *hhead;
                while (ppom->next != NULL)
                    {
					ppom = ppom->next;
					}
                ppom->next = ttmp;
            }
        }
        fclose(rread);
    }
}
/**
*   Funkcja wykorzystywana jest do edycji albumow w bazie
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*/
void edit_album(Music_album_type **head)
{
    int id = 0;
    char w;
    Music_album_type *tmp = NULL;
    tmp = *head;

    printf("Prosze podac ID filmu: ");
    scanf("%d", &id);
    if(tmp)
    {
        while(tmp != NULL)
        {
            if(tmp->id == id)
            {
                do
                {
                    system("cls");
                    printf("Wybrano ID albumu: %d\n",tmp->id);
                    printf("Artysta: %s\n",tmp->artist);
                    printf("Gatunek: %s\n",tmp->type);
                    printf("Tytul: %s\n",tmp->title);
                    printf("Kupiony: %s\n",tmp->state);
                    printf("Przesluchany: %s\n",tmp->heard);
                    printf("Rok: %d\n\n\n",tmp->year);
                    printf("1.Artysta\n2.Gatunek\n3.Tytul\n4.Kupiony\n5.Przesluchany\n6.Rok\n0.Powrot\n");
                    printf("Twoj wybor: ");
                    w=getch();

                switch(w){

                   case '1':
                        system("cls");
                        printf("Artysta: %s\n", tmp->artist);
                        printf("Nowy artysta: ");
                        scanf("%s", tmp->artist);
                        break;
                    case '2':
                        system("cls");
                        printf("Gatunek: %s\n", tmp->type);
                        printf("Nowy gatunek: ");
                        scanf("%s", tmp->type);
                        break;
                    case '3':
                        system("cls");
                        printf("Tytul: %s\n", tmp->title);
                        printf("Tytul: ");
                        scanf("%s", tmp->title);
                        break;
                    case '4':
                        system("cls");
                        printf("Kupiony: %s\n", tmp->state);
                        printf("Kupiony: ");
                        scanf("%s", tmp->state);
                        break;
                    case '5':
                        system("cls");
                        printf("Przesluchany: %s\n", tmp->heard);
                        printf("Przesluchany: ");
                        scanf("%s", tmp->heard);
                        getchar();
                        break;
                    case '6':
                        system("cls");
                        printf("Rok: %d\n", tmp->year);
                        printf("Nowy rok: ");
                        scanf("%d", &tmp->year);
                        getchar();
                        break;
                    case '0':
                        system("cls");
                        printf("Powracanie. Nacisnij Enter aby kontynuowac.");
                        break;
                    default:
                        printf("Nie ma takiego wyboru, nacisnij ENTER aby kontynowac");
                }

                }while(w != '0');
            }
            tmp = tmp->next;
        }
    }
}
/**
*   Funkcja add_artist odpowiada za po³¹czenie wybranego artysty z wybranym albumem
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*   \param[in,out] ID_ARTIST_type **headd wskaznik na strukture ID_ARTIST_type
*   \param[in,out] ARTIST_type *headdd wskaznik na strukture ARTIST_type
*/
void add_artist(Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type *headdd)
{
    char a;
    int i,j;
    puts("Aby powrocic do menu wcisnij 0, aby przejsc dalej nacisnij dowolny klawisz");
    a=getch();
    system("cls");
    Sleep(500);
    while(a!='0')
    {
        system("cls");
        Music_album_type *help;
        ID_ARTIST_type *helpp;
        ARTIST_type *helppp=headdd;
        help=(*head);
        puts("Wybierz album");
        while(help!=NULL)
        {
            printf("%d ",help->id);
            printf("%s\t",help->artist);
            printf("%s\n",help->title);
            help=help->next;
        }
        scanf("%d",&i);
        system("cls");
        puts("Wybierz artyste:");
        while(helppp!=NULL)
        {
            printf("%d ",helppp->id_art);
            printf("%s\n",helppp->artist);
            helppp=helppp->next;
        }
        helppp=headdd;
        helpp=(*headd);
        scanf("%d",&j);
        if((*headd)==NULL)
        {

            ID_ARTIST_type *current;
            current = (ID_ARTIST_type *)malloc(sizeof(ID_ARTIST_type));
            current->id=i;
            current->id_art=j;
            current->next=NULL;
            (*headd)=current;
        }
        else
        {
            while(helpp->id<=i&&helpp->next!=NULL)
        {
            helpp=helpp->next;
        }
        ID_ARTIST_type *current;
        current = (ID_ARTIST_type *)malloc(sizeof(ID_ARTIST_type));
        current->id=i;
            current->id_art=j;
            if(helpp->next==NULL)
            {
                helpp->next=current;
                current->next=NULL;
            }
            else
            {
               current->next=helpp->next;
            helpp->next=current;
            }
        }
        system("cls");
        Sleep(500);
        puts("Zapisani artysci");
        helpp=(*headd);
        while(helpp!=NULL)
        {
            if(helpp->id==i)
            {
                 printf("%d ",helpp->id);
            j=helpp->id_art;
            while(helppp->id_art!=j)
            {
                helppp=helppp->next;
            }
            printf("%s\n",helppp->artist);
            helppp=headdd;
            helpp=helpp->next;
            }
           else
            helpp=helpp->next;
        }
    puts("Aby powrocic do menu wcisnij 0");
    a=getch();
    system("cls");
    Sleep(500);
    }

}
/**
*   Funkcja delete_artist usuwa po³¹czenie artysty z albumem
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*   \param[in,out] ID_ARTIST_type **headd wskaznik na strukture ID_ARTIST_type
*   \param[in,out] ARTIST_type *headdd wskaznik na strukture ARTIST_type
*/
void delete_artist(Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type *headdd)
{
        char a;
        int i,point=0,j;
        Music_album_type *help=(*head);
        ID_ARTIST_type *helpp=(*headd);
        ARTIST_type *helppp=headdd;
        help->id=0;
        while(a!='0')
        {
            system("cls");
        point=0;
        help=(*head);
        helpp=(*headd);
        helppp=headdd;
        while(help!=NULL)
        {
            printf("%d ",help->id);
            printf("%s\t",help->artist);
            printf("%s\n",help->title);
            help=help->next;
        }
            puts("Podaj id albumu:");
            scanf("%d",&i);
            a='0';
            system("cls");
            puts("Zapisani artysci:");
        helpp=(*headd);
        while(helpp!=NULL)
        {
            if(helpp->id==i)
            {
                point++;
                 printf("%d ",helpp->id_art);
            j=helpp->id_art;
            while(helppp->id_art!=j)
            {
                helppp=helppp->next;
            }
            printf("%s\n",helppp->artist);
            helppp=headdd;
            helpp=helpp->next;
            }
           else
            helpp=helpp->next;
        }
        helpp=(*headd);
           if(point==0)
                puts("Brak artystow");
           else
           {
               puts("Podaj id do usuniecia");
               scanf("%d",&i);
               if(helpp->id_art==i)
               {
                   ID_ARTIST_type *current;
                   current = (ID_ARTIST_type*)malloc(sizeof(ID_ARTIST_type));
                   current=(*headd)->next;
                   free(*headd);
                   (*headd)=current;
               }
               else
               {
               while(helpp->next->id_art!=i)
               {
                   helpp->next;
               }
               helpp->next=helpp->next->next;
               }

           }
        puts("Aby powrocic do menu nacisnij zero, aby pozostac nacisnij dowolny klawisz");
        a=getch();
        system("cls");
        Sleep(500);
        }
}
/**
*   Funkcja modify_artist jest funkcja odpowiedzialna za tworzenie listy artystow i ja modyfikuje
*   czyli usuwa, dodaje artyste do listy z ktorej potem korzysta add_artist
*   \param[in,out] ARTIST_type **headdd wskaznik na strukture ARTIST_type
*/
void modify_artist(ARTIST_type **headdd)
{
    char artist[100];
    char a;
    char b;
    int i=0;
    int id;
    ARTIST_type *help=(*headdd);
    ARTIST_type *tmp=(*headdd);
    ARTIST_type *current=*headdd;
    help=(*headdd);
    do
    {
        system("cls");
        current=*headdd;
        help=(*headdd);
        if(help==NULL)
            puts("Brak artystow");
            if(help!=NULL)
        puts("Artysci:");
        while(help!=NULL)
        {
            printf("%d ",help->id_art);
            printf("%s\n",help->artist);
            help=help->next;
        }

        puts("[1]Dodaj artyste\n[2]Usun artyste\n[0]Powrot do menu");
            b=getch();
        switch(b)
        {
        case'1':
        puts("Podaj artyste");
        scanf("%[^\n]",artist);
        getchar();
    if(*headdd==NULL)
	{
		*headdd = (ARTIST_type*)malloc(sizeof(ARTIST_type));
        (*headdd)->id_art=0;
        strcpy((*headdd)->artist,artist);
        (*headdd)->next = NULL;

	}else
	{
	    while (current->next != NULL)
        {
	        current = current->next;
	    }
	    current->next = (ARTIST_type *)malloc(sizeof(ARTIST_type));
        int id=0;
        id=current->id_art;
        id++;
        strcpy(current->next->artist,artist);
        current->next->id_art=id;
        current->next->next = NULL;
	}
	break;
        case '2':
            puts("Podaj id do usuniecia");
            scanf("%d",&i);

            if (i==(((*headdd)->id_art))) {
            tmp=(*headdd)->next;
            free(*headdd);
            (*headdd)=tmp;
            }
            else{
                int z=0;
                while (current->next != NULL && z<i-1) {
                    current=current->next;
                    z++;
                }
                tmp = current->next;
                current->next = tmp->next;
                free(tmp);
            }
            break;
        case '0':
            puts("Powrot do menu");
            break;
        default:
            puts("Zly wybor");
        }
    }
    while(b!='0');
}

/**
*   Funkcja add_type odpowiada za po³¹czenie wybranego gatunku z wybranym albumem
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*   \param[in,out] ID_TYPE_type **headd wskaznik na strukture ID_TYPE_type
*   \param[in,out] TYPE_type *headdd wskaznik na strukture TYPE_type
*/
void add_type(Music_album_type **head,ID_TYPE_type **headd,TYPE_type *headdd)
{
    char a;
    int i,j;
    puts("Aby powrocic do menu wcisnij 0, aby przejsc dalej nacisnij dowolny klawisz");
    a=getch();
    system("cls");
    Sleep(500);
    while(a!='0')
    {
        system("cls");
        Music_album_type *help;
        ID_TYPE_type *helpp;
        TYPE_type *helppp=headdd;
        help=(*head);
        puts("Wybierz album");
        while(help!=NULL)
        {
            printf("%d ",help->id);
            printf("%s\t",help->artist);
            printf("%s\n",help->title);
            help=help->next;
        }
        scanf("%d",&i);
        system("cls");
        puts("Wybierz gatunek:");
        while(helppp!=NULL)
        {
            printf("%d ",helppp->id_type);
            printf("%s\n",helppp->type);
            helppp=helppp->next;
        }
        helppp=headdd;
        helpp=(*headd);
        scanf("%d",&j);
        if((*headd)==NULL)
        {

            ID_TYPE_type *current;
            current = (ID_TYPE_type *)malloc(sizeof(ID_TYPE_type));
            current->id=i;
            current->id_type=j;
            current->next=NULL;
            (*headd)=current;
        }
        else
        {
            while(helpp->id<=i&&helpp->next!=NULL)
        {
            helpp=helpp->next;
        }
        ID_TYPE_type *current;
        current = (ID_TYPE_type *)malloc(sizeof(ID_TYPE_type));
        current->id=i;
            current->id_type=j;
            if(helpp->next==NULL)
            {
                helpp->next=current;
                current->next=NULL;
            }
            else
            {
               current->next=helpp->next;
            helpp->next=current;
            }
        }
        system("cls");
    Sleep(500);
        puts("Zapisane gatunki");
        helpp=(*headd);
        while(helpp!=NULL)
        {
            if(helpp->id==i)
            {
                 printf("%d ",helpp->id);
            j=helpp->id_type;
            while(helppp->id_type!=j)
            {
                helppp=helppp->next;
            }
            printf("%s\n",helppp->type);
            helppp=headdd;
            helpp=helpp->next;
            }
           else
            helpp=helpp->next;
        }
    puts("Aby powrocic do menu wcisnij 0");
    a=getch();
    system("cls");
    Sleep(500);
    }

}
/**
*   Funkcja delete_type usuwa polaczenie gatunku z albumem
*   \param[in,out] Music_album_type **head wskaznik na strukture Music_album_type
*   \param[in,out] ID_TYPE_type **headd wskaznik na strukture ID_TYPE_type
*   \param[in,out] TYPE_type *headdd wskaznik na strukture TYPE_type
*/
void delete_type(Music_album_type **head,ID_TYPE_type **hhead,TYPE_type *headdd)
{
        char a;
        int i,point=0,j;
        Music_album_type *help=(*head);
        ID_TYPE_type *hhelp=(*hhead);
        TYPE_type *helppp=headdd;
        help->id=0;
        while(a!='0')
        {
        point=0;
        help=(*head);
        hhelp=(*hhead);
        helppp=headdd;
        while(help!=NULL)
        {
            printf("%d ",help->id);
            printf("%s\t",help->artist);
            printf("%s\n",help->title);
            help=help->next;
        }
            puts("Podaj id albumu:");
            scanf("%d",&i);
            a='0';
            system("cls");
            puts("Zapisane gatunki:");
        hhelp=(*hhead);
        while(hhelp!=NULL)
        {
            if(hhelp->id==i)
            {
                point++;
                 printf("%d ",hhelp->id_type);
            j=hhelp->id_type;
            while(helppp->id_type!=j)
            {
                helppp=helppp->next;
            }
            printf("%s\n",helppp->type);
            helppp=headdd;
            hhelp=hhelp->next;
            }
           else
            hhelp=hhelp->next;
        }
        hhelp=(*hhead);
           if(point==0)
                puts("Brak gatunkow");
           else
           {
               puts("Podaj id do usuniecia");
               scanf("%d",&i);
               if(hhelp->id_type==i)
               {
                   ID_TYPE_type *current;
                   current = (ID_TYPE_type*)malloc(sizeof(ID_TYPE_type));
                   current=(*hhead)->next;
                   free(*hhead);
                   (*hhead)=current;
               }
               else
               {
               while(hhelp->next->id_type!=i)
               {
                   hhelp->next;
               }
               hhelp->next=hhelp->next->next;
               }

           }
        puts("Aby powrocic do menu nacisnij zero, aby pozostac nacisnij dowolny klawisz");
        a=getch();
        system("cls");
        Sleep(500);
        }
}
/**
*   Funkcja modify_type jest funkcja odpowiedzialna za tworzenie listy gatunkow i ja modyfikuje
*   czyli usuwa, dodaje gatunek do listy z ktorej potem korzysta add_type
*   \param[in,out] TYPE_type **hhhead wskaznik na strukture TYPE_type
*/
void modify_type(TYPE_type **headdd)
{
    char type[100];
    char a;
    char b;
    int i=0;
    int id;
    TYPE_type *help=(*headdd);
    TYPE_type *tmp=(*headdd);
    TYPE_type *current=*headdd;
    help=(*headdd);
    do
    {
        system("cls");
        current=*headdd;
        help=(*headdd);
        if(help==NULL)
            puts("Brak gatunkow");
            if(help!=NULL)
        puts("Gatunki:");
        while(help!=NULL)
        {
            printf("%d ",help->id_type);
            printf("%s\n",help->type);
            help=help->next;
        }

        puts("[1]Dodaj gatunek\n[2]Usun gatunek\n[0]Powrot do menu");
            b=getch();
        switch(b)
        {
        case'1':
        puts("Podaj gatunek");
        scanf("%[^\n]",type);
        getchar();
    if(*headdd==NULL)
	{
		*headdd = (TYPE_type*)malloc(sizeof(TYPE_type));
        (*headdd)->id_type=0;
        strcpy((*headdd)->type,type);
        (*headdd)->next = NULL;

	}else
	{
	    while (current->next != NULL)
        {
	        current = current->next;
	    }
	    current->next = (TYPE_type *)malloc(sizeof(TYPE_type));
        int id=0;
        id=current->id_type;
        id++;
        strcpy(current->next->type,type);
        current->next->id_type=id;
        current->next->next = NULL;
	}
	break;
        case '2':
            puts("Podaj id do usuniecia");
            scanf("%d",&i);

            if (i==(((*headdd)->id_type))) {
            tmp=(*headdd)->next;
            free(*headdd);
            (*headdd)=tmp;
            }
            else{
                int z=0;
                while (current->next != NULL && z<i-1) {
                    current=current->next;
                    z++;
                }
                tmp = current->next;
                current->next = tmp->next;
                free(tmp);
            }
            break;
        case '0':
            puts("Powrot do menu");
            break;
        default:
            puts("Zly wybor");
        }
    }
    while(b!='0');
}
