/** Zalacza plik menu.h*/
#include "menu.h"
/** Glowna funkcja wywolana w funkcji main() projektu */

void run_main_loop()
{
	Music_album_type *head=NULL;
    ID_ARTIST_type *headd=NULL;
    ARTIST_type *headdd=NULL;
    ID_TYPE_type *hhead=NULL;
    TYPE_type *hhhead=NULL;
    char menuChoice;
    int id=0;
    Read(&hhhead,&hhead,&head,&headd,&headdd,&id);
    while(1)
    {
        show_main_options();
        printf("Twoj wybor: ");
        menuChoice=getch();
        startAction(menuChoice,&head,&headd,&headdd,&id,&hhead,&hhhead);
	}
}

/** Funkcja dzieki printf() i puts() wyswietla na ekran interfejs menu*/
void show_main_options()
{
        printf("------Program Albumy Muzyczne------\n");
        puts("-----------------------------------");
        printf("----------1->.Dodaj album----------\n");
        printf("------2->Usun album (Wpisz ID)-----\n");
        printf("---------3->Wyswietl albumy--------\n");
        printf("----4->Zapis do pliku txt i csv-----\n");
        printf("---------5->Odczyt z pliku---------\n");
        printf("---------6->Edycja albumu----------\n");
        printf("--------7->Opcje Sortowania--------\n");
        printf("8->Edycja ilosci artystow i gatunkow\n");
        printf("--------0->Koniec programu---------\n\n");
}

