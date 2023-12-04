#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  //can modify the maximum read value

char output[10][10000];//The final output is an array
int IndexOutput;

typedef struct Node{
    int element_type;//0 means gone, 1 means letter variable, 2 means operator, 3 means integer, and 4 means decimal
    char store[20];//Both numbers and letters are placed inside this
}element;

typedef struct Stack{//This stack is used to build the tree
    element data;
    struct Stack* next;
}Stack;

typedef struct Tree{//Tree nodes
    element data;
    struct Tree* left;
    struct Tree* right;
}Tree;



void CleanSpace(char* input);//Be clear about irrelevant spaces
element* TurnInputIntoElement(char* input);
//int MathFuction(char* alph);//bonus Not considered
element* TurnElementIntoSuffix(element* in);//Turns the infix expression of the element into a suffix
Stack* PushStack(element in,Stack* input);//A function that presses into the stack
element PopStack(Stack* head);//Out-stack functions
Stack* initStack();//Functions that initialize the stack
int IsEmpty(Stack*);//Determine if a stack is empty
element PeekStack(Stack*);//Look at the top element of the stack but don't pop it out
int ReturnTheValueofOp(char*);//Returns the priority of this operator
int IsLetter(char object);//Determine whether it is a variable or not
int IsOprator(char object);//Determines whether it is an operator
int IsNumber(char object);//Determine if it's a number
Tree* BuildTree(element* input);//A function that creates a tree
Tree* initTree();//Initialize the function of the tree
Tree* PushTreeStack(Tree*,Tree*);//The press-in stack function during the tree creation process
Tree* PopTreeStack(Tree* head);//The ejection function in the process of creating a tree
Tree* GradForTree(element* letter,Tree* root);//
Tree* Derivative(Tree* node,char* letter,int length);//The main derivative function
Tree* copy(Tree* input);//Duplicate the entire tree
Tree* create_multiply_node(Tree* left,Tree* right);//An operational function for the derivative rule of multiplication
Tree* create_divided_node(Tree* Deriva,Tree* needed,Tree* right,int index);//An operational function for dividing derivative rules
Tree* create_cifang_node(Tree* input);//For operations on the square of the denominator in the derivative of division
Tree* create_multimins_node(Tree* left,Tree* right);//For the power of the derivation rule
Tree* create_ln_node(Tree* input);//Create logarithmic nodes
int contains_variable(Tree* node, char* letter,int length);//Determine if there are any variables in the subtree that you want to derive
void inorderTraversalSimplify(Tree* root,int count);//When exporting, use the mid-order traversal to simplify at the same time
Tree* create_zero_node();//Zero in on some things that don't need to be used
void DeleteString(char* front,char* behind);//Delete some of the excess parts
void DeletepreString(char* front,char* behind);
void DeletepostString(char* front,char* behind);
int ContainsZero(char* input);//Check whether there is a 0 that needs to be deleted
char* SimplyfiyZero(char* input);//Delete the part with 0
void DeleteMulString(char* front);//Delete the part containing *0
Tree* CreateDoubleLeft(Tree* input);
Tree* CreateDoubleRight(char* letter);//Supplements for special cases
int DetectpreString(char* input,char*behind);
int DetectpostString(char* input,char*behind);//Delete by the position


int DetectpreString(char* input,char*behind)
{
    int frontlength = strlen(input);
    int behindlength = strlen(behind);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if (strncmp(input + i, behind, behindlength) == 0&&(IsNumber(input[i-1])==1||i == 0||IsLetter(input[i-1])==1)&&(i==frontlength-2||IsNumber(input[i+2])!=1)) //如果找到要删除的字符串
        {
            return 1;
        }
    }   

    return 0;
}

int DetectpostString(char* input,char*behind)
{
     int frontlength = strlen(input);
    int behindlength = strlen(behind);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if (strncmp(input + i, behind, behindlength) == 0&&(IsOprator(input[i-1])==1||i == 0))
        {
            return 1;
        }
    }   

    return 0;
}

