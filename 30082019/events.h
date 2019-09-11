#include <stdio.h>
#ifndef EVENTS_H
#define EVENTS_H

typedef struct
{
    char *id;
    char *AllowedServices;
    char **currentstate;
} Permissions;

typedef struct
{
    char *name;
    char *id;
    Permissions *EvSchemaPermission;
} EventSchema;

typedef struct
{
    char *name;
    char *id;
    EventSchema *EventSchema;
} Event;

typedef struct ListOfEvents
{
    Event event;
    struct ListOfEvents *next;
} ListOfEvents;

Event EventNew();
Event EventFill(char *name, char *id, EventSchema *EventSchema);
ListOfEvents *EventListInit(int SizeOfList);
ListOfEvents *EventListFill(ListOfEvents *LOE); //TODO
void EventPrint(Event E);                       //TODO

#endif