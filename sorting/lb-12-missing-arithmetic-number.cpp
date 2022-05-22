int inSequence(int A, int B, int C) {
    // if C==0 then A and B should be same
    if (!C) return (A == B);
    // C is not 0
    return ((B - A) % C == 0 and (B - A) / C >= 0);
    // -2, -9, -7 use -7/-7>=0 but -7>=0 is false
}