int main()
{
    char* input = (char*)malloc(sizeof(char)*MAX+1);
    int i,j;

    scanf("%s",input);

    CleanSpace(input);

    element* head ;

    head = TurnInputIntoElement(input);//Convert the input into an element element

    head = TurnElementIntoSuffix(head);//Convert an infix expression to a suffix expression

    Tree* root = BuildTree(head);//A tree is created from a suffix expression

    int count = 0;
    int flag = 1;//The setting indicates whether the derivative has been found for the amount of change

    Tree** gen = (Tree**)malloc(sizeof(Tree*)*MAX);//A second-order pointer to the root node is used to store the root node of the tree after derivatives of multiple variables

    for(i = 0 ; head[i].element_type!=0; i++){//Traverse the entire input element to find the variables in it to find the derivative
        for(j = 0 ; j < i;j++){
            if(strcmp(head[i].store,head[j].store)==0){
                flag = 0;//Prevent multiple derivatives for a variable
            }
        }
            if(head[i].element_type == 1&&flag == 1){
                printf("%s:",head[i].store);
                int length = (int)strlen(head[i].store);//This length is the length of the character that the variable occupies
                gen[count] = Derivative(root,head[i].store,length);
                inorderTraversalSimplify(gen[count],count);

                //Directly remove everything from the string level to simplify it
                while(DetectpreString(output[count],"+0")==1||DetectpreString(output[count],"*1")==1){//Use a function to delete the content
                    DeletepreString(output[count],"+0");
                    DeletepreString(output[count],"*1");
                }

                while(DetectpostString(output[count],"0+")==1||DetectpostString(output[count],"1*")==1){//Use a function to delete the content
                   DeletepostString(output[count],"0+");
                   DeletepostString(output[count],"1*");
                }

                DeleteMulString(output[count]);//Partial simplification of multiplication
                printf("%s\n", (output[count]));//output
                count++;//Records are the first few variables
                IndexOutput = 0;
            }
        flag = 1;//Re-set the flag
    }

    
    
    return 0;
}

void CleanSpace(char* str)//Find a way to remove spaces
{
   
    char* p = str;
    int i = 0;

    while(*p){
        if(*p!=' '){
            str[i++] = *p++;
        }
    }

    str[i] = '\0';
    
}

element* TurnInputIntoElement(char* input)
{

    element* head = (element*)malloc(sizeof(element)*MAX);
    int index = 0;
    while(*input!='\0'){//Read in characters one by one
        if(IsLetter(*input)==1){//If it's a character
            head[index].element_type = 1;
            int temp_for_count;
            for(temp_for_count = 0;IsLetter(*(input))==1;temp_for_count++){ //Fill in the string with a loop
                head[index].store[temp_for_count] = *input;
                input++;
            }
            head[index].store[temp_for_count] = '\0';//heal
        }else if(IsOprator(*input)== 1||(index != 0&&(*(input-1)== ')'||IsNumber(*(input-1))||IsLetter(*(input-1))))){//Deposit operator
            head[index].element_type = 2;
            head[index].store[0] = *input;
            head[index].store[1] = '\0';//heal
            input++;
        }else if(IsNumber(*input)== 1 || *input == '.' || (*input == '-' && (index == 0 || IsOprator(head[index-1].store[0]) == 1 || head[index-1].store[0] == '('))){ //Added judgment for decimal and minus signs
            head[index].element_type = 3;
            int temp_for_count;
            for(temp_for_count = 0;IsNumber(*(input))==1 || *(input) == '.' || (*input == '-' && (index == 0 || IsOprator(head[index-1].store[0]) == 1 || head[index-1].store[0] == '('));temp_for_count++){ //Added judgment for decimal and minus signs
                if(*input=='.'){
                    head[index].element_type = 4;//Added decimal judgment
                }
                head[index].store[temp_for_count] = *input;
                input++;
            }
            head[index].store[temp_for_count] = '\0';//heal
        }
        index++;
    }
    head[index].element_type = 0;//Changing the type to 0 at the end of the day indicates the end of the whole

    return head;
}

