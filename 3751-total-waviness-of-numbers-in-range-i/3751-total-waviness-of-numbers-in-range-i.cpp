class Solution {
    private:
    static int Count(int a){
        vector<int>digits;
        while(a>0){
            digits.push_back(a%10);
            a/=10;
        }
        reverse(digits.begin(),digits.end());
        int n=digits.size();
        int peaks=0,valleys=0;
        for(int i=1;i<=n-2;){
            if(digits[i]>digits[i-1]&&digits[i]>digits[i+1])peaks++;
            if(digits[i]<digits[i-1]&&digits[i]<digits[i+1])valleys++;
            i++;

        }
        return valleys+peaks;
    }
public:
    int totalWaviness(int num1, int num2) {
        int sum=0;
        for(int i=num1;i<=num2;i++){
            sum+=Count(i);
        }
        return sum;
    }
};