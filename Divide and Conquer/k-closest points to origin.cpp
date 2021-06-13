//using multimaps as they store data in sorted order....check out video of tech dose for same ques
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
     multimap<int,int>m;
        vector<vector<int>>ans;
        
     int n=points.size();
        for(int i=0;i<n;i++)
        {
            m.insert({points[i][0]*points[i][0]+points[i][1]*points[i][1],i});
        }
        int count = 0;
        for(auto it=m.begin();count<k;++it,++count)
            ans.push_back(points[it->second]);
        
        return ans;
    }
};
