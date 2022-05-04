//
// Created by eii on 07/04/2022.
//

#ifndef ESCAPEGAMEPROJECT_MAIN_MODEL_H
#define ESCAPEGAMEPROJECT_MAIN_MODEL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SCREEN_W 1851
#define SCREEN_H 1040

typedef struct frame frame;
typedef struct Room Room;

typedef struct Object Object;
typedef struct Door Door;
typedef struct Personage Personage;

typedef struct Edge Edge;
typedef struct EdgeList EdgeList;
typedef struct Vertex Vertex;
typedef struct VertexList VertexList;
/**
 * definition des objets
 */
struct Object{
    char * id;
    int j;
    int i;
    char * file_name;
};


struct Door{
    char * id;
    int i;
    int j;
    char * file_name;
    int access;
};

Object * createObject(char * id, int x, int y, char * file_name);
Door * createDoor(char * id, int x, int y, char * file_name);
void changeAccess(Door *D);

void freeObject(Object *o);
void freeDoor(Door * D);


/***
 * definition Frame
 */

struct frame{
    int Pos_x; //position height
    int Pos_y; //position Width
    Object * o; //=NULL par defaut
    Door * d;
};
struct Room{
    int h;
    int w; //taille de la case
    int nb_j;
    int nb_i;
    char * name;
    char * filename;
    frame ** framing;
};

int getDimension(int a,int b);
//Create Room
Room * CreateRoom();
//Create Framing
frame ** CreateFraming();
void printFraming(frame ** tab);

//delete Framing
void deleteFraming(frame ** tab);
void deleteRoom(Room * R);

/**
 * definition Personnage
 */
struct Personage {
    int x_position;
    int y_position;
};

Personage * CreatePersonage();
void DeletePersonage(Personage * p);

void move_up(Personage * p, int n);
void move_down(Personage * p, int n);
void move_left(Personage * p, int n);
void move_right(Personage * p, int n);

/**
 * definition des graph
 * Graph : "Machine d'état" du scénario
 * EdgeList: liste de lien entre le Vertex et ses successeurs
 */
/*
 * Structures
 */
struct Edge{
    char * obj_label;
    Vertex *v_next;
    struct Edge *next_e;
};
struct EdgeList{
    Edge *first;
    Edge *current;
    Edge *last;
};

/*
 * Fonction Gestion de Liste Edge List
 */
void initEdgeList(EdgeList * c);
int isEmptyEdgeList(EdgeList * c);
void insertFirstEdge(EdgeList *c, char *obj, Vertex * v);
void insertLastEdge(EdgeList *c, char *obj, Vertex * v);

/*
 * "travel in the List"
 */
void setOnFirstEdge(EdgeList *c);
void setOnLastEdge(EdgeList *c);
void setOnNextEdge(EdgeList *c);
Edge * findEdge(EdgeList *c, char *obj);
/*
 * Print Edge List
 */
void printEdgeList(EdgeList *c);

/*
 * Delete Edge
 */
void deleteFirstEdge(EdgeList *c);
void deleteEdgeList(EdgeList * c);



/**
 * VertexList: liste de vertex
 */

/*
 * Structures
 */
struct Vertex{
    char * label;
    EdgeList * connect;//vide de base
    int enigma_number;
    Vertex * next_v;
    int enigma_solved; //à 0 de base
};
struct VertexList{
    Vertex *first;
    Vertex *current;
    Vertex *last;
};
/*
 * Fonction Gestion de Liste Edge List
 */
void initGraph(VertexList * g);
int isEmptyVertexList(VertexList * g);
void insertFirstVertex(VertexList * g,char * label,int enigma_number);
void insertLastVertex(VertexList * g,char * label,int enigma_number);
void addLink(Vertex * v1, Vertex * v2, char * obj_label);

/*
 * "travel in the List"
 */
void setOnFirstVertex(VertexList * g);
void setOnLastVertex(VertexList * g);
void setOnNextVertex(VertexList * g);
Vertex * findVertex(VertexList * g,char * label);
/*
 * Print Edge List
 */
void printGraph(VertexList * g);

/*
 * Delete Edge
 */
void deleteFirstVertex(VertexList * g);
void deleteGraph(VertexList * g);

/**
 * State Change
 * Notre graph s'apparente à uns machine d'état
 * quand on résout les énigmes de l'étape on change d'état
 */

int changeState(VertexList * g,Object * o);
int SolvedEnigma(VertexList * g, Object *o);


#endif //ESCAPEGAMEPROJECT_MAIN_MODEL_H
