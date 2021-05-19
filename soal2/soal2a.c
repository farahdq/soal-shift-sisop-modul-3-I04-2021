#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
  int row=0;
  int matriksA[4][3] ;
  int matriksB[3][6];
  int hasil[4][6];
    void inputMatrix(){
      printf("Input matriks 4x3 :\n");
	    for (int i = 0; i < 4; i++) {
   	  for (int j = 0; j < 3; j++) {
     		scanf("%d", &matriksA[i][j]);
  	 	  }
 	  }
    printf("\nInput matriks 3x6 :\n");
	    for (int i = 0; i < 3; i++) {
   	  for (int j = 0; j < 6; j++) {
     		scanf("%d", &matriksB[i][j]);
  	  	}
 	  }
  }
    void* perkalianmatrix(void* arg){
      int x=row++;
        for(int y=0; y<6; y++){
       for(int z=0; z<3; z++){
        hasil[x][y] += matriksA[x][z] * matriksB[z][y];
      }
     }
    }
  int main(){
  int i=4,j=6;
  int (*matriks)[j];
     pthread_t tid[4];
    inputMatrix();
    for(int a=0; a<4; a++){
    pthread_create(&tid[a], NULL, &perkalianmatrix, NULL);
  }
    for (int a=0; a<4; a++){
   pthread_join(tid[a], NULL);
  }
  key_t key = 1234;
    
  int shmid = shmget(key, sizeof(int)*i*j, IPC_CREAT | 0666);
    matriks =  shmat(shmid, NULL, 0);
    printf("\nHasil Perkalian Matrix: \n");
      for(int b=0; b<i; b++){
      for(int c=0; c<j ; c++){
        printf("%d\t", hasil[b][c]);
      }
    printf("\n");
    }
    int* p = (int *)matriks;
      memcpy(p, hasil, sizeof(int)*i*j);
      shmdt(matriks);
  }
