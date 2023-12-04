#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

List Read(); /* details omitted */
void Print( List L ); /* details omitted */
List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */
List Reverse( List L ){
    if (L == NULL || L->Next == NULL) {
        return L;
    };

    List Cur = L->Next;
    List Res = NULL;

    while(Cur != NULL){
        List Temp = Cur->Next;
        Cur->Next = Res;
        Res = Cur;
        Cur = Temp;
    };

     L->Next = Res;

    return L;
}