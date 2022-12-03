 string frequencySort(string s) {
        int n = s.size();
        map<char, int> count;
        for (char ch : s)  {
            count[ch]++;
        }
        vector<vector<char>> extrapack(n+1);
        for (auto [ch, f] : count){
            extrapack[f].push_back(ch);
        }
        string res="";
        int freq=n;
        while(freq>=1){
            for (char ch : extrapack[freq]) 
                res.append(freq, ch);
            freq--;
        }
        return res;
    }