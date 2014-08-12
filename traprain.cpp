#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
class trapRain1{
public:
    int trap(int A[], int n){
        int max_left[n];
        int max_right[n];
       max_left[0] = 0;
       max_right[n-1] = 0;

        for(int i =1;i<n;i++){
            max_left[i] = max( max_left[i-1], A[i-1] );
            max_right[n-1-i] = max(max_right[n-i], A[n-i]);
            cout << max_left[i] <<" " <<max_right[n-1-i] <<endl;
        }

        int sum = 0;
        int height;
        for(int i=0;i<n;i++){
            height = min(max_left[i], max_right[i]);
            if(height> A[i]) {
                sum += height-A[i];
            }
        }
        return sum;
    }
};

class trapRain2{
public:
    int trap(int A[], int n){
        int max_index = 0;
        for(int i =0; i<n; i++){
            if(A[i]>A[max_index]) max_index = i;
        }
        int water = 0;
        for (int i = 0, peak = 0;i<max_index; i++){
            if(A[i]> peak)peak = A[i];
            else water+=peak - A[i];
        }
        for (int i=n-1, top = 0; i>max_index; i--){
            if(A[i]>top) top = A[i];
            else water+= top - A[i];
        }
        return water;
    }
};
int main()
{
    int A[] = {0 , 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = 12;
    int res1;
    trapRain1 s1;
    trapRain2 s2;
    res1 = s1.trap(A, n);
    int res2;
    res2 = s2.trap(A,n);
    cout<<res1<<" ";
    cout<<res2<<" ";
    return 0;
}
