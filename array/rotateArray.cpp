//189题，旋转数组
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n>1){
            for(int i=0;i<k;++i){
                 int tmp=nums[n-1];
                for(int k=n-1;k>0;k--){
                     nums[k]=nums[k-1];
                 }
                nums[0]=tmp;
             }
        }
       
    }
    void rotate1(vector<int>& nums,int k){
         int n=nums.size();
         int count=0;
        if(n>1){
            k = k%n;
            for(int start=0;count<n;start++){
                int current=start;
                int prev = nums[current];
                do{
                    int next = (current+k)%n;
                    int tmp = nums[next];
                    nums[next]=prev;
                    prev=tmp;
                    current=next;
                    count++;
                }while(current!=start);
            }
        }
    }
};

ostream& operator<<(ostream& os,const vector<int>& v){
    for(auto c:v){
        os<<c<<" ";
    }
    cout<<endl;
    return os;
}

void help(vector<int>&v,int k){
    Solution s;
    cout<<"原数组....."<<endl;
    cout<<v;
    //s.rotate(v,k);
    s.rotate1(v,k);
    cout<<"旋转k次后的数组...."<<endl;
    cout<<v;

}

int main(){
    vector<int> v{1,2,3,4,5,6,7};
    vector<int> v1;
    vector<int> v2{1};
    help(v,4);
    help(v1,3);
    help(v2,3);
    return 0;
}