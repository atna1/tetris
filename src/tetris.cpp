#include <iostream>
#include <stdio.h>
#include <termios.h>
using namespace std;
#define CELL "\x18\x18"
#define NEXTLINE "\n"
#define SPACE "  "
#define SCREEN_WIDTH 16
#define SCREEN_HIGHT 32

//define state of every picture
//L
const char *L1[]={
	CELL CELL CELL NEXTLINE CELL,
	CELL NEXTLINE CELL NEXTLINE CELL CELL,
	SPACE SPACE CELL NEXTLINE CELL CELL CELL,
	CELL CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL
};
const char *L2[]={
	CELL CELL CELL NEXTLINE SPACE SPACE CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE CELL CELL,
	CELL NEXTLINE CELL CELL CELL,
	CELL CELL NEXTLINE CELL NEXTLINE CELL
};
// T
const char *T[]={
	CELL CELL CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL,
	CELL NEXTLINE CELL CELL CELL NEXTLINE CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE CELL CELL CELL,
	SPACE SPACE CELL NEXTLINE CELL CELL CELL NEXTLINE SPACE SPACE CELL,
};
//Z
const char * Z1[]={
	CELL CELL NEXTLINE SPACE CELL CELL,
	SPACE CELL NEXTLINE CELL CELL NEXTLINE CELL,
};
const char *Z2[]={
	SPACE CELL CELL NEXTLINE CELL CELL,
	CELL NEXTLINE CELL CELL NEXTLINE SPACE CELL
};
// I
const char *I[]={
	CELL CELL CELL CELL,
	SPACE CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL NEXTLINE SPACE CELL
};
//square
const char *S[]={//square
	CELL CELL NEXTLINE CELL CELL
};
void clearScreen(int width ,int hight)
{
	for(int i = 0 ; i < hight; ++i)
		cout<<endl;
}
int getControlSeq(char *seq, size_t len)
{
	struct termios tio, oldtio;

	tcgetattr(STDIN_FILENO, &oldtio);
	tcflush(STDIN_FILENO, TCIFLUSH);
	tio = oldtio;
#ifndef IUCLC
# define IUCLC 0
#endif
	tio.c_iflag &= ~(IUCLC|IXON|IXOFF|IXANY);
	tio.c_lflag &= ~(ECHO|ECHOE|ECHOK|ECHONL|TOSTOP|ICANON);
	tio.c_cflag |= (CS8);

	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
	size_t nRead = fread(seq,len,1,stdin);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldtio);
	return nRead;
}

int main(int argc, const char *argv[])
{
	clearScreen(SCREEN_WIDTH,SCREEN_HIGHT);
	size_t seqLen;
	char seq[3]={0};
	int i = 0;
	while(getControlSeq(seq,3))
	{
		if(!strcasecmp(seq,"\x1b[A"))
			cout<<"up arrow"<<endl;
		if(!strcasecmp(seq,"\x1b[B"))
			cout<<"down arrow"<<endl;
		if(!strcasecmp(seq,"\x1b[C"))
			cout<<"left arrow"<<endl;
		if(!strcasecmp(seq,"\x1b[D"))
			cout<<"rigth arrow"<<endl;
	}
	printf("\x1b[0A");
	for(int i = 0 ;i < sizeof(S)/sizeof(S[0]);++i)
		printf("%s\n\n",S[i]);
	return 0;
}
