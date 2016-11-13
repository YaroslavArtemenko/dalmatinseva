#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define _SIZE 16
#define MAX_SUBSTRING 200


// KATERYNA POLISHCHUK xpolis03


int len(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}


int compare(char *a,char *b)
{
    int i;
    if (len(a) !=len(b))
    {
        return 1;
    }
    for(i=0; i<len(a); i++)
    {
        if (a[i] !=b[i])
        {
            return 1;
        }
    }
    return 0;
}


int myIsDigit(char c)
{
    return c >= '0' && c <= '9';
}


int char2int(char c)
{
    if(myIsDigit(c))
    {
        return c-'0';
    }
    else
    {
        return -1;
    }
}


int str2num(char *str)
{
    int j=0;
    int result=0;
    int k=1;
    for (j=len(str)-1; j>=0; j--)
    {
        result+=char2int(str[j])*k;
        k=k*10;
    }
    return result;
}


void str2hex()
{
    char c;
    while ((c=getchar()) !=EOF){
        printf("%02x", c);
    }
}


int hex_to_int(char c)
{
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first*10 + second;
    if(result > 9) result--;
    return result;
}

int hex_to_ascii(char c, char d)
{
    int high = hex_to_int(c) * 16;
    int low = hex_to_int(d);
    return high+low;
}



int hex2asciiprint ()
{
    char c1,c2;
    char tuple[2]={'0','0'};
    int k;
    while (1)
    {
        while  ((c1=getchar())== ' ')
        {
        }
        if (c1==EOF)
        {
            break;
        }
        while  ((c2=getchar())== ' ')
        {
        }
        if (c2==EOF)
        {
            break;
        }
        if ( (c1 != '\n') && (c1 != '\0') && (!((c1 >= 'a' && c1 <= 'h') || (c1 >= '0' && c1 <= '9'))))
        {
            return 1;
        }
        if( (c2 != '\n') && (c2 != '\0') && (!((c2 >= 'a' && c2 <= 'h') || (c2 >= '0' && c2 <= '9'))))
        {
            return 1;
        }
        printf("%c", hex_to_ascii(toupper(c1),toupper(c2)));
    }
    return 0;
}


void convert(char c, char *dvojice)
{
    long int quotient;
    int i=0,j,k = 0,temp;
    char hexadecimalNumber[2] = {'0','0'};

    quotient = (int)c;

    while(quotient!=0)
    {
        temp = quotient % 16;

        if( temp < 10)
            temp =temp + 48;
        else
            temp = temp + 55;

        hexadecimalNumber[i++]=temp;
        quotient = quotient / 16;
    }
    for(j=i-1; j>=0; j--)
    {
        dvojice[k] = tolower(hexadecimalNumber[j]);
        k++;
    }
}

void print_hex_and_address_withnoparametrs()
{
    char tempstr[_SIZE]= "";
    int sizeofstr=0,j,k=0,l=0;
    int adr=0;
    char c;
    int flag=1;
    char tuple[2] = {'0','0'};
    while(flag)
    {
        for (sizeofstr=0; sizeofstr<_SIZE; sizeofstr++)
        {
            if ((c=getchar()) != EOF)
            {
                tempstr[sizeofstr]=c;
            }
            else
            {
                flag=0;
                break;
            }
        }
        for (j=sizeofstr; j<_SIZE; j++)
        {
            tempstr[j]=' ';
        }
        if (sizeofstr <= 0)
        {
            return;
        }

        adr=l*16;
        printf("%08x  ",adr);
        l++;
        for (j=0; j<_SIZE; j++)
        {
            if (j>=sizeofstr)
            {
                printf("   ");
            }
            else if ( tempstr[j]=='\n' ){
                    printf("0a ");
            }
            else if ( tempstr[j]=='\0' ){
                    printf("0d ");
            }


            else
            {
                convert(tempstr[j],tuple);
                for(k=0; k<2; k++)
                {
                    printf("%c",tuple[k]); //
                }
                printf(" ");
            }
        }
        printf("  |");
        for(j=0; j<_SIZE; j++)
        {
            if (j >= sizeofstr)
            {
                printf(" ");
            }
            else if (tempstr[j] == '\n')
            {
                printf(".");
            }
            else if (tempstr[j] == '\0')
            {
                printf(".");
            }
            else
            {
                printf("%c",tempstr[j]);
            }
        }
        printf("|");
        printf("\n");
    }
}

