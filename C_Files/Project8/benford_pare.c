//
//  benford_par.c
//
//
//  Created by Trey Tuscai on 5/4/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>
#include "my_timing.h"
#include <pthread.h>

#define NUM_THREADS 8

// Global variables
int global_counts[10*NUM_THREADS];
int N = 0;
double *data;
pthread_mutex_t lock;

typedef struct
{
int tid;
} thread_data_t;

// Load data from a binary file that has an int and then
// a sequence of doubles. The value of the int should indicate
// the number of doubles in the sequence.
// Load the data into global variables N and data.
int loadData(char *filename) {
  FILE *fp;

  if(filename != NULL && strlen(filename))
    fp = fopen(filename, "r");
  else
    return -1;

  if (!fp)
    return -1;

  fread( &N, sizeof(int), 1, fp );
  data = (double*)malloc( sizeof(double)*N );
  fread( data, sizeof(double), N, fp );
  fclose( fp );
  // Uncomment this to verify the right data are being read in.
  // For super_short.bin, it should print out
  // data[0] = 97.137926
  // data[1] = 24.639612
  // data[2] = 55.692572
  // int i;
  // for (i = 0; i < N; i++) {
  //      printf( "data[%d] = %f\n", i, data[i] );
  // }
  return 1; // success
}

// Return the leading Digit of n.
int leadingDigit( double n ) {
    // This is not a particularly efficient approach.
    if (fabs(n) == 1.0)
        return 1;
    else if (fabs(n) == 0.0)
        return 0;
    else if (fabs(n) < 1.0) {
        // multiply it by 10 until you get a number that is at least 1.
        // Then chop off the fractional part. All that remains is the first digit.
        double tmp = fabs(n);
        while (tmp < 1.0) {
            tmp *= 10.0;
        }
        return (int)floor( tmp );
    }
    else {
        // Divide it by 10 until you get a number smaller than 10.
        // That number will be the first digit of the original number.
        long long unsigned in = (long long unsigned) floor(fabs(n));
        while (in > 9) {
            in /= 10;
        }
        return in;
    }
} // end leadingDigit

void *benford_thread(void *arg)
{
    int i, s;
    int n, start, stop;
    n = N/NUM_THREADS;
    s = * (int *) arg;

    // Do the computation.
    start = s * n;
    if (s != (NUM_THREADS-1))
    {
        stop = start + n;    // Ending index
    }
    else
    {
        stop = N;        // Ending index
    }

    while(start < stop)
    {
        //multithreaded calc
        int d = leadingDigit(data[start]);
        if(s != 0)
            global_counts[d+(s*10)]++;
        else
            global_counts[d]++;
        start++;
    }
    return 0;
}

/* Main routine. */
int main(int argc, char* argv[])
{
    double t1, t2;
    int i, rc;
    pthread_t thr[NUM_THREADS];
    thread_data_t thr_data[NUM_THREADS];

    // Load the data
    int succ;
    //succ = loadData( "super_short.bin" );
    succ = loadData( "medium.bin" );
    //succ = loadData( "longer.bin" );
    if (!succ)
    {
        return -1;
    }

    pthread_mutex_init(&lock, NULL);
    // Start the timer after we have loaded the data.
    t1 = get_time_sec();
    
    // Get the threads going
    for (i = 0; i < NUM_THREADS; i++)
    {
        thr_data[i].tid = i;
        if ((rc = pthread_create(&thr[i], NULL, benford_thread, &thr_data[i])))
        {
            fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
            return EXIT_FAILURE;
         }
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        pthread_join(thr[i], NULL);
    }
    
    //adds local to global counts
    for(int c = 11; c < 10*NUM_THREADS; c++)
    {
        if(c % 10 != 0)
        {
            global_counts[c%10]+= global_counts[c];
        }
    }
    
    // End the timer
    t2 = get_time_sec();
    
    for (i = 1; i < 10; i++)
    {
        printf( "There are %d %d's\n", global_counts[i], i );
    }
             
    printf("It took %f seconds for the whole thing to run\n",t2-t1);
    //printf("%d", N);

    // We are responsible for calling loadData, so we are responsible
    // for freeing the data array.
    free( data );
    
    pthread_exit(NULL);
    pthread_mutex_destroy(&lock);
    return 0;
} // end main


