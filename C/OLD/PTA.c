#include <stdio.h>
#include<stdlib.h>

int calc(char *exp);
int plus(char* q,char* exp);
int division(char * q,char*exp);
int parenthesis(char* q,char* exp);
int negative(char* q,char* exp);
int baifenzhi(char* q,char* exp);

const int LEN = 80;



int main()
{

    while(1){
    char line[LEN] = {0};
    char fmt[LEN] = {0};
            sprintf(fmt, "%%%ds", LEN-1);
        scanf(fmt, line);
        printf("%d\n", calc(line));
    };
}



int calc(char *exp){

    if(*exp == '\0'){
        return 0;
    };

    char *q = exp;

    while(*q != '\0'){
        q++;
    };

    while(*q!='-' && *q!='+' && *q!='*' && *q!='/' && *q!= 'p' && *q!='d' && *q!=')' && *q!='%'&& *q!='y'){
        q--;
/* final */
        if(q == exp){
            return atoi(exp);
        };
    };

/* negative */
    if(*q == '-'){
        char *neg = q;neg--;
        if(*neg == '+' || *neg == '-' || *neg == '*' || *neg == '/' || *neg=='%'){
            return negative(q,exp);
        };
    };


/* plus */
    if(*q == 'p'){
        return plus(q,exp);
    };

/* division */
    if(*q == 'd'){
        return division(q,exp);
    };

/* parenthesis */
    if(*q == ')'){
        return parenthesis(q,exp);
    };

    if(*q == 'y'){
        return baifenzhi(q,exp);
    };

    switch(*q){
        case '+':*q = '\0';return calc(exp) + calc(++q);break;
        case '-':*q = '\0';return calc(exp) - calc(++q);break;
        case '*':*q = 'p';return calc(exp);break;
        case '/':*q = 'd';return calc(exp);break;
        case '%':*q = 'y';return calc(exp);break;
        default:return atoi(exp);
    };
}



int baifenzhi(char* q,char* exp){
    *q = '\0';
    char* pl = ++q;

    while(*q!='-' && *q!='+' && *q!='*' && *q!='/' && *q!= 'p' && *q!='d' && *q!=')' && *q!='%'&& *q!='y'){
        q--;
        if(q == exp){
            return atoi(exp) % atoi(pl) ;
        };
    };

    if(*q != ')'){
            switch(*q){
                case '+':*q = '\0';return calc(exp) + (atoi(++q) % atoi(pl));break;
                case '-':*q = '\0';return calc(exp) - (atoi(++q) % atoi(pl));break;
                case '*':*q = '\0';return calc(exp) * atoi(++q) % atoi(pl);break;
                case '/':*q = '\0';return calc(exp) / atoi(++q) % atoi(pl);break;
                case '%':*q = '\0';return calc(exp) % atoi(++q) % atoi(pl);break;
                default:return atoi(++q);
            };            
    }else{
        return parenthesis(q,exp) / atoi(pl);
    }
}




int negative(char* q,char* exp){
    *q = '\0';
    char* pl = q;
    pl++;
    q--;    

    switch(*q){
        case '+':*q = '\0';return calc(exp) - atoi(pl);break;
        case '-':*q = '\0';return calc(exp) + atoi(pl);break;
        case '*':*q ='\0';return calc(exp) * atoi(pl) * (-1);break;
        case '/':*q ='\0';return calc(exp) / atoi(pl) * (-1);break;
        case '%':*q ='\0';return calc(exp) % (atoi(pl) * (-1));break;
        default:return atoi(exp);
    };            
}



int plus(char* q,char* exp){
        *q = '\0';
        char* pl = ++q;

/* plus final */
        while(*q!='-' && *q!='+' && *q!='*' && *q!='/' && *q!= 'p' && *q!='d' && *q!=')' && *q!='%'&& *q!='y'){
            q--;
            if(q == exp){
                return atoi(exp) * atoi(pl);
            };
        };

        if(*q != ')'){
            int pli = atoi(++q);
            q--;
            switch(*q){
                case '+':*q = '\0';return calc(exp) + atoi(pl) * pli;break;
                case '-':*q = '\0';return calc(exp) - atoi(pl) * pli;break;
                case '*':*q = '\0';return calc(exp) * atoi(pl) * pli;break;
                case '/':*q = '\0';return calc(exp) / pli * atoi(pl);break;
                case '%':*q = '\0';return calc(exp) % pli * atoi(pl);break;
                default:return atoi(++q);
            };            
        }else{
            return parenthesis(q,exp) * atoi(pl);
        };
}



int division(char* q,char* exp){
    *q = '\0';
    char* pl = ++q;

/* division final */
    while(*q!='-' && *q!='+' && *q!='*' && *q!='/' && *q!= 'p' && *q!='d' && *q!=')' && *q!='%'&& *q!='y'){
        q--;
        if(q == exp){
            return atoi(exp) / atoi(pl) ;
        };
    };

    if(*q != ')'){
            switch(*q){
                case '+':*q = '\0';return calc(exp) + (atoi(++q) / atoi(pl));break;
                case '-':*q = '\0';return calc(exp) - (atoi(++q) / atoi(pl));break;
                case '*':*q = '\0';return calc(exp) * atoi(++q) / atoi(pl);break;
                case '/':*q = '\0';return calc(exp) / atoi(++q) / atoi(pl);break;
                case '%':*q = '\0';return calc(exp) % atoi(++q) / atoi(pl);break;
                default:return atoi(++q);
            };            
    }else{
        return parenthesis(q,exp) / atoi(pl);
    }
}



int parenthesis(char* q,char* exp){
        char * pa = q;
        *q = '\0';
        int flag = 1;

        /* clear another one*/
        while(flag != 0){
            pa--;
            if(*pa == ')'){
                flag++;
            };
            if(*pa == '('){
                flag--;
            };
        };
        
        if(pa == exp){
            return calc(++pa);
        }else{
            *pa = '\0';
        };

        q = pa;
        pa--;

        switch(*pa){
            case '+':*pa = '\0';return calc(exp) + calc(++q);break;
            case '-':*pa = '\0';return calc(exp) - calc(++q);break;
            case '*':*pa = '\0';return calc(exp) * calc(++q);break;
            case '/':*pa = '\0';return calc(exp) / calc(++q);break;
            case '%':*pa = '\0';return calc(exp) % calc(++q);break;
            default:return atoi(++q);
        };

}