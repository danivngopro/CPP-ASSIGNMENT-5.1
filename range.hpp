#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class range{

		public:
		//Varaiables
		T start;
		T finish; 

		//Constructor
		range(T firstValue, T secondValue) : start(firstValue), finish(secondValue){}


		//-------------------------------------------------------------------
		// iterator related code:
		// inner class and methods that return instances of it)
		//-------------------------------------------------------------------
		class iterator {
			private:
			T* value;
			
			public:
			//Constructor
			iterator(T* rangeStartElement):  value(rangeStartElement){}

			// The method is const as this operator does not allow changing of the iterator.
			// Note that it returns T& as it allows to change what it points to.
			T operator*() const {
				return *value;
			}

			T* operator->() const {
				return &value;
			}

			// ++i; 
			iterator* operator++() {
				(*value)++;
				return this;
			}

			// i++; 
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
				(*value)++;
				return tmp; 		
			}

			bool operator==(const iterator& rhs) const {
				return *value != *(rhs.value);
			}

			bool operator!=(const iterator& rhs) const {
				return *value != *(rhs.value);
			}
		}; //end iterator

		iterator begin() {
			return iterator{&start};
		}
		
		iterator end() {
			return iterator{&finish};
		}
		
		//Auxilary method for testing the program
		void print(){
			for(T current : *this)
				cout << current; 
			cout << endl;
		}


	};//end of class range
};//end namespace itertools
