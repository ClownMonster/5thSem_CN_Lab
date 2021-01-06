#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char t[30], cs[30], g[] = "1000100000010000";
int a,e,c;
void xor(){
    for(c=1;c<strlen(g);c++)
        cs[c] = (( cs[c] == g[c])?'0':'1');
}


void crc()
{
    for(e=0;e<strlen(g);e++)
        cs[e]=t[e];              
    do{
        if(cs[0]=='1')         
            xor();                  
        for(c=0;c<strlen(g)-1;c++)
            cs[c]=cs[c+1];    
        cs[c]=t[e++];      
    } while(e<=a+strlen(g)-1);   
}


int main()
{
    printf("\nEnter data : ");
    scanf("%s",t);
    printf("\nGeneratng polynomial : %s",g);
    a=strlen(t);
    for(e=a;e<a+strlen(g)-1;e++)
        t[e]='0';
    printf("\nPadded data is : %s",t);

        crc();
    printf("\nChecksum is : %s",cs);
    for(e=a;e<a+strlen(g)-1;e++)
        t[e]=cs[e-a];
    printf("\nFinal codeword is : %s",t);
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&e);
    if(e==0)
    {
        do{
            printf("\nEnter the position where error is to be inserted : ");
            scanf("%d",&e);
        }while(e==0 || e>a+strlen(g)-1);
        t[e-1]=(t[e-1]=='0')?'1':'0';
        printf("\nErroneous data : %s\n",t);
    }
    crc();
    for(e=0;(e<strlen(g)-1) && (cs[e]!='1');e++){}  
        if(e<strlen(g)-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
        return 0;
}