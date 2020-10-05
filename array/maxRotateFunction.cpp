//396
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int rotateFunction(vector<int>&A){
        int maxRotate=0;
        int n=A.size();
        for(int i=0;i<n;i++){
            maxRotate += i*A[i];
        }
        return maxRotate;
    }
    int maxRotateFunction(vector<int>& A) {
        int maxRotate=0;
        int n=A.size();
        for(int i=1;i<n;i++){
            maxRotate += i*A[i];
        }
        cout<<"第0次的旋转函数为: "<<maxRotate<<endl;
        for(int i=1;i<n;i++){
            int tmp=A[n-1];
            int tmp_max=0;
            for(int k=n-1;k>0;k--){
                A[k]=A[k-1];
                tmp_max += k*A[k];
            }
            A[0]=tmp;
            if(maxRotate<tmp_max) maxRotate=tmp_max;
            cout<<"第"<<i<<"次旋转后的旋转函数为: "<<maxRotate<<endl;
        }
        return maxRotate;
    }

    int maxRotateFunction1(vector<int>&A){
        int maxRotate=0;
        int n= A.size();
        if(n>0){
            for(int i=0;i<n;i++){
                int f_i=0;
                for(int j=0;j<n;j++){
                    f_i +=(j+i)%n*A[j];
                }
                if(maxRotate<f_i)maxRotate=f_i;
            }
        }
        return maxRotate;
    }
    //找出递推公式
    int maxRotateFunction2(vector<int>& A){
        long n=A.size();
        if(n==0)return 0;
        long sum=0;
        long f_0=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            f_0 +=i*A[i];
        }
        cout<<"f_0: "<<f_0<<endl;
        long maxRotate=f_0;
        for(int i=1;i<n;i++){
            long f_i = f_0+sum-n*(long)A[n-i];
            cout<<"f_"<<i<<": "<<f_i<<endl;
            if(maxRotate<f_i) maxRotate=f_i;
            f_0=f_i;
        }
        return maxRotate;
    }
};

void test(vector<int> &v){
    Solution s;
    cout<<"最大值为:"<<" ";
    cout<<s.maxRotateFunction2(v)<<endl;
}
int main(){
    vector<int> v{1,1};
    test(v);
    return 0;
}