#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

int matriksInput[4][6];
int matriks[4][6];
unsigned long long hasilOperasi[4][6];

typedef struct data 
{
	int matriksA;
    int matriksB;
	int x,y;
 } data;

unsigned long long factorial(int n) 
{ 
	if(n==0)return 1;
	else
		return n*factorial(n-1);
}

void *operation(void* arg)
{
	data* d = (data*) arg;
	int a = d->matriksA;
	//printf("a :%d\n",a);
	int b = d->matriksB;
	//printf("b :%d\n",b);
	int x = d->x;
	//printf("x :%d\n",x);
	int y = d->y;
	//printf("y :%d\n",y);

	if(a==0 || b==0){
		hasilOperasi[x][y] = 0;
		//printf("hasil if 3: %llu\n",hasilOperasi[x][y]);
	}
	else if (a>=b){
		int temp = a-b;
		hasilOperasi[x][y] = factorial(a)/factorial(temp);
		//printf("hasil if 1: %llu\n",hasilOperasi[x][y]);
	}
	else if(b>a){
		hasilOperasi[x][y] = factorial(a);
		//printf("hasil if 2: %llu\n",hasilOperasi[x][y]);
	}
}

void inputMatrix(){
    printf("Input matriks 4x6 :\n");
	for (int i = 0; i < 4; i++) {
    	for (int j = 0; j < 6; j++) {
      		scanf("%d", & matriksInput[i][j]);
   	 	}
  	}
}

void main(){
	key_t key = 1234;
    int i=4,j=6;
    int (*hasil)[j];
	int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
	hasil = shmat(shmid, NULL, 0);

	int* p = (int *)hasil;
	memcpy(matriks,hasil,sizeof(int)*i*j);

	pthread_t tid[i][j];
    inputMatrix();
    for(int i= 0;i<4;i++)
	{
        for(int j=0;j<6;j++){
			data *index = (data *)malloc(sizeof(data));
            index->matriksA = matriks[i][j];
            index->matriksB = matriksInput[i][j];
            index->x = i;
            index->y = j;
			// printf("matriks A : %d",index->matriksA);
			// printf("matriks B : %d",index->matriksB);
			// printf("baris : %d",index->x);
			// printf("kolom : %d",index->y);
			pthread_create(&tid[i][j],NULL, &operation, (void*)index);
			sleep(1);
        }
		
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			pthread_join(tid[i][j], NULL);
		}
	}

	printf("\nHasil Operasi Matrix : \n");
	for(int b=0; b<i; b++){
		for(int c=0; c<j ; c++){
			printf("%llu\t", hasilOperasi[b][c]);
		}
		printf("\n");
	}
	printf("\n");
	shmdt(hasil);
	shmctl(shmid, IPC_RMID, NULL);
}

