#include "kebab.h"

  Kebab:: Kebab(){
  	
    }
  // Adds item to the pointy end of the skewer
  //   and returns true if skewer has space to add
  //   and item is a valid ingredient
  // Returns false if skewer is full or ingredient is invalid
bool Kebab:: addIngredient(char item){
	if (skewer.size()<maxlength && isValidIngredient(item))
	{
		skewer.push_back(item);
		return true;
	}else{
		return false;
	}
}
  // Adds the ingredients specified by s using addIngredient
  //   up to the capacity of the skewer
  void Kebab:: buildKebab(std::string s){
  	for(unsigned int i =0; i<s.size();++i){
  		addIngredient(s.at(i));
  	}
  }
   // returns the number of meat items on this kebab
  unsigned int Kebab:: numMeats() const{
  	unsigned int sum =0;
  	for( const char& i : skewer){
  		if(i=='B' || i=='b'){
  			sum++;
  		}
  	}
  	return sum;
  }
  // Returns true iff this kebab contains at least the same collection
  // of ingredients as k, in any order
  // Note that this kebab may contain more total ingredients than k,
  // but will return true as long as this kebab's ingredients is
  // a super-multiset of k's ingredients
  /*
  bool Kebab:: hasSameIngredients(Kebab& k) const{
  	char* p =   k.skewer.data();
  	unsigned int sum =0;
  	for (unsigned int i = 0; i < k.skewer.size(); ++i) 
  		{
  			auto it = std::find (skewer.begin(),skewer.end(), *p);
  			if (it != skewer.end())
  			{
  				swap(*it, skewer.back());
  				skewer.pop_back();
  				sum++;
  			}
  			 
  			 p++;
  		}
  		if(sum>=k.skewer.size()){
  			return true;
  		}return false;
  }*/
  
  bool Kebab:: hasSameIngredients(Kebab& k) const{
  	int countB=0;
  	int countT=0;
  	int countM=0;
  	int countP=0;
  	int countS=0;
  	int countBB=0;
  	int countTT=0;
  	int countMM=0;
  	int countPP=0;
  	int countSS=0;
  	for(unsigned int i =0; i<k.skewer.size(); i++){
  		if((k.skewer.at(i)=='B')||(k.skewer.at(i)=='b')){
  			countB++;
  		}
  		if((k.skewer.at(i)=='T')||(k.skewer.at(i)=='t')){
  			countT++;
  		}
  		if((k.skewer.at(i)=='P')||(k.skewer.at(i)=='p')){
  			countP++;
  		}
  		if((k.skewer.at(i)=='s')||(k.skewer.at(i)=='S')){
  			countS++;
  		}
  		if((k.skewer.at(i)=='m')||(k.skewer.at(i)=='M')){
  			countM++;
  		}
  	}
  	for(unsigned int i=0;i<skewer.size();i++){
  	if((skewer.at(i)=='B')||(skewer.at(i)=='b')){
  			countBB++;
  		}
  		if((skewer.at(i)=='T')||(skewer.at(i)=='t')){
  			countTT++;
  		}
  		if((skewer.at(i)=='P')||(skewer.at(i)=='p')){
  			countPP++;
  		}
  		if((skewer.at(i)=='s')||(skewer.at(i)=='S')){
  			countSS++;
  		}
  		if((skewer.at(i)=='m')||(skewer.at(i)=='M')){
  			countMM++;
  		}	
  	}
  	if(countBB>=countB&&countTT>=countT&&countMM>=countM&&countPP>=countP&&countSS>=countS){
  		return true;
  	}
  	return false;

}
  /*   std::vector<char> given = k.skewer;
  	std::vector<char> known = skewer;
  	int sizeOfGiven = given.size();
  	int sizeOfKnown = known.size();
  	int sum = 0;
  	char c;
  	if(sizeOfKnown<sizeOfGiven){
  		return false;
  	}
  	for(int i=0; i<sizeOfGiven;i++){
  		c = given.at(i);
  		
  		for(int j=0;j<sizeOfKnown;j++){

  			if(tolower(known.at(j))==tolower(c)){
  				sum++;
  				known.erase(known.begin()+j);
  				sizeOfKnown--;
  				break;
  			}
  			
  		}
  	}
  	if(sum==sizeOfGiven){
  		return true;
  	}else{
  		return false;
  	}
  }
  */	
  
    // Returns a string representing the ingredients on this kebab
  //   in the order in which they are skewered
  std::string Kebab::listIngredients() const{
  	std::string s;
  	for(const char  c : skewer){
  		s.push_back(c);
  	}
  	return s;
  }