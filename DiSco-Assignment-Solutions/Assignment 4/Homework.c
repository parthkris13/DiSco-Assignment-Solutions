//  Created by Manisha Katariya on 23/11/19.
// Manisha is the best <3.
#include <stdio.h>
int n, prefix[100]; char array[100][100];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%s", array[i]);
	}
	int flag=0, sum=0, equalCheck=0;
	for(int i=0; i<n;i++){
		flag=0;
		while(flag==0){
			sum=0;
			for(int j=0; j<n; j++){
				equalCheck=0;
				if(j==i) continue;
				for(int loop=0; loop < prefix[i]+1; loop++){
					if(array[i][loop] != array[j][loop]) equalCheck =1;
				}
				sum += equalCheck;	
			}
			if(sum == n-1) flag=1;
			else prefix[i]++;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j< prefix[i] + 1; j++){
			printf("%c", array[i][j]);
		}
	printf("\n");	
	}
	return 0;
}