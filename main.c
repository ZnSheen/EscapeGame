//
// Created by eii on 06/04/2022.
//
#include "./Controller/controller.h"
#include "./View/main_view.h"
#include "./Model/model.h"

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>



int init(){
    return Launch_view();
    //il faudra ajouter ici tout ce qui démarre à l'initialisation du jeu (lecture de fichier par exemple)
}


int main(){
    init();
    return 0;
}

