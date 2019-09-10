#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * Author: Mahmoud Souayfan
 * 
 * TODO:
 *  1) Define structure that define a service (note: function that return the nactual status of a service)
 *  2) Create the function that create a new service
 *  3) Write functions that describe each service status, verbs, transition
 * 
typedef struct
{
    char *name;     //info/apiname
    char *description; //info/description
} service;
typedef struct
{
    char * recentstate;
    char * actualstate;
    char * futurstate;
} states;

typedef struct
{
    char *str;
} test;

08/05/2019:
ce fichier est une description d'une service sous AGL, on cherche 
a definir les differentes transition, verbe et evennement d'une
service.

Apres definition des elements de la service, on doit decrire une
algorithme qui gére la transition entre les differente status,
tout en respectant les permission de transition.

1) Definition des elements:
    a) verbe:
    b) status:
2) Etre capable toujours de verifier l'État Actuel d'une service
   et d'aller au status suivant selon les transition possible
3) VUE TERMINAL:
   - Visualisation de: 
        1) Menu (des choix pour le transition)
        2) des infos sur l'etat actuel du service
*/

//Verbs:
typedef struct
{
    char *name;
    char *description;
    char *request;
    char *reply;
} verb;

verb newVerb()
{
    verb Verb;
    Verb.name = "";
    Verb.description = "";
    Verb.request = "";
    Verb.reply = "";
    return Verb;
}

verb define_verb(char *Name, char *Description, char *Request, char *Reply)
{
    verb Verb;
    Verb.name = Name;
    Verb.description = Description;
    Verb.request = Request;
    Verb.reply = Reply;
    return Verb;
}

void printVerb(verb VB)
{
    printf("\"%s\": { //verb\n", VB.name);
    printf("\t \"description\" : \"%s\",\n", VB.description);
    printf("\t \"request\" : \"%s\",\n", VB.request);
    printf("\t \"reply\" : \"%s\"\n", VB.reply);
    printf("\t}\n");
}
//******

//statemachine:
typedef struct
{
    char *name;
    char *action;
    char *success;
    char *failure; //to change to error that have the same status of the actual state
    bool enabled;
} statemachine;

statemachine newState()
{
    statemachine state;
    state.name = "";
    state.action = "";
    state.success = "";
    state.failure = "";
    return state;
}

statemachine define_state(char *name, char *action, char *success, char *failure, bool onoroff)
{
    statemachine state;
    state.name = name;       //the name of the actual status
    state.action = action;   //the action that allow the name to change
    state.success = success; //success and failure describe the next status
    state.failure = failure;
    state.enabled = onoroff;
    return state;
}

void printStatus(statemachine status)
{
    statemachine state;
    state = status;
    printf("\"%s\": { //status\n", state.name);
    printf("\t \"action\" : \"%s\",\n", state.action);
    printf("\t \"success\" : \"%s\",\n", state.success);
    printf("\t \"failure\" : \"%s\"\n", state.failure);
    printf("\t}\n");
}
//******

//permission:
typedef struct
{
    char *objName;
    char *currentstatus;
} permisn;

//SCH_BUTN
typedef struct
{
    char *name;
    char *description;
    char *type;
    char *value;
    permisn permission;
} schbutn;

schbutn new_schbutn()
{
    schbutn schemabutton;
    permisn perm;

    perm.objName = "btn-";
    perm.currentstatus = "cs";

    schemabutton.name = "";
    schemabutton.description = "";
    schemabutton.type = "";
    schemabutton.value = "";
    schemabutton.permission = perm;
    return schemabutton;
}

schbutn define_schbutn(char *name, char *description, char *type, char *value, char *prmCuSt)
{
    schbutn schemabutton;
    permisn perm;

    perm.objName = name;
    perm.currentstatus = prmCuSt;

    schemabutton.name = name;
    schemabutton.description = description;
    schemabutton.type = type;
    schemabutton.value = value;
    schemabutton.permission = perm;

    return schemabutton;
}

void print_schbutn()
{
    printf("hey");
}

//SCH_VERB
typedef struct
{
    char *name;
    char *request;
    char *reply;
} schverb;

typedef struct
{
    char *vname;
    char *success;
    char *failure;
} request;

schverb new_schverb()
{
    schverb verb_schema;
    verb_schema.name = "";
    verb_schema.reply = "";
    verb_schema.request = "";
    return verb_schema;
}

schverb define_schverb(char *name, char *request, char *reply)
{
    schverb verb_schema;
    verb_schema.name = name;
    verb_schema.reply = reply;
    verb_schema.request = request;
    return verb_schema;
}

/**/

