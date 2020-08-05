#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int zombieCounter;
int zombieKilledCounter;
int stop;
int count;

pthread_mutex_t m= PTHREAD_MUTEX_INITIALIZER;
void zombieEntered(){
	pthread_mutex_lock(&m);
	++zombieCounter;
	pthread_mutex_unlock(&m);
}

pthread_mutex_t x= PTHREAD_MUTEX_INITIALIZER;
void zombieKilled(){
	--zombieCounter;
	++zombieKilledCounter;
}

int tooManyZombiesInTheRoom(){
	if(getInTheRoomCount()> 99){
		stop= 1;
		count= 2;
		return 1;
	}
	return 0;
}

int killed100Zombies(){
	if(getKilledCount()> 99){
		stop= 1;
		count= 1;
		return 1;
	}
	return 0;
}

int zombiesExist(){
	if(getInTheRoomCount()> 0){
		return 1;
	}
	return 0;
}

int getKilledCount(){
	return zombieKilledCounter;
}

int getInTheRoomCount(){
	return zombieCounter;
}
/*doorman thread*/
void *doorMan(void *p){
    while(!tooManyZombiesInTheRoom()){
        if(stop== 0){
            if((rand()% 2)== 0){
                zombieEntered();
            }
            usleep(2);
        }
        else pthread_exit(NULL); 
    }
    pthread_exit(NULL);
}

void *slayer(void *p){
    while(!killed100Zombies()){
        if(stop== 0){
            if(!zombiesExist()) continue;
            zombieKilled();
            usleep(2);
        }
        else pthread_exit(NULL);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv){
	pthread_t d1, d2;
	pthread_create(&d2, NULL, slayer, &zombieKilledCounter);
	
	for (int i= 0; i< *argv[1]- 48; i++)
        pthread_create(&d1, NULL, doorMan, &zombieCounter);
	
    sleep(1);
    
    if(count== 1){printf("istilayı atlattın\n");}
    else if(count== 2){printf("Zombie Wins\n");}
    printf("%d-%d", getInTheRoomCount(), getKilledCount());
	
	pthread_exit(NULL);
}
