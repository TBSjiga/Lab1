#include <stdio.h>
#include <stdlib.h>
void converter ( double value, char scale )
{
	if ( scale == 'c' || scale == 'C' )
	{
		if ( value <= -273.15 )
		{
			printf ( "<<ERROR. The entered temperature is below or equal to absolute zero>>" );
		}
		else
		{
			double far = value * 1.8 + 32;
			double kel = value + 273.15;
			printf ( "%.2f C: \n", value);
			printf ( "%.2f F \n", far );
			printf ( "%.2f K \n", kel );
		}
	}
	else if ( scale == 'f' || scale == 'F' )
	{
		if ( value <= -459.67 )
		{
			printf ( "<<ERROR. The entered temperature is below or equal to absolute zero>>" );
		}
		else 
		{
			double cel = ( value - 32 ) / 1.8;
			double kel = ( value - 32 ) / 1.8 + 273.15;
			printf ( "%.2f F: \n", value );
			printf ( "%.2f C \n",  cel );
			printf ( "%.2f K \n", kel );
		}
	}
	else if ( scale == 'k' || scale == 'K' )
	{
		if ( value <= 0 )
		{
			printf ( "<<ERROR. The entered temperature is below or equal to absolute zero>>" );
		}
		else 
		{
			double cel = value - 273.15;
			double far = ( value - 273.15 ) * 1.8 + 32;
			printf ( "%.2f K: \n", value );
			printf ( "%.2f C \n",  cel );
			printf ( "%.2f F \n", far );
		}
	}
	else
	{
		printf ( "<<ERROR. Unknown temperature scale. Type C, K or F.>>" );
	}
}

int main( int argc, char *argv[] )
{
	if ( argc == 2 )
	{
		double value = atof ( argv[1] );
		converter ( value,'C' );
		printf ( "\n" );
		converter ( value,'F' );
		printf ( "\n" );
		converter ( value,'K' );
	}
    else if( argc == 3 ) 
	{
		double value = atof ( argv[1] );
		converter ( value,*argv[2] );
    }
    return 0;
}
