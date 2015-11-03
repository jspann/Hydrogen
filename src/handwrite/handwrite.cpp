#import <iostream>
using namespace std;
void tywrite( FILE *file, char data[], int length );
void tyread( FILE *file, char data[], int length );
void tyiwrite( FILE *file, unsigned int data[], int length );
void writeVariable(FILE *fp, char isRef,unsigned int value);
void writeOpcode(FILE *fp, unsigned int
 op);
int hmm;
int main(int argc, char const *argv[]){
	cout << "hey" << endl;
	/*cout << sizeof(char) << endl;
	cout << sizeof(unsigned char) << endl;
	cout << sizeof(unsigned int) << endl;*/
	FILE *fp = fopen("milkme.txt","w");
	/*
	int x = 7;
	int y = 82;
	dump
	jump [2]
	y++;
	HALT
	[2]
		x--;
		return
	*/
	hmm = 0;//bytes count

	char fdat[60];
	unsigned int fdati[60];
	//magic numbers
	fdat[0] = 72;
	fdat[1] = 89;
	fdat[2] = 02;
	//program

	
	// int jumpVal = 22+34;
	int jumpVal = 51;
	tywrite(fp, fdat, 3);//write magic
	printf("%d\n", hmm);
	writeOpcode(fp,11);
	writeVariable(fp,0,7);

	writeOpcode(fp,11);
	writeVariable(fp,0,82);

	writeOpcode(fp,30);//dump

	writeOpcode(fp,20);//call
	writeVariable(fp,0,jumpVal);

	printf("two - %d\n", hmm);
	writeOpcode(fp,7);//inc
	writeVariable(fp,1,1);
	
	writeOpcode(fp,30);//dump

	writeOpcode(fp,0);//halt

	//2
	printf("one - %d\n", hmm);
	writeOpcode(fp,8);//dec
	writeVariable(fp,1,0);
	writeOpcode(fp,30);//dump
	writeOpcode(fp,21);//ret


	fclose(fp);
	return 0;
}
void writeOpcode(FILE *fp, unsigned int op){
	unsigned int temp[1];
	temp[0] = op;
	tyiwrite(fp, temp, 1);
}

void writeVariable(FILE *fp, char isRef,unsigned int value){
	char flag[1];
	unsigned int val[1];

	flag[0] = isRef;
	val[0] = value;

	tywrite(fp, flag, 1);
	tyiwrite(fp, val, 1);
}

void tywrite( FILE *file, char data[], int length ){
	fwrite(data,sizeof(char),length,file);
	for (int i = 0; i < length; i++){
		hmm++;
	}
	
}

void tyiwrite( FILE *file, unsigned int data[], int length ){
	fwrite(data,sizeof(unsigned int),length,file);
	for (int i = 0; i < length; i++){
		hmm = hmm +4;
	}
}

void tyread( FILE *file, char data[], int length ){
	char dataaa[30];
	fread(&dataaa,sizeof(char),1,file);
	for (int i = 0; i < 30; i++){
		printf("%d\n", dataaa[i]);
	}
}