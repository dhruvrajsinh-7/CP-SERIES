bool closeStrings(string word1, string word2)
{
    int n = word1.size();
    if (n != word2.size())
        return false;

    set<char> s1, s2;
    vector<int> f1(26, 0), f2(26, 0);
    for (int i = 0; i < n; i++)
    {
        s1.insert(word1[i]);
        s2.insert(word2[i]);

        f1[word1[i] - 'a']++;
        f2[word2[i] - 'a']++;
    }

    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());

    if (s1 == s2 && f1 == f2)
        return true;
    else
        return false;
}
}