void print_hex_and_address_withparametrs(int start, int numb)
{
    int numberofsymbols=numb;
    char tempstr[_SIZE]= "";
    int sizeofstr=0,j,k=0,l=start;
    int adr=0;
    char c;
    int flag=1;
    char tuple[2] = {'0','0'};
    for (j=0; j<start; j++)
    {
        if ((c=getchar()) == EOF)
        {
            return;
        }
    }
    while(flag)
    {
        for (sizeofstr=0; sizeofstr<_SIZE; sizeofstr++)
        {
            if (((c=getchar()) != EOF) &&(numberofsymbols>0))
            {
                tempstr[sizeofstr]=c;
                numberofsymbols--;
            }
            else
            {
                flag=0;
                break;
            }
        }
        for (j=sizeofstr; j<_SIZE; j++)
        {
            tempstr[j]=' ';
        }
        if (sizeofstr <= 0)
        {
            return;
        }
        if (l==start)
        {
            printf("%08x  ",l);
            l=1;
        }

        else
        {
            adr=l*16;
            printf("%08x  ", adr);
            l++;
        }

        for (j=0; j<_SIZE; j++)
        {
            if (j>=sizeofstr)
            {
                printf("   ");
            }
            else if ( tempstr[j]=='\n' ){
                    printf("0a ");
            }
            else if ( tempstr[j]=='\0' ){
                    printf("0d ");
            }


            else
            {
                convert(tempstr[j],tuple);
                for(k=0; k<2; k++)
                {
                    printf("%c",tuple[k]);
                }
                printf(" ");
            }
        }
        printf("  |");
        for(j=0; j<_SIZE; j++)
        {
            if (j >= sizeofstr)
            {
                printf(" ");
            }
            else if (tempstr[j] == '\n')
            {
                printf(".");
            }
            else if (tempstr[j] == '\0')
            {
                printf(".");
            }
            else
            {
                printf("%c",tempstr[j]);
            }
        }
        printf("|");
        printf("\n");
    }
}


void printable_n_str (int n)
{
    char mas[MAX_SUBSTRING]= {0};
    char c;
    int i=0;
    int flag=1;
    while (1)
    {
        for (i=0; i<n; i++)
        {
            c=getchar();
            if (c==EOF)
            {
                return;
            }
            else if ((c=='\0') || (c=='\n'))
            {
                flag=0;
                break;
            }
            else
            {
                mas[i]=c;
            }
        }
        if (flag)
        {
            for (i=0; i<n; i++)
            {
                printf("%c", mas[i]);
            }

            while (1)
            {
                c=getchar();
                if (c==EOF)
                {
                    return;
                }
                else if ((c=='\0') || (c=='\n'))
                {
                    break;
                }
                else
                {
                    printf("%c", c);
                }
            }
            printf("\n");
        }
        flag=1;
    }
}


int main (int argc, char *argv[])
{
    int number=-1;
    int number1=-1;

    if (argc==1)
    {
        print_hex_and_address_withnoparametrs();
    }
    else if (argc==2)
    {
        if (compare("-x", argv[1]) == 0)
        {
            str2hex();
        }
        else if (compare("-r", argv[1]) == 0)
        {
            if (hex2asciiprint())
            {
                fprintf(stderr, " Wrong symbol occurred" );
                return 1;

            }
        }
        else
            fprintf(stderr, " Wrong argument");
    }
    else if (argc==3)
    {
        if ( compare ("-S", argv[1])==0)
        {
            number=str2num(argv[2]);
            if ((number<200) && (number>0))
            {
                printable_n_str(number);
            }
            else
                fprintf(stderr," Wrong number(<0 or >200)");
        }
        else
            fprintf(stderr, " Wrong argument");
    }
    else if (argc==5)
    {
        if (compare("-s", argv[1]) == 0)
        {
            number=str2num(argv[2]);
            if (number<0)
            {
                fprintf(stderr," -s number is less than 0");
            }
            else
            {
                if (compare("-n", argv[3]) == 0)
                {
                    number1=str2num(argv[4]);
                    if (number1<0)
                    {
                        fprintf(stderr," -n number is less than 0");
                    }
                    else
                    {
                        print_hex_and_address_withparametrs(number,number1);
                    }
                }
                else
                    fprintf(stderr, " Wrong argument expected -n");
            }
        }
        else
        {
            fprintf(stderr, " Wrong argument expected -s");
        }
    }

    else
    {
        fprintf(stderr, " Wrong number of arguments");
    }
    return 0;
}







