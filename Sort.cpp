class Solution {
public:
    void selectionsort(vector<int>& nums){
        int n= nums.size();
        for(int i =0;i<n;i+=1){
            for(int j = i+1;j<n;j+=1){
                if(nums[i]>nums[j]){
                    swap(nums[i],nums[j]);
                }
            }
        }
        return ;
    }
    void bubblesort(vector<int>& nums){
        int n = nums.size();
        for(int i =0;i<n-1;i+=1){
            for(int j =0;j<n-1;j+=1 ){
                if(nums[j]>nums[j+1]){
                    swap(nums[j+1],nums[j]);
                }
            }
        }

    }
    void insertitionsort(vector<int>& nums){
        int n = nums.size();
        for(int i =0;i<n;i+=1){
            int j =i;
            while(j>0 && nums[j-1]>nums[j]){
                swap(nums[j-1],nums[j]);
                j--;
            }
        }
        return;
    }
    void merge(vector<int>& nums, int low ,int mid,int right ){
        int n = nums.size();
        vector<int>temp;
        int i =low;
        int j = mid+1;
        while(i<=mid && j<= right){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<= right){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k =low;k<=right;k+=1){
            nums[k]= temp[k-low];
        }
        return;
    }
    void mergesort(vector<int>& nums,int low, int high){
        if(low>= high ){
            return;
        }
        int n = nums.size();
        int mid = low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid ,high);
    }
    int partition(vector<int>&nums, int low, int k){
        int n = nums.size();
        int i = low-1;
        int pivot = nums[k];
        for(int j = low;j<=k-1;j+=1){
            if(nums[j]<=pivot){
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[i+1],nums[k]);
        return i+1; 


    }
    void quicksort(vector<int>& nums , int low, int high){
        int n = nums.size();
        int pivot = nums[n-1];
        if(low<high){
            int pi = partition(nums,low,high);
            quicksort(nums,low,pi-1);
            quicksort(nums,pi+1,high);
        }
    }

    
    void sortColors(vector<int>& nums) {
        // selectionsort(nums);
        bubblesort(nums);
        // insertitionsort(nums);
        int n = nums.size();
        // mergesort(nums,0,n-1);
        // quicksort(nums,0,n-1);
        return ;
    }
};
