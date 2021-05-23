# soal-shift-sisop-modul-3-I04-2021

## MEMBER 
	Hika Pasya Mustofa		       05111942000015
	Farah Dhiah Qorirah		       05111942000018
	Nadhif Bhagawanta Hadiprayitno	       05111942000029
  
# QUESTION
# NO 1 
Keverk is a famous ambitious person in his colleagues. Before he became the head of department in HTMC, he has done a project which tells him to make a book server database. This project is required, so that it could be used by the app owner and is expected from the users. 
In this project, Keverk is asked to: 

## 1A 
When a client is connected to the server, there are two main options. They are register and login. If the user has chosen the register option, the client will prompt an id and password to be sent to the server. Users can also login to the server. Login is successful if the id and the password sent to the server matched with one of the accounts listed on the server application. This system can accepts multiple connections at once. A connection is counted when a client application is connected to the server. If there are 2 connections or more then we must wait for the first client to exit the application to be able to login and use the application. Keverk wanted the file that stores the id and password named account.txt with the following format :
akun.txt

## 1B
The system has a database on a file named files.tsv. The content of the file is the file path on the server, publisher, and the year of publication. For every insertion and removal of a file in the folder FILES on the server, the file files.tsv will be affected. Folder FILES are made, automatically when the server is started

## 1C 
Not only that, Keverk is asked to make a feature such that clients are able to insert new files to the server. FILES directory have a structure as follows. 
Then, we can fill the book’s data (please note that Filepath is the path to the file that will be sent to the server). Then the client will send the file to the server via socket. When a file is received at the server, a new row containing new data of the book is then added to the files.tsv.

## 1D 
Clients can also download files that exist in the FILES folder in the server, then the system must send the following file to the client. Server must check from files.tsv to check if the file requested is valid. If it’s not valid, the system sends an error message back to the client. If valid, the following file is then sent to the client in the client folder.

## 1E 
After that, the client can also delete file that is stored on the server. But keverk is afraid that the file that is going to be deleted is an important file, so instead of deleting the file, the program just changes its name to ‘old-FileName.extension’. When the filename is changed, the row of the file in files.tsv will be deleted.

## 1F 
Clients can see all the contents of files.tsv by calling the see command. Output of the command will follow this format. 

## 1G 
The client application can also do search by using the find command and a string. It will output the same format as number 6.

## 1H 
Keverk is cautious on insertion and removal of files on the server, so he made a log file for the server named running.log. The content of the log file is following this format
running.log

# NO 2 
Crypto (you) is Loba's friend. One morning, Crypto saw Loba who was overwhelmed with his boss's assignment. Since Crypto is such a challenging person, he wanted to help Loba with his job. The details of the assignment are:
## 2A
Create a matrix multiplication program (4x3 and 3x6) and then display the results. The matrix will contain the numbers 1-20 (no need to create a number filter).

input into the matrix that has been manually specified. Then multiplication is done by involving a two-dimensional array and a thread to run the multiplication process of both matrices. But actually in the multiplication of the matrix, it can be done without creating a thread. The thread is created with pthread_create(&tid[i][j], NULL, &multiplicationmatrix, NULL) and runs with the tid a incremented each iteration. Next, join each thread that has been created with pthread_join(tid[a], NULL).

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

In here we use shared memory because the result will be used in question 2b. The stage that is done in doing this share memory is to make the key first. Then the matrix variable will contain the shared memory segment associated with the shared memory identifier (key), shmid, to the address space of the calling process. and done copying data using memcpy through variable pointer p against variable results so that the variable matrix (memory shared) will contain the results of the matrix that has been multiplied.

## 2B 
Create a program using the output matrix of the previous program (program soal2a.c) (Note!: Use shared memory). Then the matrix will be calculated with the new matrix. As follows an example of calculation for the existing matrix. The calculation is that each cell originating from matrix A becomes a number for factorial, then cells from matrix B become the maximum factorial limit (from largest to smallest) (Note!: Use threads for calculations in each cell). 
Provisions
If a >= b  -> a!/(a-b)!
If b > a -> a!
If 0 -> 0

first done the declaration of two-dimensional arrays in this program and I use the struct in this program to facilitate the acquisition of the data that I want to get. The program is as follows:
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
With input function : 
	void inputMatrix(){
    	printf("Input matriks 4x6 :\n");
	for (int i = 0; i < 4; i++) {
    	for (int j = 0; j < 6; j++) {
      		scanf("%d", & matriksInput[i][j]);
   	 	}
  	}
	}
	
Operation Function :
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
Fuctorial function :
	unsigned long long factorial(int n) 
	{ 
		if(n==0)return 1;
		else
			return n*factorial(n-1);
	}
	
