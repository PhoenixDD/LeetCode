/*
Calculate when a word repeats at the start of a row, keep storing the number of times (rowTimes) the entire sentence repeats at each row.
Get the number of remaining rows, get the number of rows the word repeats itself.
number times the sentence repeated between last occurence of word and current = rowTimes[currentRow]-rowTime[last]
Number of times sentence repeats after = times already covered + (repeatTimes)(^)*number of rows left/(rows after that word repeats) + #sentence repeats after last occurence of that word uptil `x` number of rows where x is number of rows left%(rows after that word repeats)
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols)
    {
        int wordIndex=0,row=0,col,times=0;
        vector<int> rowTimes={0},indexAtRow(sentence.size(),-1);//Store number of times sentence repeats at ith row, store word index @ row i
        while(row<rows)
        {
            col=0;
            if(indexAtRow[wordIndex]!=-1)           //We found a cycle
                break;
            indexAtRow[wordIndex]=row;
            while(col+sentence[wordIndex].size()-1<cols)  //Can b optimised with binary search on sums of word length(Gets #words fit in row)
            {
                col+=sentence[wordIndex].size()+1;
                wordIndex=(wordIndex+1)%sentence.size();
                if(!wordIndex)              //sentence repeated once
                    times++;
            }
            rowTimes.push_back(times);
            row++;
        }
        if(row==rows)           //We exhausted all rows while finding a cycle
            return times;
        int remRows=rows-row,repeatTimes=rowTimes[row]-rowTimes[indexAtRow[wordIndex]];//rows remaining, #times the sentence repeats from last occurence
        return times+repeatTimes*(remRows/(row-indexAtRow[wordIndex]))+rowTimes[indexAtRow[wordIndex]+(remRows%(row-indexAtRow[wordIndex]))]-rowTimes[indexAtRow[wordIndex]];
    }
};