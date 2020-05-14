///////////////////////////////////////

#include "sorting.h"



/**
*   Funkcja sprawdza ile albumów znajduje sie w bazie
*   \param[in,out] Music_album *Music_album_type wskaznik struktury Music_album
*   Zwraca ilosc albumow
*/
int count_albums(struct Music_album* Music_album_type){
	int count=0;

	for(;Music_album_type;count++,Music_album_type=Music_album_type->next);
	return count;
}

/**
*   Funkcja przepisuje wskazniki do tablicy
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in,out] Music_album *head wskaznik struktury Music_album
*/
void rewrite_pointers_to_array(struct Music_album* tab[], struct Music_album* head){

	int i=0;
	while(head)
	{
		tab[i]=head;
		head=head->next;
		i++;
	}
}
/**
*   Funkcja wyswietla posortowany Gatunek
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in] n-ilosc elementow
*/
void print_array_type(struct Music_album* tab[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %s %s %d  ID%d\n",tab[i]->type,tab[i]->title,tab[i]->artist,tab[i]->year,tab[i]->id);

	}
}
/**
*   Funkcja wyswietla posortowany Tytul
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in] n-ilosc elementow
*/
void print_array_title(struct Music_album* tab[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %s %s %d  ID%d\n",tab[i]->title,tab[i]->type,tab[i]->artist,tab[i]->year,tab[i]->id);

	}
}
/**
*   Funkcja wyswietla posortowanego Artyste
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in] n-ilosc elementow
*/
void print_array_artist(struct Music_album* tab[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %s %s  %d  ID%d\n",tab[i]->artist,tab[i]->title,tab[i]->type,tab[i]->year,tab[i]->id);
	}
}

/**
*   Funkcja wyswietla posortowane ID
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in] n-ilosc elementow
*/
void print_array_id(struct Music_album* tab[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("ID%d %s %s %s %d\n",tab[i]->id,tab[i]->artist,tab[i]->title,tab[i]->type,tab[i]->year);

	}
}

/**
*   Funkcja wyswietla posortowany Rok
*   \param[in,out] Music_album *tab[] wskaznik tablicy
*   \param[in] n-ilosc elementow
*/
void print_array_year(struct Music_album* tab[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d %s %s %s  ID%d\n",tab[i]->year,tab[i]->artist,tab[i]->title,tab[i]->type,tab[i]->id);

	}
}

/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy malejaco
*/
int sortByTypeDesc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return -strcmp((*_arg3)->type,(*_arg4)->type);

}
/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy rosnaco
*/
int sortByTypeAsc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return strcmp((*_arg3)->type,(*_arg4)->type);
}
/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy malejaco
*/
int sortByTitleDesc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return -strcmp((*_arg3)->title,(*_arg4)->title);

}
/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy rosnaco
*/
int sortByTitleAsc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return strcmp((*_arg3)->title,(*_arg4)->title);
}
/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy malejaco
*/
int sortByArtistDesc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return -strcmp((*_arg3)->artist,(*_arg4)->artist);

}
/**
*   Funkcja porównuje elementy tablicy typu char oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg3 i void arg4 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy rosnaco
*/
int sortByArtistAsc( const void * arg3, const void * arg4 )
{
	struct Music_album ** _arg3 = (struct Music_album **)arg3;
	struct Music_album ** _arg4 = (struct Music_album **)arg4;
	return strcmp((*_arg3)->artist,(*_arg4)->artist);
}
/**
*   Funkcja porównuje elementy tablicy typu int oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg1 i void arg2 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy rosnaco
*/
int sortByIdAsc( const void * arg1, const void * arg2 )
{
	struct Music_album ** _arg1 = (struct Music_album **)arg1;
	struct Music_album ** _arg2 = (struct Music_album **)arg2;
	return (*_arg1)->id>(*_arg2)->id;
}
/**
*   Funkcja porównuje elementy tablicy typu int oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg1 i void arg2 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy malejaco
*/
int sortByIdDesc( const void * arg1, const void * arg2 )
{
	struct Music_album ** _arg1 = (struct Music_album **)arg1;
	struct Music_album ** _arg2 = (struct Music_album **)arg2;
	return (*_arg1)->id<(*_arg2)->id;
}
/**
*   Funkcja porównuje elementy tablicy typu int oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg1 i void arg2 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy rosnaco
*/
int sortByYearAsc( const void * arg1, const void * arg2 )
{
	struct Music_album ** _arg1 = (struct Music_album **)arg1;
	struct Music_album ** _arg2 = (struct Music_album **)arg2;
	return (*_arg1)->year>(*_arg2)->year;
}
/**
*   Funkcja porównuje elementy tablicy typu int oraz ilustruje sposób wywołania qsort() dla tej tablicy.
*   \param[in,out] void* arg1 i void arg2 to wskaznik na obszar pamieci czyli po prostu adres
*   Funkcja zwraca elementy malejaco
*/
int sortByYearDesc( const void * arg1, const void * arg2 )
{
	struct Music_album ** _arg1 = (struct Music_album **)arg1;
	struct Music_album ** _arg2 = (struct Music_album **)arg2;
	return (*_arg1)->year<(*_arg2)->year;
}

