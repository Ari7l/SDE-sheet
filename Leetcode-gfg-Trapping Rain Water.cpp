class Solution {
public:
    //arr[left] or arr[right] always is a pointer to a value which is the max value found so far, searching from left and right.

//If arr[left] <= arr[right], this means that arr[right] is the max value found so far. This also means that maxLeft will be less than or equal to arr[right], which means that maxLeft will be boundry to the answer(res variable, in this solution), since it has be less than or equal to arr[right] e, so we don't have to consider maxRight when adding to the counter.

//If arr[left] > arr[right] , this means at arr[left] is the max value found so far. Same thing applies as explained in the paragraph above
// so basically which ever height is smaller that will be the boundry as water cant be contained above it instead of calculating the trueMaxRight and trueMaxLeft we just compare the max height from left and right 
    int trap(vector<int>& height) {
        int left = 0 , right =height.size()-1;
        int maxLeft =0 ,maxRight= 0;
        int totalW = 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxLeft) maxLeft = height[left];
                else totalW+= maxLeft - height[left];
                left++;
            }
            else{
                if(height[right]>=maxRight) maxRight = height[right];
                else totalW+= maxRight - height[right];
                right--;
            }
        }        
        
        return totalW;
    }
};//TIME : O(N)