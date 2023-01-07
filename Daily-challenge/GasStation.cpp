#include<bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sum_of_cost = 0, sum_of_gas = 0;
    int index = 0, sum = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        sum_of_cost += cost[i];
        sum_of_gas += gas[i];
        sum += gas[i] - cost[i];
        if (sum < 0)
        {
            index = i + 1;
            sum = 0;
        }
    }
    if (sum_of_gas < sum_of_cost)
    {
        return -1;
    }
    return index;
}
int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<canCompleteCircuit(gas,cost);
    return 0;
}