int transition(char *actual_state, char *next_state)
{

    /*
    * schema ecrite a main levé:
      (0) Disengaged -> (1) Engaged -> (2.1) Pause - (2.2)(0) Disengaged -> (3.1)(0) Disengaged - (3.2)(1) Engaged
    */

    /*
    * transition between states is based on a request
    * * the request is based on a string that describe 
    *   the next status 
    * * lets give each status a letter: 
    *   status 1: Init / Reinit --> "INIT" --> "0"
    *   status 2: Disengaged    --> "DISE" --> "1"
    *   status 3: Engaged       --> "ENGA" --> "2"
    *   status 4: Paused        --> "PAUS" --> "3"
    * * function return -> 0 or 1 to describe the success or the failure 
    *   of the transition
    */
    //Step 1: In the first moment we have to define the initial state
    //Identification is based on the number of the actual status, and then on the number of the desired status;
    //Step 2: Describe Transition rules

    return 1;
}

int displayMenu(int actualstatus)
{
    int choosenvalue = 100;
    switch (actualstatus)
    {
    case 0:
        printf("Your service is in a \"Disengaged\" status\n");
        printf("To change to \"Engaged\" type the number \'1\':\n");
        scanf("%d", &choosenvalue);
        return choosenvalue;
        break;
    case 1:
        printf("Your service is in a \"Engaged\" status\n");
        printf("To turn back to \"Disengaged\" type the number \'0\';\nif you want to take a \"pause\" type the number \'2\':\n");
        scanf("%d", &choosenvalue);
        return choosenvalue;
        break;
    case 2:
        printf("Your service is in a \"Pause\".\n");
        printf("To turn back to \"Engaged\" type the number \'1\';\nif you want to reset the service type the number \'0\':\n");
        scanf("%d", &choosenvalue);
        return choosenvalue;
        break;
    default:
        return -1;
        break;
    }
}
/**/
int main()
{

    printf("Interpreting service params:\n");

    /* ***          Verb definition          *** */
    verb subscribe = newVerb();
    verb unsubscribe = newVerb();

    subscribe = define_verb("subscribe", "subscribe to test service", "/schemas/subscription", "/schemas/none");
    unsubscribe = define_verb("unsubscribe", "unsubscribe to test service", "/schemas/unsubscription", "schemas/none");
    /* ***          ***************          *** */

    /* ***          machine_state definition          *** */
    statemachine INIT_0 = newState();
    statemachine DISE_1 = newState();
    statemachine ENGA_2 = newState();
    statemachine PAUS_3 = newState();

    INIT_0 = define_state("INIATIAL_DISENGAGED", "subscribe", "Engaged", "Disengaged", true);
    DISE_1 = define_state("DISENGAGED", "subscribe", "Engaged", "Disengaged", false);
    ENGA_2 = define_state("ENGAGED", "unsubscribe | btn-pause", "Disengaged", "Engaged", false);
    PAUS_3 = define_state("PAUSED", "btn-resume", "Engaged", "Paused", false);
    /* ***          ************************          *** */

    /* ***          main_test          *** */
    /*
    printf("\n\n");
    printf("-----Printing machine parameter: \n");
    
    printVerb(subscribe);
    printVerb(unsubscribe);

    printStatus(INIT_0);
    printStatus(DISE_1);
    printStatus(ENGA_2);
    printStatus(PAUS_3);

    printf("-----End Of Printing Parameter");
    printf("\n\n\n");
    */

    /* ***          *********          *** */

    int statusnum = 0;
    while (1)
    {
        int test = displayMenu(statusnum); //listen function
        //printf("%d\n", test);
        if (statusnum == 0 && test == 1) //In Disengaged, going to Engaged; using the action: subscribe
        {
            printf("Transition accepté\nYou are in \"Engaged\"\n");
            printf("Actual status code: ENGA_2.\n");
            statusnum = 1;
        }
        else if (statusnum == 1 && test == 0) //In Engaged, going to Disengaged; Using the action: unsubscribe
        {
            printf("Transition accepté\nYou are in \"Disengaged\"\n");
            printf("Actual status code: DISE_1.\n");
            statusnum = 0;
        }
        else if (statusnum == 1 && test == 2) //In Engaged, going to Pause; Using the action: btn-pause
        {
            printf("Transition accepté\nYou are in \"Pause\"\n");
            printf("Actual status code: PAUS_3.\n");
            statusnum = 2;
        }
        else if (statusnum == 2 && test == 1) //In Pause, going to Engaged; Using the action: btn-resume
        {
            printf("Transition accepté\nYou are in \"Engaged\"\n");
            printf("Actual status code: ENGA_2.\n");
            statusnum = 1;
        }
        else if (statusnum == 2 && test == 0) //In Pause, going to Disengaged; Using the action: unsubscribe
        {
            printf("Transition accepté\nYou are in \"Disengaged\"\n");
            printf("Actual status code: DISE_1.\n");
            statusnum = 0;
        }
        else
        {
            printf("Transition Refused\n");
        }
    }
    return 0;
}