/** Funkcja odpowiada za dzialanie menu programu.
*   Przyjmuje siedem parametrow.
*   \param[in] menuChoice wybor opcji
*   \param[in,out] Music_album_type **head podwojny wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd podwojny wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type **head podwojny wskaznik struktury ARTIST
*   \param[in,out] int* id wskaznik zmiennej id
*   \param[in,out] ID_TYPE_type **hhead wskaznik struktury ID_TYPE
*   \param[in,out] TYPE_type **hhhead  wskaznik struktury TYPE
*   Przy pomocy pobrania od u¿ytkownika wyboru,konstrukcja switch pozwala wybrac odpowiednia operacje.
*   Jest w niej 10 przypadkow (w tym default, informujacy o bledzie w wyborze).
*   Przypadek 1 dodaje album do listy, dzieki funkcji action_add_album().
*   Przypadek 2 usuwa album z listy, dzieki funkcji action_delete_album().
*   Przypadek 3 wyswietla albumy, dzieki funkcji action_print_list().
*   Przypadek 4 zapisuje albumy do pliku, dzieki funkcji  action_save_list().
*   Przypadek 5 odczytuje albumy z pliku, dzieki funkcji action_read_from_file().
*   Przypadek 6 edytuje albumy, dzieki funkcji action_album_edit().
*   Przypadek 7 sortuje albumy, dzieki funkcji action_show_sorted().
*   Przypadek 8 umozliwia dodanie np. kilku artystow do jednego albumy, dzieki funkcji artist_m().
*   Przypadek 9 konczy program, dzieki funkcji action_end_program().
*   Funkcje  system("cls"), puts(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/

void startAction(char menuChoice,Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id,ID_TYPE_type **hhead,TYPE_type **hhhead){
	switch (menuChoice){
            case '1':
            	action_add_album(head,id);
                break;
            case '2':
            	action_delete_album(&(*head),&(*hhead),&(*headd));
                break;
            case '3':
            	action_print_list(*hhhead,*hhead,*head,*headd,*headdd);
                break;
            case '4':
                action_save_list(*hhhead,*hhead,*head,*headd,*headdd);
                break;
            case '5':
            	action_read_from_file(hhhead,hhead,head,headd,headdd,id);
                break;
            case '6':
            	action_album_edit(head);
                break;
            case '7':
            	action_show_sorted(*head);
            	break;
            case '8':
                artist_m(*head,&(*headd),&(*headdd),&(*hhead),&(*hhhead));
                break;

		case '0':
            action_end_program(*hhhead,*hhead,*head,*headd,*headdd);
			break;

        default:
		{
            puts("Blad! podaj jeszcze raz!");
            Sleep(1000);
            system("cls");
			break;
		}
	}

}
/** Funkcja odpowiada za dodawanie albumu do listy.
*   Przyjmuje dwa parametry.
*   \param[in,out] Music_album_type **head podwojny wskaznik struktury Music_album
*   \param[in,out] int* id wskaznik zmiennej id
*   Umozliwia dodanie dwuczlonowych nazw.
*   W polach przesluchany i zakupiony, wprowadzono wartosc domyslna [T].
*   Dzieki konstrukcji switch() wyeliminowano koniecznosc wpisywania fraz tak/nie, wystarcza pierwsze litery tych wyrazow.
*   Funkcje system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/

void action_add_album(Music_album_type **head,int* id)
{
    system("cls");
	printf("Dodawanie albumu.");
    Sleep(500);
    system("cls");
    int i=0;
    char artist[100];
	char type[100];
	char title[100];
	char state[100];
	char heard[100];
	int year;
	char st;
	char he;
	char a='a';
    system("cls");
    //getchar();
    printf("Artysta: ");
    scanf("%[^\n]",artist);
    getchar();
    printf("Gatunek: ");
    scanf("%[^\n]",type);
    getchar();
    printf("Tytul: ");
    scanf("%[^\n]",title);
    getchar();
    printf("Zakupiony([T]/N): ");
    st=getch();
    switch(st){
        case 'T':
            strcpy(state,"Tak");
            break;
        case 't':
            strcpy(state,"Tak");
            break;
        case 'N':
            strcpy(state,"Nie");
            break;
        case 'n':
            strcpy(state,"Nie");
            break;
        default:
            strcpy(state,"Tak");
            break;

    }
    printf("\nPrzesluchany:([T]/N): ");
    he=getch();
    switch(he){
        case 'T':
            strcpy(heard,"Tak");
            break;
        case 't':
            strcpy(heard,"Tak");
            break;
        case 'N':
            strcpy(heard,"Nie");
            break;
        case 'n':
            strcpy(heard,"Nie");
            break;
        default:
            strcpy(heard,"Tak");
            break;
    }
    printf("\nPodaj rok albumu: ");
    scanf("%d",&year);
    add_node(head,artist,type,title,state,heard,year,id);
    system("cls");
    printf("Album zostal pomyslnie dodany, wracanie do menu.");
    getchar();
    Sleep(500);
    system("cls");
}
/** Funkcja odpowiada za usuwanie albumu z listy.
*   Przyjmuje trzy parametry.
*   \param[in,out] Music_album_type **head podwojny wskaznik struktury Music_album
*   \param[in,out] ID_TYPE_type **hhead podwojny wskaznik struktury ID_TYPE
*   \param[in,out] ID_ARTIST_type **headd podwojny wskaznik struktury ID_ARTIST
*   Umo¿liwia usuwanie albumu po ID, dzieki funkcji delete_node_by_index().
*   Funkcje system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void action_delete_album(Music_album_type **head,ID_TYPE_type **hhead,ID_ARTIST_type **headd)
{
    Music_album_type *current=*head;
    system("cls");
	printf("Usuwanie albumu.");
	Sleep(500);
	system("cls");
    int index;
    system("cls");
    while(current != NULL)
        {
            printf("ID: %d\n",current->id);
            printf("Artysta: %s\n",current->artist);
            current=current->next;
        }
    printf("Wpisz ID albumu, ktory chcesz usunac: ");
    scanf("%d",&index);
    delete_node_by_index(&(*head),&(*hhead), &(*headd),index);
    system("cls");
}
/** Funkcja odpowiada za wyswietlanie albumow
*   Przyjmuje piec parametrow.
*   \param[in,out] TYPE_type *hhhead,  wskaznik struktury TYPE
*   \param[in,out] ID_TYPE_type *hhead  wskaznik struktury ID_TYPE
*   \param[in,out] Music_album_type **head  wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type *headdd wskaznik struktury ARTIST
*   Zawiera funkcje show_album(), dzieki ktorej mozliwe jest wyswietlanie.
*   Funkcje getch(), system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void action_print_list(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd){
    system("cls");
	printf("Wyswietlanie albumu.");
	Sleep(500);
    system("cls");
    show_album(&(*hhhead),&(*hhead),&(*head),&(*headd),&(*headdd));
    printf("Aby powrocic do menu nacisnij Enter.");
    getch();
    system("cls");
    printf("Powracanie do menu");
    Sleep(500);
    system("cls");
}

/** Funkcja odpowiada za zapisywanie albumow
*   Przyjmuje piec parametrow.
*   \param[in,out] TYPE_type *hhhead,  wskaznik struktury TYPE
*   \param[in,out] ID_TYPE_type *hhead  wskaznik struktury ID_TYPE
*   \param[in,out] Music_album_type **head  wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type *headdd wskaznik struktury ARTIST
*   Zawiera funkcje save() i save_csv dzieki ktorym mozliwe jest zapisywanie do plikow .txt i .csv.
*   Funkcje system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void action_save_list(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd)
{
    system("cls");
	printf("Zapisywanie albumow do pliku txt i csv.");
    Sleep(500);
    system("cls");
    save(hhhead,hhead,head,headd,headdd);
    save_csv(hhhead,hhead,head,headd,headdd);
    printf("Albumy zostaly pomyslnie zapisane.");
    Sleep(500);
    system("cls");
    printf("Powracanie do menu");
    Sleep(500);
    system("cls");
}
/** Funkcja odpowiada za odczytywanie albumow z pliku
*   Przyjmuje szesc parametrow.
*   \param[in,out] TYPE_type *hhhead, podwojny wskaznik struktury TYPE
*   \param[in,out] ID_TYPE_type *hhead  podwojny wskaznik struktury ID_TYPE
*   \param[in,out] Music_album_type **head  podwojny wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd podwojny wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type *headdd podwojny wskaznik struktury ARTIST
*   \param[in,out] int* id podwojny wskaznik zmiennej id
*   Zawiera funkcje Read(), dzieki ktorej mozliwe jest odczytywanie danych z pliku.
*   Funkcje system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void action_read_from_file(TYPE_type **hhhead, ID_TYPE_type **hhead,Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id)
{
	system("cls");
	printf("Wczytywanie z pliku.");
    Sleep(500);
    system("cls");
    Read(hhhead,hhead,head,headd,headdd,id);
    printf("Pomyslnie wczytano");
    Sleep(500);
    system("cls");
    printf("Powracanie do menu");
    Sleep(500);
    system("cls");
}
/** Funkcja odpowiada za edycje albumow.
*   Przyjmuje jeden parametr.
*   \param[in,out] Music_album_type **head podwojny wskaznik struktury Music_album
*   Zawiera funkcje edit_album(), dzieki ktorej mozliwa jest edycja albumow
*   Funkcje system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void action_album_edit(Music_album_type **head)
{
    system("cls");
	printf("Edycja albumu.");
    Sleep(500);
    system("cls");
    edit_album(head);
}

/** Funkcja odpowiada za sortowanie albumow.
*   Przyjmuje jeden parametr.
*   \param[in,out] Music_album_type *head wskaznik struktury Music_album
*   Dzieki funkcjom  show_sorting_menu_options(), rewrite_pointers_to_array(), qsort(), getch() i kontrukcji switch(), mozliwe jest sortowanie po dowolnym polu, rosnaco/malejaco.
*   Funkcje getch(), run_main_loop(), system("cls") printf(), puts(), Sleep()  implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*
*/

