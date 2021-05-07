/* GENERATE A MAX_INPUT GRID IN "random_input.txt" */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* random from 0 to n-1 */
int uniform_distribution(int n) {
       int limit;
       int r;
	srand(time(0));
       limit = RAND_MAX - (RAND_MAX % n);

       while((r = rand()) >= limit);


       return r % n;
}

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

/* This program generates an input file with maximum territories */
int main(int argc, char **argv)
{

    srand(time(0));
    int dim;

    dim = atoi(argv[1]);

    int nb_territory = atoi(argv[2]);

    if (nb_territory > dim *dim)
    {
        printf("TOO MANY TERRITORIES!\n");
        exit(1);
    }
    FILE *f = fopen("random_input.txt","w");

    fprintf(f, "%d\n%d\n", dim, nb_territory);

    int x,y,a;

    /* Flags to say if x or y is at the edge */

    int xedge = 0,yedge = 0;

    int count_t = 0;

    int tab_check[dim][dim];
    
    for (x = 0; x < dim; x++)
        for ( y = 0;y < dim; y++)
        {
            tab_check[y][x] = -1;
        }

    while (count_t  < nb_territory)
    {	    

    	y = random_number(1,dim);
	    x = random_number(1,dim);

    printf("%d, %d\n", x,y);
	if (tab_check[y-1][x-1] == 0)
		continue;

	tab_check[y-1][x-1] = 0;
	count_t ++;
    if (y == 1 || y == dim)
        yedge = 1;
    else 
        yedge = 0;

    
    if ( x == 1 || x == dim)
        xedge = 1;
    else 
        xedge = 0;

    if (xedge && yedge)
        a = random_number(0,4);
    else if (xedge || yedge)
        a = random_number(0,6);
    else 
        a = random_number(0,9);


    fprintf(f, "%d %d %d\n", a ,x ,y);
       
    }

    fclose(f);
}
