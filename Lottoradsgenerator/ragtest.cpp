#include "stdafx.h"

#include "lottorad.h"
#include "multipleLotto.h"


void clear(int arr[36]){
    for (int i=0;i<36;++i)
        arr[i]=0;
}


bool checkRow( const int rad[7] ){
  int cnt[36];
  clear( cnt );
  for (int i=0;i<7;++i)
      if(rad[i]>=1 && rad[i]<=35)
          cnt[rad[i]]+=1;
      else {
          std::cerr << "BUG: Lottoraden innehåller talet " << rad[i] << "!!\7";
          return false;
      }
  for (int j=0;j<36;++j)
      if (cnt[j]>1){
          std::cerr << "BUG: Siffran " << j << " förekommer flera gånger!!\7";
          return false;
      }
  return true;
}// checkRow


//***********************************************************************
// ANROP:   ragnarsTest( myIdentity );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(const string& myIdentity){
    if (myIdentity.find("Homer")!=string::npos){
        std::cerr << "Felaktig identitet : " << myIdentity << "\7\7\n";
        std::cerr << "Använd DITT förnamn och de sista 4 siffrorna i DITT personnunmmer!!\n";
        system("pause");
        exit( 0 );
    }

    int cnt[36];
    clear( cnt );
    bool ok = true;
    const int numIte = 10000;
    for (int ite=0;ite<numIte  && ok ;++ite){
        int row[8];
        for (int i=0;i<7;++i)
           row[i] = 23;  
        row[7]=999;
        getLotto((row));
        ok = ok && checkRow(row);
        if (ok && row[7]!=999){
            std::cerr << "BUG: din algoritm skriver utanför arrayen!\7\n";
            ok = false;
        }
        for (int i=0; ok && i<7;++i)
            cnt[row[i]]+=1;
    }

    if (ok && cnt[23]==0){
        std::cerr << "BUG: din algoritm genererar aldrig samma tal som raden råkade innehålla vid anrop\7\n" ;
		std::cerr << "Om arrayen exempelvis råkar vara fylld med 3:or innan anrop, så kommer din algoritm inte att kunna slumpa fram talet 3.\n" ;
        ok = false;
    }

    int approx = (numIte*7)/35;
    int min = int(approx*0.9);
    int max = int(approx*1.1);

    if (ok){
        for (int i=1;i<=35 && ok;++i)
            if (cnt[i]==0){
                std::cerr << "BUG: Din algoritm kan inte generera alla tal mellan 1 och 35!\7\n";
                ok = false;
            }
            else
            if (cnt[i]<min || cnt[i]>max){
                std::cerr << "BUG: Lottoraderna är inte tillräckligt slumpmässiga!!\7\n";
                std::cerr << "     du kanske randomizerar (med seed) i getLotto ! \7\n!!";
                ok = false;
            }
    }

    if (ok)
        std::cerr << "ragnarsTest lyckades!\n";
    else std::cerr << "ragnarsTest MISSLYCKADES!!\7\n";
    return ok;
}// ragnarsTest


bool ragnarsTest2(const string& myIdentity){
    if (myIdentity.find("Homer")!=string::npos){
        std::cerr << "Felaktig identitet : " << myIdentity << "\7\7\n";
        std::cerr << "Använd DITT förnamn och de sista 4 siffrorna i DITT personnunmmer!!\n";
        system("pause");
        exit( 0 );
    }


    bool ok = true;
    int rad[7] = {1,2,3,4,5,6,7};	
    Result res = lottoExperiment(rad, 52);
    if (res.maxResult==0){
		std::cerr << "multiple lotto ej implementerad" << endl;
        return false;
    }


    bool seen[8];
    for (int i=0;i<=7;++i)
        seen[i]=false;



    for (int ite=0;ite<1000 && ok;++ite){
        Result result = lottoExperiment(rad, 1);
        const int m = result.minResult;
        ok = ok && m>=0 && m<=7;
        ok = m==result.maxResult && m==result.averageResult;
        if (ok)
            seen[m] = true;
        if (!ok){
            std::cerr << "error in multiple lotto detected!!. ERRCODE = 1\n";
            return false;
        }
    }

    ok = ok && seen[0] && seen[1] && seen[2] && seen[3];
    if (!ok){
            std::cerr << "error in multiple lotto detected!!. ERRCODE = 2\n";
            return false;
    }

    bool commonResult = false;
    for (int ite=0;ite<5 && !commonResult;++ite){
        Result result = lottoExperiment(rad, 520);
        commonResult =  result.minResult==0 && result.maxResult==4 && result.averageResult>1.3 && result.averageResult<1.5;
    }

    ok = ok && commonResult;
    if (!ok){
        std::cerr << "error in multiple lotto. Troligt fel!  ERRCODE = 3\n";
        return false;
    }


    if (ok)
        std::cerr << "Grattis! Multiple lotto är OKEJ ! \n";

    return ok;
}
