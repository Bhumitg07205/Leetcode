class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        if(asteroids[0]>mass)return false;
        long long m=mass;
        for(int a:asteroids){
            if(m>=a){
                m+=a;
            }else return false;
        }
        return true;
    }
};