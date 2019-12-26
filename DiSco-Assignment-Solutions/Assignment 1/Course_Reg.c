#include<stdio.h>
#include<math.h>
int main() {
    int n, lines;
    scanf("%d", &n);
    long long int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    scanf("%d", &lines);
    int pre[lines], course[lines];
    for (int i = 0; i < lines; i++)
        scanf("%d %d" ,&pre[i], &course[i]);
    int p, pInd, c, cInd, temp, flag = 0;
    for (int i = 0; i < lines; i++) {
        p = pre[i];
        c = course[i];
        for (int j = 0; j < n; j++) {
            if (arr[j] == c) {
                cInd = j;
                flag++;
            }
            else if(arr[j] == p) {
                pInd = j;
                flag++;
            }
            if (flag == 2)
                break;
        }
        if (pInd > cInd) {
            temp = arr[pInd];
            arr[pInd] = arr[cInd];
            arr[cInd] = temp;
            i = -1;
        }
        flag = 0;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}