//Define a function, the parameter is an element pointer, and the return value is also an element pointer
element* TurnElementIntoSuffix(element* in) 
{
    //Create an array of suffix expressions, allocate memory space with malloc, the size is the maximum number of elements
    element* postfix = (element*)malloc(sizeof(element)*MAX);
    //Create a stack to store operators
    Stack* temp = initStack();

    int length;

    length = 0 ;

    //Loop through the input elements until you encounter an element type of 0 as the end flag
    while(in->element_type!=0){
            if(in->element_type == 1 || in->element_type == 3||in->element_type == 4){//Not an operator
            postfix[length++] = *in; //Add the element to the postfix array
            in++; //Move to the next element
            }else if(in->element_type == 2 && in->store[0]=='('){ //If the element is a left parenthesis
            temp = PushStack (*in,temp); //Push it into the stack
            in++; //Move to the next element
            }else if(in->element_type == 2 && in->store[0]==')'){ //If the element is a right parenthesis
            while(PeekStack(temp).store[0]!='('){ //Pop the stack until you encounter a left parenthesis
                postfix[length++] = PopStack(temp); //Add the popped element to the postfix array
            }
            PopStack(temp); //Pop the left parenthesis
            in++; //Move to the next element
            }else if(in->element_type==2){ //If the element is an operator
                if (IsEmpty(temp)==1||PeekStack(temp).store[0]=='('||ReturnTheValueofOp(in->store)>ReturnTheValueofOp(PeekStack(temp).store)){ //If the stack is empty, or the top of the stack is a left parenthesis, or the priority of the current operator is higher than the top of the stack
                    temp = PushStack(*in,temp); //Push the current operator into the stack
                }else{ //Otherwise
                    while(IsEmpty(temp)==0&&ReturnTheValueofOp(in->store)<=ReturnTheValueofOp(PeekStack(temp).store)){ //Pop the stack until the stack is empty or the priority of the current operator is higher than the top of the stack
                        postfix[length++] = PopStack(temp); //Add the popped element to the postfix array
                    }
                    temp = PushStack(*in,temp); //Push the current operator into the stack
                }
                in++; //Move to the next element
            }
    }

    while(IsEmpty(temp)!=1){ //Pop the remaining elements in the stack
        postfix[length++] = PopStack(temp); //Add them to the postfix array
    }

    return postfix; //Return the postfix array
}

int ReturnTheValueofOp(char*input)
{
    int result = 0;
    if(input[0]=='^'){
        result = 3;
    }else if(input[0]=='*'||input[0]=='/'){
        result = 2;
    }else if(input[0] == '+'||input[0] =='-'){
        result = 1;
    }else if(input[0] == ','){
        result = 0;
    }

    return result;
}

Stack* PushStack(element in,Stack*input)//Standard operation for press-into stacks
{
    Stack* cur = (Stack*)malloc(sizeof(Stack));
    Stack* temp;
    cur ->data = in;
    temp = input->next;
    input->next = cur;
    cur->next = temp;

    return input;
}

element PopStack(Stack* head)//Regular ejection operations
{
    element result = (head->next)->data;
    head ->next = head ->next->next;

    return result;
}

