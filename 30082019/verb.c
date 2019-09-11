#include <stdio.h>
#include <stdlib.h>
#include "verb.h"

Verb VerbNew()
{
    Verb v;

    char *id;
    char *description;
    VerbReq *request;
    VerbRep *reply;

    v.id = id;
    v.description = description;
    v.request = request;
    v.reply = reply;

    return v;
}

Verb VerbFill(char *id, char *description, VerbReq *vrq, VerbRep *vrp)
{
    Verb v;

    v.id = id;
    v.description = description;
    v.request = vrq;
    v.reply = vrp;

    return v;
}

ListOfVerb *VerbListInit(int SizeOfList)
{
    ListOfVerb *list = NULL;

    for (int counter = 0; counter < 6; counter++)
    {
        ListOfVerb *node = malloc(sizeof(*node));
        node->verb = VerbNew();
        node->next = list;
        list = node;
    }

    return list;
}

ListOfVerb *VerbListFill(ListOfVerb *LOV)
{
    //run the list then fill it by the user
}

void VerbPrint(Verb V)
{
    printf("TODO - print verb");
    /*TODO*/
}