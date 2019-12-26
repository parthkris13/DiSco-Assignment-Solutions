// Beauty
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, s1, s2, d1, d2, x;
	cin >> n >> s1 >> s2 >> d1 >> d2;
	int a[n][n];
	for(int i = 0; i < n; i++) {
		x = i%2;
		for(int j = 0; j < n; j++) {
			a[i][j] = 1 - x;
			x = 1 - x;
		}
	}
	if (n%2 != 0) {
		if(a[s1][s2] == a[d1][d2] && a[s1][s2] == 1)
			cout << "YES";
		else
			cout << "NO";
	}
	else {
		if(a[s1][s2] != a[d1][d2])
			cout<<"YES";
		else
			cout<<"NO";
	}
}


/*
2
0 0
0 1

5
0 0
4 4

5
1 1
3 4
*/