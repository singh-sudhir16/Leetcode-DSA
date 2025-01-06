class Solution {
public:
    int left(string s , int indx){

        int res = 0 , i = indx-1;

        while(i>=0) {
            if(s[i]=='1'){
                res += indx-i;
            } 
            i--;
        }
        return res;
    }
    int right(string s , int indx){

        int res = 0 , i = indx+1;

        while(i<s.size()) {
            if(s[i]=='1'){
                res += i - indx;
            } 
            i++;
        }
        return res;
    }
    vector<int> minOperations(string s) {
        vector<int> res(s.size());
        for(int i=0 ; i<s.size() ; i++){
            int l = left(s , i);
            int r = right(s , i);
            res[i] = l+r;
        }
        return res;
    }
};