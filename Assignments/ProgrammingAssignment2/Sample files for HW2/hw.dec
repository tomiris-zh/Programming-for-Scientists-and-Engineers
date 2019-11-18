#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFSZ	128

int main()
{
	int i, j;
	char c, nl;
	float average;
	int max, nmax;
	int secret, guess, total, games;

	setvbuf(stdout, NULL, _IONBF, 0);
	printf( "WELCOME to the guessing game!\n" );

	srand( time( NULL ) );
	max = 9999;
	guess = 0;
	total = 0;
	games = 0;

	char buf[128];

	printf( "MENU: s, n, or q\n" );
	// Here I use fgets, rather than getchar, in case the user enters words rather than 
	// the single char.  Also, it reads the newline, so I don't have to handle it
	// IF the user enters whole words, it isn't counted as an error, just ignored
	while( fgets( buf, BUFSZ, stdin ) != NULL )
	{
		// I use a switch statement here instead, just to show both ways
		c = buf[0];
		switch( c )
		{
			case 'q':
			{
				if ( games == 0 )
					average = 0.0;
				else
					average = (float) total/games;
				printf( "Bye!  AVERAGE %f\n", average );
				return 0;
			}
			case 'n':
			{
				printf( "Enter a new MAXIMUM\n" );
				// Use fgets and atoi, rather than scanf.  atoi also doesn't really check for non-chars
				fgets( buf, BUFSZ, stdin );
				nmax = atoi( buf );
				if ( nmax >= 0 )
					max = nmax;
				break;
			}
			case 's':
			{
				secret = rand()%(max+1);
	
				guess = 0;
				games++;
				printf( "Guess a number BETWEEN 0 AND %d\n", max );
				for (;;)
				{
					// Use fgets and atoi, rather than scanf.  atoi also doesn't really check for non-chars
					fgets( buf, BUFSZ, stdin );
					j = atoi( buf );
					guess++;
					total++;
					if ( j < secret )
					{
						printf( "LOW\n" );
					}
					else if ( j > secret )
					{
						printf( "HIGH\n" );
					}
					else
					{
						printf( "Correct: it TOOK %d guesses\n", guess );
						break;
					}
				}
				break;
			}
			default:
				printf( "UNRECOGNIZED %c\n", c );
		}
		printf( "MENU: s, n, or q\n" );
	}
}
