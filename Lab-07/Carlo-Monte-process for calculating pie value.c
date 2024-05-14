#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int point_inside_circle=0;
void *runner(void *param);
int main(int argc,char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    if (argc != 2) {
    fprintf(stderr,"usage: a.out <integer value>\n");
    return -1;
    }

    if (atoi(argv[1]) < 0) {
    fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
    return -1;
    }
    pthread_attr_init(&attr);
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);
    double pi=4.00*point_inside_circle/atoi(argv[1]);
    printf("The value of pie is: %lf \n",pi);
}
void *runner(void *param)
{
    int i, upper = atoi(param);
    //srand(time(NULL));
    for(i=0;i<upper;i++){
        int first = rand();
        double x=((double)first/ RAND_MAX)*2-1;
        int second=rand();
        double y=((double)second/RAND_MAX)*2-1;
        if(sqrt(x*x+y*y)<=1)
        //int c=x*x + y*y;
        //if(sqrt(c<=1))

        {
            point_inside_circle++;
        }
    }
    pthread_exit(0);
}

