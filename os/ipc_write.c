#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    printf("                     IPC WRITER\n");
    printf("                    ============\n");
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Write data :");
    scanf("%s", str);
    printf("Data written in memory: %s\n", str);
    shmdt(str);
    return 0;
}