void action_show_sorted(Music_album_type *head){
    system("cls");
    printf("Sortowanie.");
    Sleep(500);
    system("cls");
	printf("Opcje sortowania\n");
    char sortingFieldMenuChoice;
    char sortingDirectionMenuChoice;
	show_sorting_menu_options();
	printf("Twoj wybor: ");
    sortingFieldMenuChoice=getch();

    Music_album_type* tab[count_albums(head)];
	rewrite_pointers_to_array(tab,head);

	void (*printFunction)(Music_album_type** , int);
	int (*sortMethod)( const void *, const void * );
	printFunction=&print_array_artist;
	sortMethod=sortByArtistDesc;
    switch (sortingFieldMenuChoice){
     	case '1':{
     	    system("cls");
     		printf("Wybierz opcje sortowania\n\n");
     		puts("1.Sortowanie artysty malejaco");
     		puts("2.Sortowanie artysty rosnaco\n\nTwoj wybor: ");
     		sortingDirectionMenuChoice=getch();
            system("cls");
     		switch(sortingDirectionMenuChoice)
     		{
     			printFunction=&print_array_artist;
     			case '1':{
     				sortMethod= sortByArtistDesc;
					puts("Po posortowaniu Artist malejaco:");

                    }
					break;

				 case '2':{
				 		sortMethod=sortByArtistAsc;
						puts("Po posortowaniu Artist rosnaco:");
				 }
					break;
					 }
     	}

			break;

     	case '2':{
     		system("cls");
     		printf("Wybierz opcje sortowania\n\n");
     		puts("1.Sortowanie gatunku malejaco");
     		puts("2.Sortowanie gatunku rosnaco\n\nTwoj wybor: ");
     		sortingDirectionMenuChoice=getch();
     		system("cls");
     		printFunction=&print_array_type;

     		switch(sortingDirectionMenuChoice)
     		{

     			case '1':{
     					sortMethod=sortByTypeDesc;
						puts("Po posortowaniu gatunku malejaco:");

					break;
				 }
				 case '2':{
				 		sortMethod=sortByTypeAsc;
						puts("Po posortowaniu Gatunku rosnaco:");
					break;
				}
			}
			break;
     	}
     	case '3':{
     		system("cls");
     		printf("Wybierz opcje sortowania\n\n");
     		puts("1.Sortowanie tytulu malejaco");
     		puts("2.Sortowanie tytulu rosnaco\n\nTwoj wybor: ");
     		sortingDirectionMenuChoice=getch();
     		system("cls");
     		printFunction=&print_array_title;

     		switch(sortingDirectionMenuChoice)
     		{

     			case '1':{
     					sortMethod=sortByTitleDesc;
						puts("Po posortowaniu tytulu malejaco:");
					break;
				 }
				 case '2':{
				 		sortMethod=sortByTitleAsc;
						puts("Po posortowaniu tytulu rosnaco:");

					break;
				}
			}
			break;
     	}
		case '4':{
     		system("cls");
     		printf("Wybierz opcje sortowania\n\n");
     		puts("1.Sortowanie ID malejaco");
     		puts("2.Sortowanie ID rosnaco\n\nTwoj wybor: ");
     		sortingDirectionMenuChoice=getch();
     		system("cls");
     		printFunction=&print_array_id;

     		switch(sortingDirectionMenuChoice)
     		{

     			case '1':{
     					sortMethod=sortByIdDesc;
						puts("Po posortowaniu ID malejaco:");
					break;
				 }
				 case '2':{
				 		sortMethod=sortByIdAsc;
						puts("Po posortowaniu ID rosnaco:");
					break;
				}
			}
			break;
     	}
     	case '5':{
     		system("cls");
     		printf("Wybierz opcje sortowania\n\n");
     		puts("1.Sortowanie roku roku malejaco");
     		puts("2.Sortowanie roku rosnaco\n\nTwoj wybor: ");
     		sortingDirectionMenuChoice=getch();
     		system("cls");
     		printFunction=&print_array_year;
     		switch(sortingDirectionMenuChoice)
     		{

     			case '1':{
     					sortMethod=sortByYearDesc;
						puts("Po posortowaniu roku malejaco:");
					break;
				 }
				 case '2':{
				 		sortMethod=sortByYearAsc;
						puts("Po posortowaniu roku rosnaco:");
					break;
				}
			}
			break;
     	}

        case '0':
            system("cls");
            printf("Powrot do menu.");
            Sleep(500);
            system("cls");
            run_main_loop();
            break;


     	default:{
     		puts("blad! standardsowe sortowanie!");
			break;
		 }
	}
	qsort(tab,count_albums(head),sizeof(struct Music_album*),sortMethod);
	(*printFunction)(tab,count_albums(head));
	printf("Nacisnij ENTER aby powrocic do menu.");
    getch();
    system("cls");
}
/** Funkcja odpowiada za konczenie dzialania programu
*   Przyjmuje piec parametrow.
*   \param[in,out] TYPE_type *hhhead,  wskaznik struktury TYPE
*   \param[in,out] ID_TYPE_type *hhead  wskaznik struktury ID_TYPE
*   \param[in,out] Music_album_type **head  wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type *headdd wskaznik struktury ARTIST
*   Zawiera funkcje save(), save_csv(), ktore umozliwiaja zapis danych bezposrednio przed zamknieciem programu.
*   Dzieki konstrukcji switch() wyeliminowano koniecznosc wpisywania fraz tak/nie, wystarcza pierwsze litery tych wyrazow.
*   Funkcje getch(), system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*   Po przejsciu opisywanej funkcji program konczy dzialanie, odpowiada za to exit(0).
*/
void action_end_program(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd)
{
    system("cls");
    puts("Koniec programu!");
    Sleep(500);
    system("cls");
    char choice;
    printf("Czy chcesz zapisac zmiany? [T]/N\nTwoj wybor: ");
    choice=getch();
    system("cls");
    switch(choice){
    case 'T':
        save(hhhead,hhead,head,headd,headdd);
        save_csv(hhhead,hhead,head,headd,headdd);
        printf("Zapisano, program konczy dzialanie.");
        Sleep(500);
        break;
      case 't':
        save(hhhead,hhead,head,headd,headdd);
        save_csv(hhhead,hhead,head,headd,headdd);
        printf("Zapisano, program konczy dzialanie.");
        Sleep(500);
        break;
    case 'N':
        printf("Program konczy dzialanie.");
        Sleep(500);
        break;
        case 'n':
        printf("Program konczy dzialanie.");
        Sleep(500);
    break;
    default:
        printf("Zapisano, program konczy dzialanie.");
        Sleep(500);
        save(hhhead,hhead,head,headd,headdd);
        break;
    }
    system("cls");
    exit(0);
}

