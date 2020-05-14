#ifndef STRUCTURES_H
#define STRUCTURES_H
/** Zalaczone biblioteki */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
/** Glowna struktura albumow */
typedef struct  Music_album{
    char artist[100];
    char type[100];
    char title[100];
    char state[100];
    char heard[100];
    int year;
    int id;
    struct Music_album *next;
}Music_album_type;
/** Struktura laczaca pole ID z polem Artsyta */
typedef struct ID_ARTIST
{
    int id;
    int id_art;
    struct ID_ARTIST *next;
}ID_ARTIST_type;
/** Struktura przechowujaca artystow */
typedef struct ARTIST_a
{
    int id_art;
    char artist[100];
    struct ARTIST_a *next;
}ARTIST_type;
/** Struktura laczaca pole ID z polem Gatunek */
typedef struct ID_TYPE
{
    int id;
    int id_type;
    struct ID_TYPE *next;
}ID_TYPE_type;
/** Struktura przechowujaca gatunki */
typedef struct TYPE_a
{
    int id_type;
    char type[100];
    struct TYPE_a *next;
}TYPE_type;
/** Funkcja odpowiadajaca za dodawanie albumow*/
void add_node(Music_album_type **head,char *artist,char *type,char *title,char *state,char *heard, int year,int* id);
/** Funkcja odpowiadajaca za wyswietlanie albumow*/
void show_album(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);//mod
/** Funkcja pomocnicza odpowiadajaca za usuwanie pierwszego albumu*/
void delete_first(Music_album_type **head);
/** Funkcja odpowiadajaca za usuwanie wszystkich albumow*/
void delete_all(Music_album_type **head,int* id);
/** Funkcja odpowiadajaca za usuwanie albumow po ID*/
void delete_node_by_index(Music_album_type **head,ID_TYPE_type **hhead,ID_ARTIST_type **headd, int index);
/** Funkcja odpowiadajaca za zapis danych do pliku*/
void save(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);//mod
/** Funkcja odpowiadajaca za odczyt danych z pliku*/
void Read(TYPE_type **hhhead, ID_TYPE_type **hhead,Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id);//mod
/** Funkcja edytujaca albumy */
void edit_album(Music_album_type **head);
/** Funkcja odpowiadajaca za dodanie artysty*/
void add_artist(Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type *headdd);
/** Funkcja odpowiadajaca za usuwanie artysty*/
void delete_artist(Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type *headdd);
/** Funkcja odpowiadajaca za modyfikacje artysty*/
void modify_artist(ARTIST_type **headdd);
/** Funkcja odpowiadajaca za zapis danych do pliku .csv*/
void save_csv(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);
/** Funkcja odpowiadajaca za dodanie gatunku*/
void add_type(Music_album_type **head,ID_TYPE_type **hhead,TYPE_type *hhheaad);
/** Funkcja odpowiadajaca za usuwanie gatunku*/
void delete_type(Music_album_type **head,ID_TYPE_type **hhead,TYPE_type *hhheaad);
/** Funkcja odpowiadajaca za modyfikacje gatunku*/
void modify_type(TYPE_type **hhheaad);
/** Funkcja usuwajaca struktury */
void delete_structures(TYPE_type **hhhead, ID_TYPE_type **hhead,Music_album_type **head, ID_ARTIST_type **headd, ARTIST_type **headdd);

#endif

