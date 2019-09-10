//VERB:
typedef struct
{
} verb;
verb newVerb();
verb define_verb(char *Name, char *Description, char *Request, char *Reply);
void printVerb(verb VB);

//STATE MACHINE:
typedef struct
{
} statemachine;
statemachine newState();
statemachine define_state(char *name, char *action, char *success, char *failure);
void printStatus(statemachine status);

//SCHEMA & ACTION REP|REQ
//SCH_BUTN
typedef struct
{

} schbutn;

//SCH_VERB
typedef struct
{

} schverb;

int transition(char *actual_state, char *next_state);