class Solution {
public:
    void reduce(string &board)
    {
        int index,l,prev_length=0;
        while(prev_length!=board.length())
        {            
            prev_length=board.length();
            for(int i=board.length()-1;i>1;i--)
            {
                l=1;
                while(i>0&&board[i]==board[i-1])
                    l++,i--;
                if(l>=3)
                    board.erase(i,l);
            }
        }
    }
    int helper(string board,string hand)
    {
        int index,result=6,next_index;
        string board_temp;
        for(int h=0;h<hand.size();h++)
        {
            index=next_index=0;
            while(index!=string::npos)
            {
                index=board.find(hand[h],next_index);
                if(index<board.length()-1&&board[index]==board[index+1])
                {
                    board_temp=board.substr(0,index)+board.substr(index+2);
                    reduce(board_temp);
                    if(board_temp.empty())
                        return 1;
                    result=min(1+helper(board_temp,hand.substr(0,h)+hand.substr(h+1)),result);
                    index++;
                }
                else if(index!=string::npos&&h>0&&hand[h]==hand[h-1])
                {
                    board_temp=board.substr(0,index)+board.substr(index+1);
                    reduce(board_temp);
                    if(board_temp.empty())
                        return 2;
                    result=min(2+helper(board_temp,hand.substr(0,h-1)+hand.substr(h+1)),result);
                }
                next_index=index+1;
            }
        }
        return result;
    }
    int findMinStep(string board, string hand) 
    {
        int result;
        sort(hand.begin(),hand.end());
        result=helper(board,hand);
        return result>hand.size()?-1:result;
    }
};