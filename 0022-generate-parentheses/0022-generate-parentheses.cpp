class Solution {
public:

    bool isValid(string temp){
        int count=0;

        for(int i=0 ; i<temp.size() ; i++){
            if(temp[i]=='('){
                count++;

            } 
            else if(temp[i]==')'){
                count--;
            }

            if(count <0){
                return false;
            } 

        }
        if(count ==0) return true;
        else return false;
    }

    void helper(int n , string temp , vector<string>&ans){
        if(temp.size()==2*n){
            if(isValid(temp)){
                ans.push_back(temp);
            }
            return;
        }


        temp.push_back('(');
        helper(n,temp,ans);

        temp.pop_back();
        temp.push_back(')');
        helper(n,temp,ans);
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string>ans;

        helper(n,temp,ans);
        return ans;
        
    }
};