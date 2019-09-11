#include <stdio.h>
#ifndef VERB_H
#define VERB_H

typedef struct
{
    char *id;
    char *name;
    char req_code_list[];
} VerbReq;

typedef struct
{
    char *id;
    char *message_success;
} VerbRep;

typedef struct
{
    char *id;
    char *description;
    VerbReq *request;
    VerbRep *reply;
} Verb;

typedef struct ListOfVerb
{
    Verb verb;
    struct ListOfVerb *next;
} ListOfVerb;

Verb VerbNew();
Verb VerbFill(char *id, char *description, VerbReq *vrq, VerbRep *vrp);
ListOfVerb *VerbListInit(int SizeOfList);
ListOfVerb *VerbListFill(ListOfVerb *LOV); //TODO
void VerbPrint(Verb V);                    //TODO

#endif