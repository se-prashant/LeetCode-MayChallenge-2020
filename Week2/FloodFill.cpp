// https://leetcode.com/accounts/login/?next=/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
class Solution {
public:

    void fillFlood(vector<vector<int>>& image, int sr, int sc, int newColor,int reqColor,bool **vis){
        if((sr<0 || sr>=image.size()) || (sc<0 || sc>=image[sr].size()) || image[sr][sc]!=reqColor){
               return;
        }
        if(vis[sr][sc]==true)
            return;
        image[sr][sc] = newColor;
        vis[sr][sc] = true;
        fillFlood(image,sr-1,sc,newColor,reqColor,vis);
        fillFlood(image,sr,sc-1,newColor,reqColor,vis);
        fillFlood(image,sr,sc+1,newColor,reqColor,vis);
        fillFlood(image,sr+1,sc,newColor,reqColor,vis);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        bool **vis = new bool*[row+1];
        for(int i=0; i<=row; i++){
            vis[i] = new bool[col+1];
            for(int j=0;j<=col;j++)
                vis[i][j] = false;
        }
        int reqCol = image[sr][sc];
        fillFlood(image,sr,sc,newColor,reqCol,vis);   
        
        for(int i=0;i<row;i++){
		    delete[] vis[i];
        }
        delete[] vis;
        return  image;
    }
};
