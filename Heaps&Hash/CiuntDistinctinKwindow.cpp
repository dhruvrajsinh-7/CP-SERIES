vector<int> countDistinct(int arr[], int n, int k)
{
    vector<int> v;
    unordered_map<int, int> mp;
    int left = 0, right = 0;
    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    v.push_back(mp.size());
    for (right = k; right < n; right++)
    {
        mp[arr[left]]--;
        if (mp[arr[left]] == 0)
        {
            mp.erase(arr[left]);
        }
        left++;
        mp[arr[right]]++;
        v.push_back(mp.size());
    }
    return v;
}