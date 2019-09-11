#include <stdio.h>
#include "events.h"

Event EventNew()
{
    Event e;

    char *name;
    char *id;
    EventSchema *EventSchema;

    e.name = name;
    e.id = id;
    e.EventSchema = EventSchema;

    return e;
}

Event EventFill(char *name, char *id, EventSchema *EventSchema)
{
    Event e;

    e.name = name;
    e.id = id;
    e.EventSchema = EventSchema;

    return e;
}

ListOfEvents *EventListInit(int SizeOfList)
{
    ListOfEvents *list = NULL;

    for (int counter = 0; counter < 6; counter++)
    {
        ListOfEvents *node = malloc(sizeof(*node));
        node->event = EventNew();
        node->next = list;
        list = node;
    }

    return list;
}

ListOfEvents *EventListFill(ListOfEvents *LOE)
{
    //TODO
}

void EventPrint(Event E)
{
    //TODO
}