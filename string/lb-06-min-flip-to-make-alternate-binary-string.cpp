int minFlips(string s) {
    int n = s.size();
    int starts_one = 0, starts_zero = 0;
    // a string can start with either 0 or 1
    // whichever need min swap that would be the ans
    // starting with one =>all odd position should be 1
    // same for 0
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            // for starting with 1 at odd poition if not 0 then one more filp for this.
            // if zero at odd position starting with 0 then make it 1 hence one more flip for starting with 0
            (s[i] != '0') ? starts_one++ : starts_zero++;
        } else {
            // for starting with one if even position do not have 1 then flip 1
            // do nothing as already there is 0. vice versa for 0
            (s[i] != '1') ? starts_one++ : starts_zero++;
        }
    }
    return min(starts_one, starts_zero);
}