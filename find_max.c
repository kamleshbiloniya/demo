#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<string.h>
#include<pthread.h>
#include<math.h>
#define SEED 0x74
pthread_t threads[64];
#define MAX_THREADS 64
#define TDIFF(start, end) ((end.tv_sec - start.tv_sec) * 1000000UL + (end.tv_usec - start.tv_usec))
#define USAGE_EXIT(s) do{ \
                             printf("Usage: %s <# of elements> <# of threads> \n %s\n", argv[0], s); \
                            exit(-1);\
                    }while(0);
typedef struct thread_param{

                         int *array;
                         int size;
                         int skip;
                         double max;
                         int max_index;
  }thread_param;

int checkprime(int x){
  if(x==0)return 0;
  for(int i=2; i<=sqrt(x);i++){
    if(x%i==0)return 0;
  }
  return 1;
}


void *find_max_prime(void * arg){
  static int count=0;
  thread_param *param=(thread_param*)arg;
  int i=count;
  int max_p_index=-1;
  while(i< (param->size)){
    if(checkprime(param->array[i])&&max_p_index==-1)max_p_index=i;
    else if(checkprime(param->array[i])&&param->array[i]>param->array[max_p_index])max_p_index=i;
i+=param->skip;
  }
  param->max_index=max_p_index;
  param->max=param->array[max_p_index];
  count++;
  return NULL;
}

int main(int argc, char **argv)
{
  int *ar,num_ele,num_th;
   struct timeval start, end;
  if(argc !=3)
          USAGE_EXIT("not enough parameters");
  num_th =atoi(argv[2]);
  num_ele=atoi(argv[1]);
  if(num_th <=0 || num_th > MAX_THREADS){
        USAGE_EXIT("invalid num of threads");
  }
ar = malloc(num_ele * sizeof(int));
if(!ar){
          USAGE_EXIT("invalid num elements, not enough memory");
  }
  srand(SEED);
  for(int i=0;i<num_ele;i++){
   ar[i]=random();
  }
    gettimeofday(&start, NULL);
    thread_param *argp=(thread_param*)malloc(num_th*sizeof(thread_param));
     bzero(argp,num_th*sizeof(thread_param));
  int maximum=0;
  for(int i=0; i<num_th; i++){
    thread_param *arg=argp+i;
    arg->array=ar;
    arg->size=num_ele;
    arg->skip=num_th;
    arg->max_index=-1;
  if(pthread_create(&threads[i], NULL, find_max_prime, (void*)arg) != 0){
      printf("ERROR404\n");
             perror("pthread_create");
             exit(-1);
       }
  }
  for(int i=0; i<num_th; i++){
    pthread_join(threads[i], NULL);
  }

  for(int i=0;i<num_th;i++){
    thread_param *arg=argp+i;

    if(arg->max>maximum)maximum=arg->max;
  }
    printf("Maximum prime number:%d\n",maximum);
    gettimeofday(&end, NULL);
      printf("Time taken = %ld microsecs\n", TDIFF(start, end));
      free(argp);
      free(ar);
return 0;
}

/*
what does it do?
It finds maximum prime number. 
compile:
gcc -pthread find_max.c -lm

run:
./a.out 100 10
*/
