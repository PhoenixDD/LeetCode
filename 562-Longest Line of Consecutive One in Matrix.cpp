class Solution {
public:
    int longestLine(vector<vector<int>>& M) 
    {
        if(M.empty()||M.front().empty())
            return 0;
        int curr,result=0;
        for(int i=0;i<M.size();i++)
        {
            curr=0;
            for(int j=0;j<M[i].size();j++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
        }
        for(int j=0;j<M[0].size();j++)
        {
            curr=0;
            for(int i=0;i<M.size();i++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
        }
        for(int j_temp=0;j_temp<M[0].size();j_temp++)
        {
            curr=0;
            for(int j=j_temp,i=0;j<M[0].size()&&i<M.size();j++,i++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
            
        }
        for(int i_temp=1;i_temp<M.size();i_temp++)
        {
            curr=0;
            for(int i=i_temp,j=0;j<M[0].size()&&i<M.size();j++,i++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
            
        }
        for(int j_temp=1;j_temp<M[0].size();j_temp++)
        {
            curr=0;
            for(int j=j_temp,i=0;j>=0&&i<M.size();j--,i++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
            
        }
        for(int i_temp=1;i_temp<M.size();i_temp++)
        {
            curr=0;
            for(int i=i_temp,j=M[0].size()-1;j>=0&&i<M.size();j--,i++)
            {
                if(M[i][j])
                    curr++;
                else
                    curr=0;
                result=max(result,curr);
            }
            
        }
        return result;                
    }
};