In the main function below the program can access the results of matrix sensitive operations in the program point 2a through share memory with a predetermined key of 1234, where the value is stored in the result variable. Then there is a result variable that will copy the data from the result variable by memcpy for the operation process to be performed next. Each cell operation on the matrix, a thread will be created. Then the first looping process of the thread will run the operation function as a routine with the index attribute as the variable used. 
The thread is created with pthread_create(&tid[i][j], NULL, &multiplicationmatrix, NULL) and runs with the tid i j incremented each iteration. Then it is joined to each thread that has been created with pthread_join(tid[a], NULL). In order for the thread to run regularly (sequentially) is used sleep(1) so that between threads there is a time lag of 1 second. To end the ongoing share memory used shmctl.

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


## 2C
For fear of lags in the process of helping Loba, Crypto also created a program (soal2c.c) to check the top 5 processes consuming computer resources with the command  “ps aux | sort -nrk 3,3 | head -5” (Note !: You must use IPC Pipes)

At this point, you are asked to check the top 5 processes that consume their computer resources with ps aux command | sort -nrk 3.3 | head -5. Where the command must be executed through IPC Pipes. The program is as follows:
	#include <stdlib.h>
	#include <stdio.h>
	#include <unistd.h>
	#include <errno.h>

	  int pid;
	  int pipe1[2];
	  int pipe2[2];
	    void exec1() {
	    // input from stdin (already done)
	    // output to pipe1
	      dup2(pipe1[1], 1);
	    // close fds
	      close(pipe1[0]);
	      close(pipe1[1]);
	    // exec
	      execlp("ps", "ps", "aux", NULL);
	    // exec didn't work, exit
	      perror("bad exec ps");
	      _exit(1);
	      }

	    void exec2() {
	     // input from pipe1
		dup2(pipe1[0], 0);
	    // output to pipe2
		dup2(pipe2[1], 1);
	    // close fds
		close(pipe1[0]);
		close(pipe1[1]);
		close(pipe2[0]);
		close(pipe2[1]);
	    // exec
		execlp("sort", "sort", "-nrk", "3.3", NULL);
	    // exec didn't work, exit
		perror("bad exec grep root");
		_exit(1);
	      }

	    void exec3() {
	      // input from pipe2
		dup2(pipe2[0], 0);
	      // output to stdout (already done)
	      // close fds
		close(pipe2[0]);
		close(pipe2[1]);
	      // exec
		 execlp("head", "head", "-5", NULL);
	      // exec didn't work, exit
		  perror("bad exec grep sbin");
		   _exit(1);
	      }

	    void main() {
	      // create pipe1
		 if (pipe(pipe1) == -1) {
		  perror("bad pipe1");
		  exit(1);
	    }
		// fork (ps aux)
		  if ((pid = fork()) == -1) {
		    perror("bad fork1");
		    exit(1);
	     } else if (pid == 0) {
	      // stdin --> ps --> pipe1
		 exec1();
		}
	    // parent
	    // create pipe2
		if (pipe(pipe2) == -1) {
		  perror("bad pipe2");
		  exit(1);
	      }
	      // fork (grep root)
		  if ((pid = fork()) == -1) {
		    perror("bad fork2");
		      exit(1);
		} else if (pid == 0) {
		   // pipe1 --> grep --> pipe2
		  exec2();
		  }
	       // parent
	       // close unused fds
		close(pipe1[0]);
		close(pipe1[1]);
	       // fork (grep sbin)
		  if ((pid = fork()) == -1) {
		   perror("bad fork3");
		    exit(1);
		   } else if (pid == 0) {
		       exec3();
		       }
	    }
Based on the program, each command is divided into several functions, namely the exec1 function containing the ps aux command, the exec2 function containing the -nrk 3.3 sort command, and the exec3 function containing the command head -5. Which in each main function is done pipe creation as well as the call of each exec function that if failed it will be done exit and display the error message. Call each function by applying a fork creation that if if(pid == 0) is fulfilled, the exec function will run. So it can be concluded that every function called is a child. It can also be known that ps aux command is used to display all running processes, command sort -nrk 3.3 to sort based on its memory usage, and command head -5 so that the process displayed is the 5th most averaged process.

Problems encountered :
1. haven't add pthread library
2. confuse about the shared memory code

# QUESTION 3
During his time of inactivity, a student named Alex. He had an idea to tidy up a number of files on his laptop. Because there are too many files, Alex asked Ayub for advice. Ayub suggests creating a C program to categorize the files. This program will move files according to their extension into a folder according to the extension. The folder is in the working directory in which the categorization program is run

Example:
# The category program is located at /home/izone/kategori
$ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip
#Result
/home/izone
|-jpg
|--file1.jpg
|-c
|--file2.c
|-zip
|--file3.zip

