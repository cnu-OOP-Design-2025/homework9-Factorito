#include <iostream>
#include <string>
#include <list>
using namespace std;

template<typename TT>
class MyVector {
    private:
    TT* data;           
    size_t capacity;     
    size_t length;       

    void resize() {
        cout << "Resize: " << capacity << " -> " << capacity * 2 << endl;

       
        capacity *= 2;
       TT* newdata = new TT [capacity];
       
      
        for(int i =0; i<length; i++){
            newdata[i] = data[i];
        }
        TT* tmp = data;
        data = newdata;
        delete [] tmp; 
        
    }

public:

    MyVector() : capacity(2), length(0) {
        
        data = new TT[capacity];
        
    }

    ~MyVector() {
       
        delete [] data;
        
    }

    void push_back(const TT& value) {
      
        if(length == capacity){
            resize();
        }

       
        data[length++] = value; 

        return; 
    }

   
    TT pop_back() {
        if (length == 0)
            throw out_of_range("Vector is empty");
        return data[--length]; 
    }

    
    TT& operator[](const int index){
        return data[index];
    }

    
    size_t size() const {
        return length;
    }

    TT * begin() {return data;}
    TT * end() {return data + length;}

};



template<typename T>
void testVector(const string& name, std::list<T> values) {

    cout << "------------------" << endl;
    MyVector<T> vec;
    for (auto& v : values)
        vec.push_back(v);

    cout << name << ": ";
    for (auto& e : vec) {
    cout << e << " ";
    }
    cout << endl;
    while(vec.size())
        cout << "Pop: " << vec.pop_back() << "\n";
}

int main() {
    testVector<int>("IntVec", {1, 2, 3, 4, 5, 6});
    testVector<double>("DoubleVec", {1.1, 2.2, 3.3, 4.4, 5.5});
    testVector<char>("CharVec", {'A', 'B', 'C', 'D', 'E', 'F'});
    testVector<string>("StringVec", {"Hello", "World", "C++", "Template", "Vector"});
    return 0;
}
