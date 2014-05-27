// set mx = 1666667 for primes upto 1e8
// set mx = 166667  for primes upto 1e7
const unsigned MX = 166667 , MAX_S = sqrt(MX/60);
unsigned short composite[MX];
vector<int> pr;
void sieve() {
    unsigned w[16] = {1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59};
    unsigned mod[16][16], di[16][16], num;
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++){
            di[i][j] = (w[i] * w[j])/60;
            mod[i][j] = lower_bound(w, w + 16, (w[i]* w[j])%60) - w;
        }
    pr.push_back(2) , pr.push_back(3) , pr.push_back(5);
    memset(composite, 0, sizeof composite);
    for(unsigned i = 0; i < MX; i++)
        for(int j = (i==0); j < 16; j++) {
            if(composite[i] & (1<<j)) continue;
            pr.push_back( num = 60 * i + w[j] );
            if(i > MAX_S) continue;
            for(unsigned k = i, done = false; !done; k++)
                for(int l = (k == 0); l < 16 && !done; l++)
                {
                    unsigned mult = k * num + i * w[l] + di[j][l];
                    if( mult >= MX ) done = true;
                    else composite[mult] |= 1<<mod[j][l];
                }
        }
}
