/*Cases to consider "ab"->"ba" and "abc...z"-> "z,y,x....a"
Key is that we always need a temporary character to transform other characters
to their mapping which is not in the string */
class Solution {
public:
    bool canConvert(string str1, string str2) 
	{
        if(str1==str2)				//Corner case
			return true;
		vector<char> map(26,'-');
		for(int i=0;i<str1.size();i++)
		{
			if(map[str1[i]-'a']!='-'&&map[str1[i]-'a']!=str2[i])//Already mapped but different character is always false
				return false;
			map[str1[i]-'a']=str2[i];
		}
		return unordered_set(str2.begin(),str2.end())<26;//Check if there is atleast 1 character that is not included and this can be used as temp to swap	
    }
};