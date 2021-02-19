
Time Complexity - O(Log(N))+O(N) where Log(N) for sorting the intervals array and N for Merging it and
Space Complexity is O(2N) for return vector

Code :

class Solution {
public:
vector<vector> merge(vector<vector>& intervals) {

    //Returned Vector
    vector<vector<int>> mergedIntervals;
	
    //If the array size is 0 return Null array
    if(intervals.size()==0){
        return mergedIntervals;
    }
	
    //sort the array
    sort(intervals.begin(),intervals.end());
	
    //Insert the first set in the array tempIntervals i.e [start,end]
    vector<int> tempInterval =intervals[0];
	
    //Iterate in the array
    for(auto it:intervals){
	
        //if (second of last set) is greater than (first of current set)
        //means they are merging intervals
        if(it[0]<=tempInterval[1]){
		
            //so change the end limit of the merge set 
            tempInterval[1]=max(it[1],tempInterval[1]);
			
        }else{
		
            //if they are not merging then simply push previous set 
            //in the Returned vector
            mergedIntervals.push_back(tempInterval);
			
            //assign the current set 
            tempInterval=it;
        }
    }
	
    //Insert the last set left in the tempInterval inside the return array
    mergedIntervals.push_back(tempInterval);
	
    return mergedIntervals;
}
};
