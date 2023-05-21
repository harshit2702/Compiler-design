#include <stdio.h>
#include <stdlib.h>

void main(){

    char lp[]={'A','B','C','C'};
    char *rp[]={"aB","c","Ab","b"};
    int prod[3][3],c,r;


//Leading
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            prod[i][j]=0;
    }

//creating matrix for productions
    for(int i=0;i<4;i++){
        c=rp[i][0]-'a';
        if(c>=0){
            r=lp[i]-'A';
            prod[r][c]=1;
        }
    }   

    for(int i=0;i<4;i++){
        c=rp[i][0]-'A';
        if(c>=0&&c<26){
            for(int j=0;j<3;j++){
                r=lp[i]-'A';
                prod[r][j]=prod[c][j]||prod[r][j];
            }
        }
    }

    for(int i=0;i<3;i++){
        printf("Leading(%c)=",'A'+i);
        for(int j=0;j<3;j++)
            if(prod[i][j]==1)
                printf("%c",'a'+j);
            printf("\n");
    }

    printf("\n\n");


//Trailing

    int len[4]={1,0,1,0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            prod[i][j]=0;
    }

//creating matrix for productions
    for(int i=0;i<4;i++){
        c=rp[i][len[i]]-'a';
        if(c>=0){
            r=lp[i]-'A';
            prod[r][c]=1;
        }
    }   

    for(int i=0;i<4;i++){
        c=rp[i][len[i]]-'A';
        if(c>=0&&c<26){
            for(int j=0;j<3;j++){
                r=lp[i]-'A';
                prod[r][j]=prod[c][j]||prod[r][j];
            }
        }
    }

    for(int i=0;i<3;i++){
        printf("Trailing(%c)=",'A'+i);
        for(int j=0;j<3;j++)
            if(prod[i][j]==1)
                printf("%c",'a'+j);
            printf("\n");
        
    }

}