## 3A
Program accepts -f option like stated above, with this option the user may add file arguments to be categorized as much as they want. 
Output:
File 1 : Berhasil Dikategorikan (jika berhasil)
File 2 : Sad, gagal :( (jika gagal)
File 3 : Berhasil Dikategorikan

 
 	
	getcwd(cwd, sizeof(cwd));
    int i=0;
    //loop as much arguments of the file where it would insert into the thread used to move file
    if (strcmp(argv[1],"-f") == 0) 
    {
        for(int j = 2 ; j < argc ; j++ )
        {
            pthread_create(&(tid[i]),NULL,function,argv[j]);
            pthread_join(tid[i],NULL);
            printf("File %d : Berhasil Dikategorikan\n", i+1);
            i++;
        }
    }

If the argument given by user is -f and the argument path is correct, it will be inserted to thread, and will be executing the function to move file to categorize file. In accordance with the thread amount, thread will be run simultaneously using the pthread_join. There are also different parameters that are the pointer type and return 0 and 1 to know whether the file is able to be categorized or not. if succeed = 1, and if fail = 0. the number returned would then be integerized and if 1 will say = Berhasil Dikategorikan, and if it fails = Sad, gagal


Answer

## 3B
Program may accept -d option to categorize a directory instead. With this option, the user may only input 1 directory as it's arguments, unlike the -f option where the user may input multiple file arguments. Example:
$ ./kategori -d /path/to/directory/

The command above will categorize the files in /path/to/directory, the categorization result will be saved in the working directory where the C program is called (categorization result is not located at /path/to/directory).
Output:
Jika berhasil, print “Direktori sukses disimpan!”
Jika gagal, print “Yah, gagal disimpan :(“

 	 else if (strcmp(argv[1],"-d") == 0 && argc == 3) 
    {
        i = 0;
        DIR *fd;
        struct dirent *masuk;
        char tempata[100];
        fd = opendir(argv[2]);
        //check if directory can be opened or not
        if(fd == NULL)
        {
            printf("Yah, gagal disimpan :(\n");
        }
        // Read what is inside the directory
        while( (masuk=readdir(fd)) )
        {
            if ( !strcmp(masuk->d_name, ".") || !strcmp(masuk->d_name, "..") )
            continue;

            // Save/Keep the path file that's been categorized in Tempata
            strcpy(tempata,argv[2]);
            strcat(tempata,"/");
            strcat(tempata,masuk->d_name);
            // Check if the file if its right, if right then it goes inside the thread
            if(masuk->d_type == 8)
            {
            pthread_create(&(tid[i]),NULL,function,tempata); // create the thread
            pthread_join(tid[i],NULL);
            i++;
            }
        }
        printf("Direktori Sukses Disimpan!\n");
    }

If the argument that is given by User is -d then the argument path that is chosen will be 1, the first is to call the function list to list and keep the _Path_ file in the array. After that, the element that will make a new thread the execute the move file like 3A, and is exactly the amount of _path_ on the array and will be run in parallel using the pthread_join.

The second parameter would be to return 0 or 1 to indicate if the directory has been categorized or not. 

## 3C
Other than the above options, this program accepts the * option. Example:
$ ./kategori \*

This option categorizes all the file in the working directory when the C program is run

	else if (strcmp(argv[1],"*") == 0 && argc == 2) 
    {
        i = 0;
        DIR *fd;
        struct dirent *masuk;
        char tempata[100];
        fd = opendir(cwd);

        if(fd == NULL)
        {
            printf("Yah, gagal disimpan :(\n");
        }
        char tempatsoal[100] = "/home/damdum/Soal3/soal3.c", tempatsoal3[100] = "/home/damdum/Soal3/soal3";
        while((masuk=readdir(fd)))
        {
            if (!strcmp(masuk->d_name, ".") || !strcmp(masuk->d_name, "..") )
            continue;

            strcpy(tempata,cwd);
            strcat(tempata,"/");
            strcat(tempata,masuk->d_name);

            //printf("tempata = %s\n", tempata);
            //printf("tempatsoal = %s\n", tempatsoal);
            //printf("tempatsoal3 = %s\n", tempatsoal3);

            if((strcmp(tempata,tempatsoal) == 0) || strcmp(tempata,tempatsoal3) == 0) 
            continue;

            else if(masuk->d_type == 8){
            pthread_create(&(tid[i]),NULL,function,tempata); //create thread
            pthread_join(tid[i],NULL);
            i++;
            }
        }
        printf("Direktori suskses disimpan!\n");
    }

If the argument that is given which is "*" the first that is done to keep the _path current working directory_ caused to categorized the file that on the directory that is being used. 

it will call the fucntiion first and save the file in the array, where after that will make a new thread each to execute the move file function. Thread would then run in parallel.



## 3D
All files must be moved into a folder. Files without extensions will be moved to a folder named "Unknown". Hidden files will be moved to a folder named "Hidden".

	 else
    {
        strcpy(temp,cwd);
        strcat(temp,"/");
        strcat(temp,"Unknown");
        mkdir(temp, 0777);
    }
	

    char path[1024], destination[1024];
    strcpy(path,arg);
    strcpy(destination,cwd);
    strcat(destination,"/");
    if(n == 1 )
    {
        strcat(destination,"Unknown");
    }
    else
    {
        strcat(destination,lowcase);
    }
    strcat(destination,"/");
    strcat(destination,arr3);
    rename(path,destination);
    n = 0;
    m = 0;

	return NULL;
}


## 3E
Each file to be categorized will be processed by a thread to make the program run in parallel to make it quicker.


