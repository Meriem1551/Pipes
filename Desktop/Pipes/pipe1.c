#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
char message[14] = "Ramadan karim";
int main(){
//pere ecrit fils lire ou fils ecrit, pere lire
//pour creer un pipe on utilise: pipe(d) tq d= tableau; 
//pipe returns int: -1 error
// r|w
// 0|1

//communication pere --> fils par pipe

int p[2];
int pipe(int[2]);
if(pipe(p) == -1){
fprintf(stderr, "erreur ouverture pipe\n");
exit(1);
}
if(fork() == 0) {// fils
char messagerecu[14];
char c;
int nboctets;
close(p[1]);
read(p[0], &c, 1) != 0;
nboctets = read(p[0], messagerecu, 14);
printf("Lecture %d octets: %s\n", nboctets, message);
close(p[0]);
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
