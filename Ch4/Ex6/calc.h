#define NUMBER '0'
#define VAR '1'

#define MAX_VAR 26

extern double var[MAX_VAR];
extern char tmp;

void push(double f);
double pop(void);
double head(void);
void swap(void);
void clear(void);
void prints(void);
int getop(char s[]);
int getch(void);
void ungetch(int c);
int assign(char c, double v);
void retrieve(char c);