element PeekStack(Stack*input)
{
     element result = input->next->data;

     return result;
}
//Define a function, the parameter is an element pointer, and the return value is a tree pointer
Tree* BuildTree(element* input)
{
    //Create an array of tree pointers, allocate memory space with malloc, the size is the maximum number of elements
    Tree** head = (Tree**)malloc(sizeof(Tree*)*MAX);
    //Initialize a variable to store the index of the top of the array
    int top = -1;

    //Loop through the input elements until you encounter an element type of 0 as the end flag
    while (input->element_type != 0){
        //If the element is an operand (number, variable, or constant)
        if((input)->element_type==1||(input)->element_type==3||(input)->element_type==4){
            //Create a new tree node and assign the element to its data field
            Tree* Node = initTree();
            Node->data = *input; 
            //Push the node into the array
            head[++top] = Node; 
        }else{ //If the element is an operator
            //Create a new tree node and assign the element to its data field
            Tree* Node = initTree();
            Node->data = *input; 
            //Pop two nodes from the array and assign them to the right and left children of the current node
            Node->right = head[top--]; 
            Node->left = head[top--]; 
            //Push the current node into the array
            head[++top] = Node;
        }
        //Move to the next element
        input++;
    }

    //Return the root node of the tree, which is the last element in the array
    return head[top];
}


Stack* initStack()//Initialize the stack
{
    Stack* new = (Stack*)malloc(sizeof(Stack)*MAX);
    new->next = NULL;

    return new;
}

int IsEmpty(Stack*input)
{
    int result = 0;
    if(input->next ==NULL){
        result = 1;
    }

    return result;
}

int IsLetter(char object)
{
    int result = 0;

    if(object >= 'a'&& object <='z'){
        result = 1;
    }

    if(object >= 'A'&& object <='Z'){
        result = 1;
    }

    return result;
}

int IsOprator(char object)
{
    int result = 0;
    if(object=='+' ||object =='*'||object == '/'||object == '^'||object == ','||object=='('||object==')'){
        result = 1;
    }//Additional judgment is required
    return result;
}
int IsNumber(char object)
{
    int result = 0;
    if(object>='0'&&object<='9'){
        result = 1;
    }
    return result;
}
Tree* initTree()
{
    Tree* node = (Tree*)malloc(sizeof(Tree));
    node->left = NULL;
    node->right = NULL;

    return node;
}

Tree* copy(Tree* input)//Create a duplicate version so that the original tree is not changed
{
    if(input == NULL){
        return NULL;
    }

    Tree* new_node = (Tree*)malloc(sizeof(Tree));

    new_node->data = input->data;
    new_node->left = copy(input->left);
    new_node->right = copy(input->right);

    return new_node;
}

Tree* create_multiply_node(Tree* left,Tree* right)
{
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data.element_type = 2;
    new_node->data.store[0] = '*';
    new_node->left = left;
    new_node->right = right;

    return new_node;
}
//Define a function, the parameters are four tree pointers, and the return value is a tree pointer
Tree* create_divided_node(Tree* Deriva,Tree* needed,Tree* right,int index)
{
    //Create a new node for the root of the quotient rule tree, allocate memory space with malloc, and assign the '/' operator to its data field
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data.element_type = 2;
    new_node->data.store[0] = '/';

    //Create a new node for the left child of the root node, allocate memory space with malloc, and assign the '*' operator to its data field
    Tree* new_node_left= (Tree*)malloc(sizeof(Tree));
    new_node_left->data.element_type = 2;
    new_node_left->data.store[0] = '*';
    
    //Assign the first parameter (Deriva) to the left child of the new node left, which is the derivative of the numerator of the original function
    new_node_left->left = Deriva;

    //Create a temporary pointer to traverse the tree
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp = Deriva;

    //Find the leftmost node of the Deriva tree
    while(temp->left!=NULL){
        temp = temp->left;
    }

    //Create a new node for the left parenthesis, allocate memory space with malloc, and assign the '(' character to its data field
    Tree* Left = (Tree*)malloc(sizeof(Tree));
    Left->data.element_type = 3;
    Left->data.store[0] = '(';
    Left->left = NULL;
    Left->right = NULL;

    //Assign the left parenthesis node to the left child of the leftmost node of the Deriva tree
    temp->left = Left;

    //Assign the second parameter (needed) to the right child of the new node left, which is the denominator of the original function
    new_node_left->right = needed;

    //Assign the new node left to the left child of the root node
    new_node->left = new_node_left;

    //Create a new node for the right child of the root node, allocate memory space with malloc, and assign the '^' operator to its data field
    Tree* new_node_right = (Tree*)malloc(sizeof(Tree));
    new_node_right->data.element_type = 2;
    new_node_right->data.store[0] = '^';
    //Assign the third parameter (right) to the left child of the new node right, which is the denominator of the original function
    new_node_right->left = right;

    //Create a new node for the right child of the new node right, allocate memory space with malloc, and assign the '2)' characters to its data field
    Tree* new_node_right_right = (Tree*)malloc(sizeof(Tree));
    new_node_right_right->data.element_type = 3;
    new_node_right_right->data.store[0] = '2';
    new_node_right_right->data.store[1] = ')';

    //Set the left and right children of the new node right right to NULL
    new_node_right_right->left = NULL;
    new_node_right_right->right = NULL;
    //Assign the new node right right to the right child of the new node right
    new_node_right->right = new_node_right_right;

    //Assign the new node right to the right child of the root node
    new_node->right = new_node_right;

    //Return the root node of the quotient rule tree
    return new_node;
}


