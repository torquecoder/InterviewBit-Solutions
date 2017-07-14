// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int ans=0;
    int x=X[0],y=Y[0];
    for(int i=1;i<X.size();i++)
    {
        if(X[i]==x)
            ans+=abs(y-Y[i]);
        else if(Y[i]==y)
            ans+=abs(x-X[i]);
        else
        {
            int maxi=max(abs(x-X[i]),abs(y-Y[i]));
            ans+=maxi;
        }
        x=X[i];
        y=Y[i];
    }
    return ans;
}
