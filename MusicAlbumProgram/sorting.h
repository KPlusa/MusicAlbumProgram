#ifndef SORTING_H
#define SORTING_H

#include "structures.h"

// ile albumow w bazie
int count_albums(struct Music_album* Music_album_type);
//przepisywanie wskaünikow do tablicy
void rewrite_pointers_to_array(struct Music_album* tab[], struct Music_album* );
//sortowanie gatunku malejaco
int sortByTypeDesc( const void * arg3, const void * arg4 );
//sortowanie gatunku rosnaco
int sortByTypeAsc( const void * arg3, const void * arg4 );
//wyswietlanie posortowanego type
void print_array_type(struct Music_album* tab[],int n);
//sortowanie tytulu malejaco
int sortByTitleDesc( const void * arg3, const void * arg4 );
//sortowanie tytulu rosnaco
int sortByTitleAsc( const void * arg3, const void * arg4 );
//wyswietlanie posortowanego title
void print_array_title(struct Music_album* tab[],int n);
//sortowanie artysty malejaco
int sortByArtistDesc( const void * arg3, const void * arg4 );
//sortowanie artysty rosnaco
int sortByArtistAsc( const void * arg3, const void * arg4 );
//wyswietlanie posortowanego artist
void print_array_artist(struct Music_album* tab[],int n);
//sortowanie ID rosaco
int sortByIdAsc( const void * arg1, const void * arg2 );
//sortowanie ID malejaco
int sortByIdDesc( const void * arg1, const void * arg2 );
//wyswietlanie posortowanego id
void print_array_id(struct Music_album* tab[],int n);
//sortowanie YEAR rosaco
int sortByYearAsc( const void * arg1, const void * arg2 );
//sortowanie YEAR malejaco
int sortByYearDesc( const void * arg1, const void * arg2 );
//wyswietlanie posortowanego year
void print_array_year(struct Music_album* tab[],int n);

#endif