/**Funkcja dzieki printf() wyswietla interfes menu, w funkcji odpowiadajacej za sortowanie*/
void show_sorting_menu_options()
{
	printf("Menu (wybierz numer odpowiedni dla opcji)\n");
	printf("1.Sortowanie Artysty\n");
	printf("2.Sortowanie Gatunku\n");
	printf("3.Sortowanie Tytulu\n");
	printf("4.Sortowanie ID\n");
	printf("5.Sortowanie Roku\n");
	printf("0.Powrot do menu\n\n");
}

/** Funkcja odpowiada za modyfikacje pozycji, w okreslonych polach
*   Przyjmuje piec parametrow.
*   \param[in,out] Music_album_type **head  wskaznik struktury Music_album
*   \param[in,out] ID_ARTIST_type **headd wskaznik struktury ID_ARTIST
*   \param[in,out] ARTIST_type *headdd wskaznik struktury ARTIST
*   \param[in,out] ID_TYPE_type *hhead  wskaznik struktury ID_TYPE
*   \param[in,out] TYPE_type *hhhead,  wskaznik struktury TYPE
*   Zawiera funkcje add_artist(), delete_artist(),add_type(), delete_type(), modify_artist(), modify_type, ktore umozliwiaja modyfikacje.
*   Dzieki konstrukcji switch(), petli do..while i funkcji getch() mozliwe jest wybieranie odpowiedniej opcji modyfikacji.
*   Funkcje getch(), system("cls") printf(), Sleep() implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*   Funkcje system("cls"), printf(), puts(), Sleep()  implementowane w odpowiedniuch miejscach kodu, odpowiadaja za wygodna obsluge programu.
*/
void artist_m(Music_album_type *head,ID_ARTIST_type **headd,ARTIST_type **headdd,ID_TYPE_type **hhead,TYPE_type **hhhead)
{
    int a;
    do
    {
        system("cls");
        puts("[1]Dodawanie artysty do albumu");
        puts("[2]Usuwanie artysty z albumu");
        puts("[3]Dodawanie gatunku do albumu");
        puts("[4]Usuwanie gatunku z albumu");
        puts("[5]Modyfikowanie listy artystow");
        puts("[6]Modyfikowanie listy gatunkow");
        puts("[0]Powrot do menu");
        a=getch();
        switch(a)
        {
        case '1':
            system("cls");
            add_artist(&head,&(*headd),*headdd);
            break;
        case '2':
            system("cls");
            delete_artist(&head,&(*headd),*headdd);
            break;
        case '3':
            system("cls");
            add_type(&head,&(*hhead),*hhhead);
            break;
        case '4':
            system("cls");
            delete_type(&head,&(*hhead),*hhhead);
            break;
        case '5':
            system("cls");
            modify_artist(&(*headdd));
            break;
        case '6':
            system("cls");
            modify_type(&(*hhhead));
            break;
        case '0':
            puts("Powrot");
            Sleep(1000);
            system("cls");
            break;
        default:
            puts("Podano bledna wartosc");
            system("cls");
        }
    }
    while(a!='0');

}

