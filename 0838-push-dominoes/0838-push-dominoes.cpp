class Solution {
public:
    string pushDominoes(string dominoes) {

        int n = dominoes.length();

        vector<int>LeftClosestR(n);
        vector<int>RightClosestL(n);

        for(int i=0 ; i<n ; i++){
            if(dominoes[i]=='R'){
                LeftClosestR[i]=i;
            }
            else if(dominoes[i] == '.'){
                LeftClosestR[i]=i>0 ? LeftClosestR[i-1]:-1;

            }
            else{
                LeftClosestR[i]=-1;
            }
        }

        for(int i=n-1 ; i>=0 ; i--){
            if(dominoes[i]=='L'){
                RightClosestL[i]=i;
            }
            else if(dominoes[i] == '.'){
                RightClosestL[i]=i<n-1 ? RightClosestL[i+1]:-1;

            }
            else{
                RightClosestL[i]=-1;
            }
        }

        string result(n,' ');
        for(int i=0 ; i<n ; i++){
            int disLeftR=abs(i- LeftClosestR[i]);
            int disRightL=abs(i-RightClosestL[i]);

            if(LeftClosestR[i]==RightClosestL[i]){
                result[i]='.';
            }
            else if(LeftClosestR[i] ==-1){
                result[i]='L';
            }
            else if(RightClosestL[i] == -1){
                result[i]='R';
            }
            else if(disLeftR == disRightL ){
                result[i]='.';
            }
            else{
                result[i]= disLeftR < disRightL ?'R':'L';
            }
        }
        return result;
        
    }
};