Tree* create_cifang_node(Tree* input)
{
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    Tree* new_node_right = (Tree*)malloc(sizeof(Tree));

    new_node->data.element_type = 2;
    new_node->data.store[0] = '^';
    new_node->left = input;

    new_node_right->data.element_type = 3;
    new_node_right->data.store[0] = '2';
    new_node_right->left = NULL;
    new_node_right->right = NULL;

    new_node->right = new_node_right;

    return new_node;
}

//Define a function, the parameters are two tree pointers, and the return value is also a tree pointer
Tree* create_multimins_node(Tree* left,Tree* right)
{
    //Create a new node for the root of the power rule tree, allocate memory space with malloc, and assign the '^' operator to its data field
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data.element_type = 2;
    new_node->data.store[0] = '^';
    //Assign the first parameter (left) to the left child of the root node, which is the base of the original function
    new_node->left = left;

    //Create a new node for the right child of the root node, allocate memory space with malloc, and assign the '-' operator to its data field
    Tree* new_node_right = (Tree*)malloc(sizeof(Tree));
    new_node_right->data.element_type = 2;
    new_node_right->data.store[0] = '-';

    //Create a new node for the left child of the new node right, allocate memory space with malloc, and assign the '(' character and the second parameter (right) to its data field
    Tree* new_node_right_left = (Tree*)malloc(sizeof(Tree));
    new_node_right_left->data.element_type = 1;
    new_node_right_left->data.store[0] = '(';
    int i;

    //Copy the data of the right parameter to the new node right left's data field, starting from the second position
    for(i = 0; right->data.store[i]!='\0';i++){
        new_node_right_left->data.store[i+1] = right->data.store[i];
    }

    //Assign the left and right children of the right parameter to the left and right children of the new node right left
    new_node_right_left->left = right->left;
    new_node_right_left->right = right->right;

    //Assign the new node right left to the left child of the new node right, which is the exponent of the original function
    new_node_right->left = new_node_right_left;

    //Create a new node for the right child of the new node right, allocate memory space with malloc, and assign the '1)' characters to its data field
    Tree* new_node_right_right = (Tree*)malloc(sizeof(Tree));
    new_node_right_right->data.element_type = 3;
    new_node_right_right->data.store[0] = '1';
    new_node_right_right->data.store[1] = ')';
    //Set the left and right children of the new node right right to NULL
    new_node_right_right->left = NULL;
    new_node_right_right->right = NULL;

    //Assign the new node right right to the right child of the new node right, which is the constant to be subtracted from the exponent
    new_node_right->right = new_node_right_right;
    //Assign the new node right to the right child of the root node, which is the new exponent of the power rule
    new_node->right = new_node_right;

    //Return the root node of the power rule tree
    return new_node;
}


