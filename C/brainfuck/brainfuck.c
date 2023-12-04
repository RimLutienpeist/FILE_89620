// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int c;
//     puts("#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nint main(){char *ptr=malloc(3000);memset(ptr, \'\\0\', 3000);");
//     while ((c=getchar())!=EOF) {
//         switch (c) {
//             case '>':	puts("++ptr;"); break;
//             case '<':	puts("--ptr;"); break;
//             case '+':	puts("++*ptr;"); break;
//             case '-':	puts("--*ptr;"); break;
//             case '.':	puts("putchar(*ptr);"); break;
//             case ',':	puts("*ptr =getchar();"); break;
//             case '[':	puts("while (*ptr) {"); break;
//             case ']':	puts("}"); break;
//         }
//     }
//     puts("}\n");
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s file_name", argv[0]);
        return 0;
    }

    FILE * pFile;
    pFile=fopen (argv[1],"r");
    if (pFile==NULL) {
        perror ("Error opening file");
        exit(1);
    }

    char *code = malloc(3000);      // 存储代码
    int code_offset = 0;
    int *skip_table = malloc(3000); // 追踪方括号
    int skip_table_offset = 0;
    int *stack = malloc(3000);      // 为了得到对应括号的位置，我们自然要有一个栈
    int p = 0;

    // 提取代码、构造方括号追踪表
    int c;
    while ((c=getc(pFile)) != EOF) {
        if (c == '[')
            stack[p++] = code_offset;
        if (c == ']') {
            // assert p>0
            int start = stack[--p];
            skip_table[start] = code_offset; // start => end
            skip_table[code_offset] = start; // end => start
        }
        switch (c) {
            case '>':
            case '<':
            case '+':
            case '-':
            case '.':
            case ',':
            case '[':
            case ']':
                code[code_offset++] = c; // 存储代码
        }
    }

    // 运行代码
    char *ptr=malloc(3000);    // 大数组
    memset(ptr, '\0', 3000);   // 清0
    int ip = 0;                // IP指向当前指令
    while (ip < code_offset) {
        c=code[ip];            // 当前指令
        switch (c) {
            case '>':	++ptr; break;
            case '<':	--ptr; break;
            case '+':	++*ptr; break;
            case '-':	--*ptr; break;
            case '.':	putchar(*ptr); break;
            case ',':	*ptr =getchar(); break;
            case '[':	if (*ptr == '\0') ip = skip_table[ip]; break; // while (*ptr) {
            case ']':	if (*ptr)         ip = skip_table[ip]; break; // }
        }
        ip++;
    }
}

// [-]>[-]>[-]++++[<+++++>-]<+++[<+++++>-]<.>++[<----->-]<-.---.