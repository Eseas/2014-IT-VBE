#include <fstream>

void skirkTaskus(int S1, int S2, int S3, int& L1, int& L2, int& L3) {
        if (S1 == S2 && S2 == S3) return;         // jei balsu kiekiai lygus, taskai neskiriami

        if (S1 > S2  && S1 > S3)  L1 += 4;          // daugiausiai balsu surinkusiam skiriami 4 taskai
                else if (S2 > S1  && S2 > S3) L2 += 4;
                        else if (S3 > S1  && S3 > S2) L3 += 4;
        if (S1 == S2  && S1 > S3){                       // dviems daugiausiai balsu susinkusiems skiriami 2 taskai kiekvienam
                L1 += 2;
                L2 += 2;
        } else if (S1 == S3  && S1 > S2){
                        L1 += 2;
                        L3 += 2;
                     } else if (S2 == S3  && S2 > S1){
                                L2 += 2;
                                L3 += 2;
                                 }
}
int raskGeriausia(int& L1, int& L2, int& L3, int D1, int D2, int D3) {
        if ((L1 == L2 && L1 > L3) || (L1 == L3 && L1 > L2) || (L2 == L3 && L2 > L1) || (L1 == L2 && L2 == L3)) {  // jeigu dvieju ar triju GERIAUSIØ logotipu taskai vienodi, pridedami direktoriaus taskai
                L1 += D1;
                L2 += D2;
                L3 += D3;
        }
        if (L1 > L2 && L1 > L3) return 1;
        if (L2 > L1 && L2 > L3) return 2;
        if (L3 > L1 && L3 > L2) return 3;
}
int main() {
        int k,                                              // Skyriu skaicius
               S1, S2 , S3,                             // Vieno skyriaus balsai
               L1 = 0, L2 = 0, L3 = 0,           // Logotipu tasku skaicius
               B1 = 0, B2 = 0, B3 = 0,         // Logotipu balsu skaicius
               D1, D2, D3;                            // Direktoriaus skirti taskai

        std::ifstream fd ("U1.txt");             // Duomenu is failo skaitymas
        fd >> k;
        for (int i = 0; i < k; i++) {
                fd >> S1 >>  S2 >> S3;
                skirkTaskus(S1, S2, S3, L1, L2, L3);
                B1 += S1;    // balsu suskaiciavimas
                B2 += S2;
                B3 += S3;
        }
        fd >> D1 >> D2 >> D3;
        fd.close();

        std::ofstream fr("U1rez.txt");      // Rezultatu isvedimas
        fr << B1 << ' ' << B2 << ' ' << B3 << std::endl;
        fr << L1 << ' ' << L2 << ' ' << L3 << std::endl;
        fr <<  raskGeriausia(L1, L2, L3, D1, D2, D3);
        fr.close();
}