//Define a function, the parameter is a tree pointer, and the return value is also a tree pointer
Tree* create_ln_node(Tree* input)
{
    //Create a new node for the root of the logarithm tree, allocate memory space with malloc, and assign the input's data to its data field
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data.element_type = 2;
    new_node->data.store[0] = input->data.store[0];

    //Create a new node for the left child of the root node, allocate memory space with malloc, and assign the 'ln(' characters to its data field
    Tree* new_node_left = (Tree*)malloc(sizeof(Tree));
    new_node_left->data.element_type = 2;
    new_node_left->data.store[0] = 'l';
    new_node_left->data.store[1] = 'n';
    new_node_left->data.store[2] = '(';
    new_node_left->left = NULL;
    new_node_left->right = NULL;

    //Create a new node for the right child of the root node, allocate memory space with malloc, and assign the ')' character to its data field
    Tree* new_node_right = (Tree*)malloc(sizeof(Tree));
    new_node_right->data.element_type = 2;
    new_node_right->data.store[0] = ')';
    new_node_right->left = NULL;
    new_node_right->right = NULL;

    //Assign the new node left to the left child of the root node
    new_node->left = new_node_left;
    //Assign the new node right to the right child of the root node
    new_node->right = new_node_right;

    //Return the root node of the logarithm tree
    return new_node;

}


Tree* Derivative(Tree* node,char* letter,int length)
{   
    if(node == NULL){
        return NULL;
    }

    int i;
    char temp[20];

    for(i = 0 ; i < length;i++){
        temp[i] = letter[i];
    }

    temp[i] = '\0';

    Tree* new_node = (Tree*)malloc(sizeof(Tree));

    if(node->data.element_type == 2 && node->data.store[0] =='+'){
        new_node->data.element_type = 2;
        new_node->data.store[0] = '+';
       if(contains_variable(node->left,temp,length) == 1){
           new_node->left = Derivative(node->left,letter,length);
       }else{
           new_node->left = create_zero_node();
       }
       if(contains_variable(node->right,temp,length)==1){
           new_node->right = Derivative(node->right,letter,length);
       }else{
           new_node->right = create_zero_node();
       }
       
    }else if(node->data.element_type == 2&& node->data.store[0] == '-'){
        new_node->data.element_type = 2;
        new_node->data.store[0] = '-';
        if(contains_variable(new_node->left,letter,length)==1){
           new_node->left = Derivative(node->left,letter,length);
        }else{
           new_node->left = create_zero_node();
        }
        if(contains_variable(new_node->right,letter,length)==1){
           new_node->right = Derivative(node->right,letter,length);
        }else{
           new_node->right = create_zero_node();
        }
    }else if(node->data.element_type == 2&& node->data.store[0] == '*'){
        new_node->data.element_type = 2;
        new_node->data.store[0] = '+';
        if(contains_variable(node->left,letter,length)==0){
            Tree* new_node_left = (Tree*)malloc(sizeof(Tree));
            new_node_left->data.element_type = 3;
            new_node_left->data.store[0] ='0';
            new_node_left->left = NULL;
            new_node_left->right = NULL;
            new_node->left = new_node_left;
        }else{  
            new_node->left = create_multiply_node(Derivative(node->left,letter,length), copy(node->right));
        }

        if(contains_variable(node->right,letter,length)==0){
            Tree* new_node_right = (Tree*)malloc(sizeof(Tree));
            new_node_right->data.element_type = 3;
            new_node_right->data.store[0] ='0';
            new_node_right->left = NULL;
            new_node_right->right = NULL;
            new_node->right = new_node_right;
        }else{
            new_node->right = create_multiply_node(Derivative(node->right,letter,length), copy(node->left));
        }
    }else if(node->data.element_type == 2 && node->data.store[0] == '/'){
        new_node->data.element_type = 2;
        new_node->data.store[0] = '-';
        new_node->left = create_divided_node(copy(Derivative(node->left,letter,length)),copy(node->right),copy(node->right),0);
        new_node->right = create_divided_node(copy(Derivative(node->right,letter,length)),copy(node->left),copy(node->right),1);
    }else if(node->data.element_type == 2 && node->data.store[0] == '^'){
        new_node->data.element_type = 2;
        if(strcmp(temp,node->left->data.store)==0 &&strcmp(temp,node->right->data.store)==0){
            new_node->data.element_type = 2;
            new_node->data.store[0] = '*';
            new_node->left = CreateDoubleLeft(copy(node));
            new_node->right = CreateDoubleRight(letter); 
        }
        else if(strcmp(temp,node->left->data.store)==0){
            new_node->data.element_type = 2;
            new_node->data.store[0] = '*';
            new_node->left = node->right;
            new_node->right = create_multimins_node(copy(node->left),copy(node->right));
        }else if(strcmp(temp,node->right->data.store)==0){
            new_node->data.element_type = 2;
            new_node->data.store[0] = '*';
            new_node->left = copy(node);
            new_node->right = create_ln_node(node->left);
        }else if(strcmp(temp,node->left->data.store)!=0&&strcmp(temp,node->right->data.store)!=0){
            new_node->data.element_type = 3;
            new_node->data.store[0] = '0';
            new_node->left = NULL;
            new_node->right = NULL;
        }
    }else if(node->data.element_type == 3||node->data.element_type == 4){
        new_node = node;
    }else if(node->data.element_type == 1&&strcmp(node->data.store,temp)!=0){
        new_node->data.element_type = 3;
        new_node->data.store[0] = '0';
        new_node->left = node->left;
        new_node->right = node->right;
    }else if(node->data.element_type == 1&&strcmp(node->data.store,temp)==0){
        new_node->data.element_type == 3;
        new_node->data.store[0] = '1';
        new_node->left = node->left;
        new_node->right = node->right;
    }

    return new_node;
}

