


//header files
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
using namespace std;
const int MAX = 50 ;                            // global declaration of max
class postfix                                   //postfix class
{
	private :

		int stack[MAX] ;                        //integer array
		int top, nn ;                           //integer declaration
		char *s ;                               //character pointer
	public :
		postfix( ) ;                            //default constructer
		//function declarations
		void setexpr ( char *str ) ;
		void push ( int item ) ;
		int pop( ) ;
		void calculate( ) ;
		void show( ) ;
} ;
postfix :: postfix( )
{
	top = -1 ;                                 //assigning top as -1
}
void postfix :: setexpr ( char *str )
{
	s = str ;                                   //pointing s to str
}
void postfix :: push ( int item )
{
	if ( top == MAX - 1 )                       // top condition cheacking
		{cout << endl << "Stack is full" ;}
	else
	{
		top++ ;                                 //incrementing top
		stack[top] = item ;                     //assigning value of stack of top as item
	}
}
int postfix :: pop( )
{
	if ( top == -1 )                            //cheacking top condition for empty
	{
		cout << endl << "Stack is empty" ;      //displaying message
		return NULL ;
	}
	int data = stack[top] ;
	top-- ;                                     //decrementing top
	return data ;                               //returning data
}
void postfix :: calculate( )
{
	int n1, n2, n3 ;                            //creating three integer variables
	while ( *s )
	{
		if ( *s == ' ' || *s == '\t' )
		{
			s++ ;                               //incrementing pointer if space or tab is there
			continue ;                          //continue to the loop
		}
		if ( isdigit ( *s ) )
		{
			char *m;
			m=s;
			int count=0;
			while(isdigit(*s))
			{
				count++;
				s++;
			}
			cout<<"count"<<count;
			int num=0,i=count-1;
			while(isdigit(*m))
			{
				nn=*m-'0';
				num=num+nn*pow(10,i);
				i--;
				m++;

			}
			cout<<"num"<<num<<endl;
			push(num);

		}
		else
		{
			n1 = pop( ) ;                       //pop the first number
			n2 = pop( ) ;                       //pop the second number
			switch ( *s )                       //switch case
			{
				case '+' :                      //if character is +
					n3 = n2 + n1 ;              //addition of two numbers
					break ;
				case '-' :                       //if character is -
					n3 = n2 - n1 ;              //subtraction of two numbers
					break ;
				case '/' :                       //if character is /
					n3 = n2 / n1 ;              //division of two numbers
					break ;
				case '*' :                       //if character is *
					n3 = n2 * n1 ;              //multiplication of two numbers
					break ;
				case '%' :                       //if character is %
					n3 = n2 % n1 ;              //taking mod of two numbers
					break ;
				case '$' :                       //if character is $
					n3 = pow ( n2 , n1 ) ;      //calcuting power of the numbers
					break ;
				default :                       //default case
					cout << "Unknown operator" ;
					exit ( 1 ) ;
			}

			push ( n3 ) ;                       //pushing calculated number to the Stack
		}
		s++ ;                                   //incrementing pointer
	}
}
void postfix :: show( )
{
	nn = pop ( ) ;                              //pop the number from the Stack
	cout << " \n Result is: " << nn ;
}

int main( )                                     //main function
{
	char expr[MAX] ;                            //creating character array
	cout << "\nEnter postfix expression  : " ;//displaying initial message
	cin.getline ( expr, MAX ) ;                 //getting the expression from the user
	postfix q ;                                 //object creation

	//calling  functions
	q.setexpr ( expr ) ;
	q.calculate( ) ;
	q.show( ) ;
    return 0;
}


/*
output of the program :
Enter postfix expression  : 12 13 +
count2num12
count2num13
 
 Result is: 25



*/
