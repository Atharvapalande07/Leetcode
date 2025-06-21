class Solution {
public:
    bool Ispossible(vector<int>& time, int totalTrips , long long mid){
        long long actualTrip =0;
        for(int i=0 ; i<time.size() ; i++){
            actualTrip+=mid / time[i];
        }
        return actualTrip >= totalTrips;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start=1;
        long long end = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(start < end){
            long long mid=start+(end - start)/2;

            if(Ispossible(time , totalTrips , mid)){
                end=mid;
            }
            else{
                start=mid + 1;
            }
        }
        return start;

        
    }
};