/*
Pogram Description: 
Author: Catherine Garner
Date: 23/02/2017
OS Version: Windows 10 - 64 bit
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#define SIZE 4
#define COUNT 2

//Parameters
void Option_1(int *);
int Option_2(int *, int *);
int Option_3(int *);
int Option_4(int *);
int Option_5(int *);

int main()
{
    int option;
    int ENTERED [SIZE] = {0,0,0,0};
    int EXIT [COUNT] = {0,0};
    int CORRECT_INCORRECT [COUNT] = {0,0};
    
    do
    {
        printf("\n********** MENU **********\n");
        printf("\n1. Enter code");
        printf("\n2. Encrypt code and verify if correct");
        printf("\n3. Decrypt code");
        printf("\n4. Display the number of times the code was entered \n   (i) Successfully\n   (ii) Incorrectly");
        printf("\n5. Exit program");
        printf("\nPlease select an option\n");
        
        option = getch();
            
        switch(option)
        {
            case '1': //Entereing the code
            {
                Option_1(ENTERED);
                
                printf("\nCode entered\n");
                break;
                
            } //End case 1
            
            case '2': //Encrypting and verifying if the code is correct
            {
                Option_2(ENTERED, CORRECT_INCORRECT);
                break;
            } //End case 2
            
            case '3': //Decrypting the code entered
            {
                Option_3(ENTERED);
                break;
            } // End case 3
            
            case '4'://Displaying the amount of times code was entered correctly/incorrectly
            {
                Option_4(CORRECT_INCORRECT);
                break;
            } //End case 4
            
            case '5': //Exiting the program
            {
                Option_5(EXIT);
                
                if(EXIT[0] == 1)
                {
                    break;
                }
                break;
            } //End case 5
            
            default:
            {
                printf("\nError! Incorrect input");
            } //End default
            
        } //End switch
    }
    while(EXIT[0] != 1); //Dont exit until the user says so
        
    printf("\nGoodbye");
    
    flushall();
    getchar();
    return(0);
}
    
    
void Option_1(int *entered)
{
    int i;
    
    printf("\nPlease enter your code on seperate lines\n");
    for(i = 0; i < SIZE; i++)
    {
        scanf("%d", &*(entered + i));//Entering the code
    }
    
}//End Option_1()

int Option_2(int *encrypt, int *correct_incorrect)
{
    int i;
    int buffer [SIZE] = {0,0,0,0};//Buffer to allow for the switching of numbers
    int access_code[SIZE] = {4,5,2,3};//Access code
    int right = 2;
    
    //Encryption process
    for(i = 0; i < SIZE; i++)
    {
        (buffer [i]) = (encrypt [i]); //Coppies each number into the buffer
    }
    
    //Switching the numbers
    (encrypt [2]) = (buffer [0]);
    (encrypt [3]) = (buffer [1]);
    (encrypt [0]) = (buffer [2]);
    (encrypt [1]) = (buffer [3]);
    
    //Adding one to each number
    for(i = 0; i < SIZE; i++)
    {
        (encrypt [i]) = (encrypt [i]) + 1;
    }

    //If the number is 10 change it to 0
    for(i = 0; i < SIZE; i++)
    {
        if((encrypt [i]) == 10)
        {
            (encrypt [i]) = 0;
        }
    }
    
    //Checking if the code matches access code
    for(i = 0; i < SIZE; i++)
    {
        if(encrypt[i] == access_code[i])
        {
           right = 1; 
        }//End if
        
        else
        {
            right = 0;
        }//End else
    }//End for
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\nEncrypted code: %d\n", encrypt[i]);
    }//End for
    
    if(right == 1)
    {
        printf("\nCORRECT CODE\n");
        correct_incorrect[0] = correct_incorrect[0] + 1;
    }//End if
    
    else
    {
        printf("\nERROR CODE\n");
        correct_incorrect[1] = correct_incorrect[1] + 1;
    }//End else
}//End Option_2()

int Option_3(int *decrypt)
{
    int buffer[SIZE] = {0,0,0,0};
    int i;
    
    //Decryption process
    for(i = 0; i < SIZE; i++)
    {
        (decrypt [i]) = (decrypt [i]) - 1; //Takes one from each number
    }
    
    //Coppies each number into the buffer
    for(i = 0; i < SIZE; i++)
    {
        (buffer [i]) = (decrypt [i]); 
    }
    
    //If the number is -1, change it to 9
    for(i = 0; i < SIZE; i++)
    {
        if((decrypt [i]) == -1)
        {
            (decrypt [i]) = 9;
        }
    }
    
    //Switches the numbers
    (decrypt [2]) = (buffer [0]);
    (decrypt [3]) = (buffer [1]);
    (decrypt [0]) = (buffer [2]);
    (decrypt [1]) = (buffer [3]);
    
    printf("\nCode decrypted");
    
    for(i = 0; i < SIZE; i++)
    {
        printf("\n%d", decrypt[i]);
    }
    
}//End Option_3()

Option_4(int *correct_incorrect)
{
    printf("\nThe code was entered (i)Successfully %d times\n", correct_incorrect[0]);
    printf("\nThe code was entered (ii)Incorrectly %d times\n", correct_incorrect[1]);
}//End Option_4()

int Option_5(int *exit)
{
    char answer = 'n';
    
    printf("\n\nAre you sure you would like to exit (y/n)?\n");
    scanf("%c", &answer);
    
    if(answer == 'y')
    {
        exit[0] = 1;
    }//End if
    
    else
    {
        exit [1] = 0;
    }//End else
}//End Option_5()
    
    
