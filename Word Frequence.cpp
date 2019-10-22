#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int CountL[26];
 
int CheckL(char c)//计算每个字母出现的次数 
{
    char i, j;
    int flag = 0;
 
    for(i = 'A', j = 'a'; i <= 'Z', j <= 'z'; i++, j++){
        if(i == c){
            CountL[i - 65]++;
            flag = 1;
            break;
        }
        if(j == c){
            CountL[j - 97]++;
            flag = 1;
            break;
        }
    }
    return flag;
}
 
int LetterScan(char *filep)//计算字母总数 
{
    FILE *fp;
    int count = 0;
    char c;
	fp = fopen(filep, "r");
    if(fp!= NULL){
        while(!feof(fp)){
        	c = fgetc(fp);
        	if(CheckL(c)){
        	    count++;
        	}
    	}
    }
 	else{
 		printf("empty file!");
 		exit(0);
	}
    fclose(fp);
    return count;
}
 
char *SortL()//按频率排序 
{
    char *Letter;
    Letter = (char *)calloc(26, sizeof(char));
 
    for(int i = 0; i < 26; i++){
        Letter[i] = i + 97;
    }
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 25 - i; j++){
            if(CountL[j] < CountL[j + 1]){
                int temp = CountL[j];
                CountL[j] = CountL[j + 1];
				CountL[j + 1] = temp;
				
                char temp1 = Letter[j];
                Letter[j] = Letter[j + 1];
                Letter[j + 1] = temp1;
            }
        }
    }
    return Letter;
}

 
int main()
{
    char *FilePath = "statics.txt";
    int count = 0;
    char *Letter;
    Letter = (char *)calloc(26, sizeof(char));
    //system("rm -rf doc/test.txt");
    //system("cat doc/*txt > doc/test.txt");
    count = LetterScan(FilePath);
    Letter = SortL();
 
    for(int i = 0; i < 26; i++){
        printf("%c:%.2f\n", Letter[i], (float)CountL[i] / count);
    }
    
    int n;
    printf("输出单个文件中的前%d个最常出现的英语单词",n);
    scanf("%d",&n);
    
    
    free(Letter);
    return 0;
}
