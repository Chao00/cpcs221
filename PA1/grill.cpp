#include "grill.h"
#include "linkedlist.h"
// default constructor
  Grill::Grill(){
  	
  }
    // Switches the kebabs at pos1 and pos2
  // Returns true if positions are valid and swap can be performed
  // Returns false if positions are invalid
  //1-based
   bool Grill::swap(unsigned int pos1, unsigned int pos2){
   			if (rack.size() == 0) {
			return false;
		}  if (pos1<1||pos2<1||pos1>rack.size()||pos2>rack.size()) {
			return false;
		}
		 if (pos1 == pos2) {
			return false;
		} 
			if (pos1 < pos2) {
				Kebab * temp2 = rack.removeAt(pos2 - 1);
				Kebab * temp1 = rack.removeAt(pos1 - 1);
				rack.insertAt(temp2, (pos1 - 1));
				rack.insertAt(temp1, (pos2 - 1));
				return true;
			}
			if (pos2 < pos1) {
				Kebab * temp1 = rack.removeAt(pos1 - 1);
				Kebab * temp2 = rack.removeAt(pos2 - 1);
				rack.insertAt(temp1, (pos2 - 1));
				rack.insertAt(temp2, (pos1 - 1));
				return true;
			}
	}
 

  	/*
  	if(pos1>pos2){
  	Kebab* k1 = rack.removeAt(pos1-1);
  	Kebab* k2 = rack.removeAt(pos2-1);
  	rack.insertAt(k1,pos2-1);
  	rack.insertAt(k2,pos1-1);
  	return true;
  	}
  	if(pos2>pos1){
  	Kebab* k2= rack.removeAt(pos1-1);
  	Kebab* k1 = rack.removeAt(pos2-1);
  	rack.insertAt(k1,pos1-1);
  	rack.insertAt(k2,pos2-1);
   	return true;
  	}
  }*/


   // remove and return the kebab at a 1-indexed
  // position on the grill
  // return NULL if pos invalid
  Kebab* Grill::request(unsigned int pos){
  	if(pos<1||pos>rack.size()){
  		return NULL;
  	}

  	return rack.removeAt(pos-1);
  }
  // remove and return the leftmost kebab matching
  // at least the ingredients of r, in any order
  // return NULL if no match found
  Kebab* Grill::request(Kebab& r){
  	for(unsigned int i =0; i<rack.size();i++){
  		Kebab* k =rack.elementAt(i);
  		if(k->hasSameIngredients(r)){
  			return rack.removeAt(i);
  		}
  	}
  	return NULL;
  }
    void Grill::addKebab(Kebab& n){
    	Kebab* k =&n;
    	rack.insertBack(k);
    }
      // arrange in decreasing order of # of meat items
  void Grill::sortByMeat(){
  	
  	if(rack.size()!=0){
  		for(unsigned int j=0; j<rack.size()-1;j++){
  			for(unsigned int i=0;i<rack.size()-1-j; i++){
  				if(rack.elementAt(i)->numMeats()<rack.elementAt(i+1)->numMeats()){
  					swap(i+1,i+2);
  				}
  			}
  		}
  	}
  }
  /*	
  if(rack.size()!=0){	
  	for(unsigned int i=0;i<rack.size()-1;i++){
  		unsigned int biggest = i;
  		for(unsigned int j=i+1;j<rack.size();j++){
  			if(rack.elementAt(j)->numMeats()>rack.elementAt(biggest)->numMeats()){
  				biggest = j;
  			}
  		}
  		if(biggest!=i){
  			swap(i+1,biggest+1);
  		}
  	
  	}

  }
}*/
    // returns a vector containing the string representation of all
  //   kebabs on the grill
  std::vector<std::string> Grill::showKebabs() const{
  	  std::vector<std::string> kvec;
  	  Kebab* k;
  	  for(unsigned int i =0; i<rack.size();i++){
  	  	k = rack.elementAt(i);
  	  	std::string get = k->listIngredients();
  	  	
  	  	kvec.push_back( get);
  	  }
  	  return kvec;
  }
  /*
  voidSelectionSort(intarr[], intsize)
{
for(inti= 0; i< size -1; ++i)
{
intsmallest = i;
// Find the index of the smallest element
for(intj = i+ 1; j < size; ++j)
{
if(arr[j] < arr[smallest])
{
smallest = j;
}
}
// Swap the smallest with the current item
temp = arr[i];{
arr[i] = arr[smallest];
arr[smallest] = temp;
}
}*/