class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int currGas = 0;
        int totalGas = 0;
        int startIndex = 0;

        for(int i = 0; i < n; i++)
        {
            currGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];

            if(currGas < 0)
            {
                currGas = 0;
                startIndex = i + 1;
            }
        }

        if(totalGas < 0)
        {
            return -1;
        }

        else{
            return startIndex;
        }
    }
};