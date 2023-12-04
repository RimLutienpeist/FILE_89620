#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node  {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print( Polynomial p ); /* details omitted */
Polynomial Add( Polynomial a, Polynomial b );

int main()
{
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Add( Polynomial a, Polynomial b ){
    Polynomial result = (Polynomial)malloc(sizeof(Polynomial));
    result->Coefficient = 0;
    result->Exponent = 0;
    result->Next = NULL;
    Polynomial p = result;
    int N = 0;

    while(a != NULL && b != NULL){
        if(a->Exponent == b->Exponent){
            if(a->Coefficient + b->Coefficient == 0){
                a = a->Next;
                b = b->Next;
            }else{
                result->Next = a;
                result->Next->Coefficient += b->Coefficient;
                result = result->Next;
                a = a->Next;
                b = b->Next;
                N++;
            };
        }else if(a->Exponent > b->Exponent){
            result->Next = a;
            result = result->Next;
            a = a->Next;
            N++;
        }else if(a->Exponent < b->Exponent){
            result->Next = b;
            result = result->Next;
            b = b->Next;
            N++;
        };
    };

    if(a == NULL){
        while(b != NULL){
            result->Next = b;
            result = result->Next;
            b = b->Next;
            N++;
        };
    }else if(b == NULL){
        while(a != NULL){
            result->Next = a;
            result = result->Next;
            a = a->Next;
            N++;
        };
    };

    if(N == 0){
        p->Next == NULL;
        return p; 
    };

    result->Next = NULL;

    return p;
}

