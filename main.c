/* 
 * File:   main.c
 * Author: Me
 *
 * Created on January 22, 2016, 7:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 * 
 */
void print_str(char s[]);
int key_check(char s[]);

int main(int argc, char** argv) {

    int i,j,k,iterate,i_save;
    char* buffer;
    //char* prt_arr;
    long length;
    if(argc==2){
    FILE * f = fopen (argv[1], "rb");
    
    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    fread (buffer, 1, length, f);
    fclose (f);
    
    iterate=1;
    
    for (i =0; i <length; i ){
        if(iterate==0)
            i++;
                    
        if(buffer[i]=='/'&&buffer[i+1]=='*'){
            j=1;
            while(j){
                printf("%c", buffer[i]);
                if(buffer[i]=='/'&&buffer[i-1]=='*')
                    j=0;
                i++;
            }
            printf("(Comment)\n");
            iterate=1;
        }
        
        if(buffer[i]==';'||buffer[i]=='&'||buffer[i]=='|'||buffer[i]=='/'||
           buffer[i]=='['||buffer[i]==']'||buffer[i]==','||buffer[i]=='+'||
           buffer[i]=='-'||buffer[i]=='('||buffer[i]==')'){
            
            printf("%c (Operator)\n",buffer[i]);
            i++;
            iterate=1;
        }
        
        if(buffer[i]=='<'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='='||buffer[i]=='>'||buffer[i]=='<'){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator)\n");
            iterate=1;
        }
        
        if(buffer[i]=='>'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='='||buffer[i]=='>'){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }

        if(buffer[i]=='.'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='.'){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }
        
        if(buffer[i]=='*'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='*'){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }
        
        if(buffer[i]==':'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='='){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }
        
        if(buffer[i]=='='){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='>'){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }
        
        if(buffer[i]=='!'){
            printf("%c",buffer[i]);
            i++;
            if(buffer[i]=='='){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Operator) \n");
            iterate=1;
        }
        
        if(buffer[i]=='"'){
            j=1;
            printf("%c", buffer[i]);
            while(j){
                i++;
                printf("%c", buffer[i]);
                if(buffer[i]=='"')
                    j=0;
                
            }
            printf(" (String)\n");
            iterate=1;
        }
        
        if(buffer[i]=='\''){
            for(j=0; j<3;j++){
                printf("%c",buffer[i]);
                i++;
            }
            printf(" (Char)\n");
            iterate=1;
        }
        
        if(isalpha(buffer[i])){
            j=1;
            k=0;
            char testS[25];
            printf("%c", buffer[i]);
            testS[k]=buffer[i];
            while(j==1){
                i++;
                k++;
                printf("%c", buffer[i]);
                testS[k]=buffer[i];

                if(!isalnum(buffer[i+1])){

                    
                    j=0;
                    testS[k+1]='\0';
                    
                }
            }
            //printf("   testS==%s\n",testS);
            if(key_check(testS)==0)
                printf(" (Keyword)\n"); 
            else
                printf(" (Identifier)\n");
            

            iterate=1;
        }
        
        if(isdigit(buffer[i])||buffer[i]=='#'){
            printf("%c", buffer[i]);
            i++;
            while(isdigit(buffer[i])||buffer[i]=='.'||buffer[i]=='_'){
                printf("%c", buffer[i]);
                i++;
            }
            printf(" (Num Literal)\n");
            iterate=1;
                
            
        }
        

        
        i++;
    }
    }
    else{
        printf("No input, please input a file name\n");
    }
       
    return (EXIT_SUCCESS);
}

int key_check(char s[]){
    if(strcmp(s,"and")==0)
        return 0;
    else if(strcmp(s,"accessor")==0)
        return 0;
    else if(strcmp(s,"array")==0)
        return 0;
    else if(strcmp(s,"begin")==0)
        return 0; 
    else if(strcmp(s,"bool")==0)
        return 0;
    else if(strcmp(s,"case")==0)
        return 0;
    else if(strcmp(s,"else")==0)
        return 0;
    else if(strcmp(s,"elsif")==0)
        return 0;    
    else if(strcmp(s,"end")==0)
        return 0;
    else if(strcmp(s,"exit")==0)
        return 0;
    else if(strcmp(s,"function")==0)
        return 0;
    else if(strcmp(s,"if")==0)
        return 0;
    else if(strcmp(s,"in")==0)
        return 0;  
    else if(strcmp(s,"integer")==0)
        return 0;
    else if(strcmp(s,"interface")==0)
        return 0;
    else if(strcmp(s,"is")==0)
        return 0;
    else if(strcmp(s,"loop")==0)
        return 0;
    else if(strcmp(s,"module")==0)
        return 0;    
    else if(strcmp(s,"mutator")==0)
        return 0;
    else if(strcmp(s,"natural")==0)
        return 0;
    else if(strcmp(s,"null")==0)
        return 0;
    else if(strcmp(s,"of")==0)
        return 0;
    else if(strcmp(s,"or")==0)
        return 0;  
    else if(strcmp(s,"others")==0)
        return 0;
    else if(strcmp(s,"out")==0)
        return 0;
    else if(strcmp(s,"positive")==0)
        return 0;
    else if(strcmp(s,"procedure")==0)
        return 0;
    else if(strcmp(s,"return")==0)
        return 0;    
    else if(strcmp(s,"struct")==0)
        return 0;
    else if(strcmp(s,"subtype")==0)
        return 0;
    else if(strcmp(s,"then")==0)
        return 0;    
    else if(strcmp(s,"type")==0)
        return 0;
    else if(strcmp(s,"when")==0)
        return 0;
    else if(strcmp(s,"while")==0)
        return 0;   
    else
        return 1;
}

void print_str(char s[]){
    int start = 1;
    int len = 100;
    
    printf("%.*s  ", len, s + start);
    
    switch (s[0]){
        case '1':
            printf("(%s)\n", "Comment");
        break;
        
        case '2':
            printf("(%s)\n", "Identifier");
        break;
        
        case '3':
            printf("(%s)\n", "String");
        break;
        
        case '4':
            printf("(%s)\n", "Keyword");
        break;
        
        case '5':
            printf("(%s)\n", "Char Literal");
        break;
        
        case '6':
            printf("(%s)\n", "Operator");
        break;
        
        case '7':
            printf("(%s)\n", "Num Literal");
        break;
        
        case '8':
            printf("(%s)\n", "UNK");
        break;
    }
}

/*    char s[] = "1something";  print_str test code
    char t[] = "2something";
    char u[] = "3something";
    char v[] = "4something";
    char w[] = "5something";
    char x[] = "6something";
    char y[] = "7something";
    char z[] = "8something";
    print_str(s);
    print_str(t);
    print_str(u);
    print_str(v);
    print_str(w);
    print_str(x);
    print_str(y);
    print_str(z);
 * 
 * 
 * 
 *             if(buffer[i]=='a');{
                if(buffer[i+1]=='n'&&buffer[i+2]=='d')
                    k=1;
                else if(buffer[i+1]=='c'&&buffer[i+2]=='c'&&buffer[i+3]=='e'&&
                        buffer[i+4]=='s'&&buffer[i+5]=='s'&&buffer[i+6]=='o'&&
                        buffer[i+1]=='r')
                    k=1;
                else if(buffer[i+1]=='r'&&buffer[i+2]=='r'&&buffer[i+3]=='a'&&
                        buffer[i+4]=='y')
                    k=1;
            }
 * 
 * 
 * 
 * 
 * 
 */
