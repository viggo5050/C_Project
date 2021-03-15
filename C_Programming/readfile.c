#include<stdio.h>
#include<assert.h>

int main(void){



	FILE *fp1  = fopen("./file1","w");
	assert(fp1 != NULL);
	for (int i = 0;i<5;i++){
		fputc('6',fp1);
	}
	fclose(fp1);
	fp1  = fopen("./file1","r");
	FILE *fp2  = fopen("./file2","w");
	int c;
	while ((c = fgetc(fp1))!= EOF){
		fputc(c,fp2);
	}
	fclose(fp1);
	fclose(fp2);
}