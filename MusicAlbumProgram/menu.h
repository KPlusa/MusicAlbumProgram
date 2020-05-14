#ifndef MENU_H
#define MENU_H
/** Zalacza pliki sorting.h i structures.h */
#include "sorting.h"
#include "structures.h"

/** Glowna funkcja wywolywana w funkcji main() projektu */
void run_main_loop();
/** Funkcja wyswietla na ekran interfejs menu*/
void show_main_options();
/**Funkcja odpowiadajaca za wyswietlanie interfesu menu, w funkcji sortowania*/
void show_sorting_menu_options();
/** Funkcja odpowiadajaca za dzialanie menu programu.*/
void startAction(char menuChoice,Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id,ID_TYPE_type **hhead,TYPE_type **hhhead);
/** Funkcja odpowiadajaca za dodawanie albumu do listy.*/
void action_add_album(Music_album_type **head,int* id);
/** Funkcja odpowiadajaca za usuwanie albumu z listy.*/
void action_delete_album(Music_album_type **head,ID_TYPE_type **hhead,ID_ARTIST_type **headd);
/** Funkcja odpowiadajaca za wyswietlanie albumow*/
void action_print_list(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);
/** Funkcja odpowiadajaca za zapisywanie albumow*/
void action_save_list(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);
/** Funkcja odpowiada za odczytanie albumow z pliku*/
void action_read_from_file(TYPE_type **hhhead, ID_TYPE_type **hhead, Music_album_type **head,ID_ARTIST_type **headd,ARTIST_type **headdd,int* id);
/** Funkcja odpowiadajaca za edycje albumow.*/
void action_album_edit(Music_album_type **head);
/** Funkcja odpowiada za sortowanie albumow.*/
void action_show_sorted(Music_album_type *head);
/** Funkcja odpowiada za konczenie dzialania programu.*/
void action_end_program(TYPE_type *hhhead, ID_TYPE_type *hhead, Music_album_type *head,ID_ARTIST_type *headd,ARTIST_type *headdd);
/** Funkcja odpowiada za modyfikacje pozycji, w okreslonych polach.*/
void artist_m(Music_album_type *head,ID_ARTIST_type **headd,ARTIST_type **headdd,ID_TYPE_type **hhead,TYPE_type **hhhead);
#endif