int contains_variable(Tree* node, char* letter,int length) {
    
    int i;
    char temp[20];

    for(i = 0 ; i < length;i++){
        temp[i] = letter[i];
    }
    temp[i] = '\0';

    if (node == NULL) {
        return 0;
    }
    if ((node->data.element_type == 1||node->data.element_type == 3|| node->data.element_type ==4) && strcmp(node->data.store,temp)==0) {
        return 1;
    }
    return contains_variable(node->left, letter,length) || contains_variable(node->right, letter,length);
}

void inorderTraversalSimplify(Tree* root,int count)
{
        if(root != NULL){  
            int i;

            inorderTraversalSimplify(root->left,count);
            for(i = 0;i < strlen(root->data.store);i++){
                output[count][IndexOutput++] = root->data.store[i];
            }
            inorderTraversalSimplify(root->right,count);
        }
}



Tree* create_zero_node()//Save the node with a derivative of 0
{
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    new_node->data.element_type = 3;
    new_node->data.store[0] = '0';
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void DeleteString(char* front,char* behind)
{
    int frontlength = strlen(front);
    int behindlength = strlen(behind);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if (strncmp(front + i, behind, behindlength) == 0&&(IsOprator(front[i-1])==1||i == 0)) //If you find the string you want to delete
        {
            for (j = i, k = i + behindlength; k < frontlength; j++, k++) //Move the elements behind you forward
            {
                front[j] = front[k];
            }
            front[j] = '\0'; //Set the end character
            break; 
        }
    }
}
void DeletepreString(char* front,char* behind)
{
    int frontlength = strlen(front);
    int behindlength = strlen(behind);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if (strncmp(front + i, behind, behindlength) == 0&&(IsNumber(front[i-1])==1||i == 0||IsLetter(front[i-1])==1)&&(i==frontlength-2||IsNumber(front[i+2])!=1)) //If you find the string you want to delete
        {
            for (j = i, k = i + behindlength; k < frontlength; j++, k++) //Move the elements behind you forward
            {
                front[j] = front[k];
            }
            front[j] = '\0'; //Set the end character
            break; 
        }
    }
}

