string removeConsecutiveCharacter(string S) {
    string ans;
    // if prev char do not match then take previous as unique ans
    for (int i = 1; i < S.size(); i++) {
        if (S[i] != S[i - 1]) ans.push_back(S[i - 1]);
    }
    // as last will be unique ans goes outof bound in loop
    ans.push_back(S[S.size() - 1]);
    return ans;
}