class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        //Create a vector to keep track of both position and speed pair wise
        vector<pair<int, int>> cars(position.size());

        //Populate
        for(int i = 0; i < position.size(); i++)
        {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }

        //Sort in descending order -  greater<pair<int, int>>() this is for sorting in descending order
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        stack<double> st;

        //Find the totalTimeTaken by each vehicle to reach the end point.
        //If the timeTaken by the previous vehicle is less than the next element that means they both will never reach
        // the same point therefore create a new fleet - thus push in the stack
        for(auto& x : cars)
        {
            int pos = x.first;
            int spd = x.second;

            double timeTaken = (double)(target - pos) / spd;

            if(st.empty() || timeTaken > st.top())
            {
                st.push(timeTaken);
            }
        }

        return st.size();
    }
};