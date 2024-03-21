#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char message[14];
int main(){

int p[2];
int pipe(int[2]);
if(pipe(p) == -1){
fprintf(stderr, "erreur ouverture pipe\n");
exit(1);
}
if(fork() == 0) {// fils
char messagerecu[14];
char c;
char messgrev[14];
close(p[1]);
read(p[0], &c, 1) != 0;
//nboctets = read(p[0], messagerecu, 14);
int j = strlen(messagerecu) - 1;
for(int i = 0; i < strlen(messagerecu); i++){
messgrev[i] = messagerecu[j];
j++;
}
close(p[0]);
write(p[1], messgrev;
close(p[1]);
exit(0);
}
else{
//suite pere
close(p[0]);
write(p[1], message, 14);
close(p[1]);
exit(0);
}
}
