// Program that validates if a credit card number is valid

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "vars-credit.h"
#include "getcardnum.c"
#include "valilength.c"
#include "valistart.c"
#include "valichecksum.c"

// Start main function
int main(int argc, char const *argv[])
{

    getcardnum( );

    valilength(  );
    if (isvalid == false)
    {
        // Invalid in length
        return 1;
    }

    validatestart( );
    if (isvalid == false)
    {
        // Invalid in the start
        return 2;
    }

    valichecksum ( );
    if (isvalid == false)
    {
        // Invalid in Checksum
        return 3;
    }

    printf("%s\n\n", cardname);

    return 0;
}
