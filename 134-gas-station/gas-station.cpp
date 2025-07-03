class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int startIndex = 0;
        int currGas = 0;
        int totalGas = 0;

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

        return totalGas < 0 ? -1 : startIndex ;
    }
};