void DeletepostString(char* front,char* behind)
{
    int frontlength = strlen(front);
    int behindlength = strlen(behind);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if (strncmp(front + i, behind, behindlength) == 0&&(IsOprator(front[i-1])==1||i == 0)) //If you find the string you want to delete
        {
            for (j = i, k = i + behindlength; k < frontlength; j++, k++) //Move the elements behind you forward
            {
                front[j] = front[k];
            }
            front[j] = '\0'; //Set the end character
            break; 
        }
    }
}


int ContainsZero(char* input)//Check whether the following node contains 0
{
    int result = 0;
    int i;
    for(i = 0 ; i < strlen(input)-1;i++){
        if(input[i]=='0'&&(input[i+1]=='*'||input[i+1] =='/')){
            result = 1;
        }
        if((input[i] == '*'||input[i] == '/')&&input[i+1] == '0'){
            result = 1;
        }
    }


    return result;
}

char* SimplyfiyZero(char* input)//Simplify the number of nodes with 0
{
    int index = 0;
    int i;
    int begin = 0;

    char* temp = (char*)malloc((strlen(input)+1));
    for(i = 0 ; i < strlen(input);i++){
        temp[i] = input[i];
    }

    for(i = 0;i < strlen(input);i++){
        if(input[i]=='+'||input[i]=='-'||input[i] == '\0'){
            char* sub = (char*)malloc(sizeof(char)*(i-begin+1));
            strncpy(sub,input+begin,i-begin+1);
            if(ContainsZero(sub)==1){
                DeleteString(temp,sub);
            }
            begin = i+1;
        }
    }
    return temp;

}
void DeleteMulString(char* front)
{
    int frontlength = strlen(front);
    int i,j,k;

    for(i = 0 ; i < frontlength;i++){
        if(((front[i] =='0')&&front[i+1]== '*'&&i == 0)||(front[i]=='*'&&(front[i+1]=='0')||((front[i]=='0')&&front[i+1]=='*'&&!IsNumber(front[i-1]))))
        {
            //Find the start and end positions of the multiplication expression
            int start = i-1; //Start with *0 or the previous character of 0*
            int end = i+2; //Start with *0 or the last character of 0* and look backwards
            while(start >= 0 && front[start] != '+' && front[start] != '-') //If you don't encounter a plus or minus sign, keep looking
            {
                start--;
            }
            while(end < frontlength && front[end] != '+' && front[end] != '-'&&front[end]!=')') //If you don't encounter a plus or minus sign, keep looking backwards
            {
                end++;
            }
            //Move the following elements forward, covering the entire multiplication expression
            for (j = start, k = end; k < frontlength; j++, k++) 
            {
                front[j] = front[k];
            }
            front[j] = '\0'; 
            frontlength = strlen(front); //Update the string length
            break; 
        }
    }
}

Tree* CreateDoubleLeft(Tree* input)
{
    Tree* new_node = input;

    return input;
}

Tree* CreateDoubleRight(char* letter)//Handling of special cases to the second side
{
    Tree* new_node = (Tree*)malloc(sizeof(Tree));
    Tree* new_node_left = (Tree*)malloc(sizeof(Tree));
    Tree* new_node_right = (Tree*)malloc(sizeof(Tree));
    
    new_node->data.element_type = 2;
    new_node->data.store[0] = '+';

    new_node_left->data.element_type = 3;
    new_node_left->data.store[0] = '(';
    new_node_left->data.store[1] = '1';
    new_node_left->left = NULL;
    new_node_left->right = NULL;

    new_node_right->data.element_type = 1;
    new_node_right->data.store[0] = 'l';
    new_node_right->data.store[1] = 'n';
    new_node_right->data.store[2] = '(';
    int i;
    for(i = 0;letter[i]!='\0';i++){
        new_node_right->data.store[i+3] = letter[i];
    }
    new_node_right->data.store[i+3] = ')';
    new_node_right->data.store[i+4] = ')';
    new_node_right->left = NULL;
    new_node_right->right = NULL;

    new_node->left = new_node_left;
    new_node->right = new_node_right;


    return new_node;
}