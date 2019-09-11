#include <stdio.h>
#ifndef STATEMACHINE_H
#define STATEMACHINE_H
/**
 * How a state machine is defined ?
 * 
 */

typedef struct
{
    char *id;
    char *set_state;
    char *message;
} success;

typedef struct
{
    char *name;
    char **action_req_name;
    success *success;
} statemachine;

typedef struct ListOfStates
{
    statemachine state;
    ListOfStates *next;
} ListOfStates;

statemachine StateNew();
statemachine StateDefine(char *name, char *action_req_name, char *success);
ListOfStates *StateListInit(int SizeOfList);
ListOfStates *StateListFill(ListOfStates *LOS); //TODO
void StatePrint(statemachine SM);               //TODO
#endif