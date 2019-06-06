class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int ans = 0;
        int ls = 0,rs = 0;
        int lmin = 27,rmin = 27;
        for(int i=0;i<n;i++)
        {
            if(left[i]*right[i]==0)   //有一边没有就需要将这种可能移除，即＋1
            {
                ans+=left[i]+right[i];
            }
            else
            {
                ls+=left[i];
                rs+=right[i];
                lmin = min(lmin,left[i]);
                rmin = min(rmin,right[i]);
            }
        }
        return ans+min(ls-lmin+1,rs-rmin+1)+1;
    }

};
