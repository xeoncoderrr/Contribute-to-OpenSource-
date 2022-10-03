
// input
// 1. n number of rows and columns
// 2. nxn matrix with 1 and 0 . 1 ->path 0->block

//Output : String
// Path U-> UP D->DOWN R->RIGHT L->LEFT

void move(vector<vector<bool>>&arr,vector<string>& paths,string path,int row,int col){
    int n=arr.size();
    if(row==-1 || row==n || col==-1 || col==n) return;
    if(row==n-1 && col==n-1 && arr[row][col]==1){
        paths.push_back(path);
        return;
    }
    if(arr[row][col]==1){
//         not to re count again while backtracking
        arr[row][col]=0;
        
        move(arr,paths,path+"U",row-1,col); //up
        move(arr,paths,path+"R",row,col+1); //right
        move(arr,paths,path+"D",row+1,col); //down
        move(arr,paths,path+"L",row,col-1); // left
        
        arr[row][col]=1;
    }
}

vector<string> findAllPaths( vector<vector<bool>> &arr)
{
    //    Write your code here.
    vector<string> paths;
    move(arr,paths,"",0,0);
    return paths;

}


