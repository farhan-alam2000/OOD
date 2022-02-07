//designing hashmap using linked list
/*
<----------------------Constraints and assumptions--------------------------------->
For simplicity, are the keys integers only? - Yes
For collision resolution, can we use chaining? - Yes
Do we have to worry about load factors? - No
Can we assume inputs are valid or do we have to validate them? - Assume they're valid 
Can we assume this fits memory? - Yes
<----------------------------------------------------------------------------------->
*/
/*working of functions - 
	1. get(key) - get the value of key from hashmap
		case a: key present in the map, return its value
		case b: key not present, return -1
	2. put(key, value) - put/update the value of key in hashmap
		case a: key not present, put the key-value in hashmap
		case b: key present, update the value of corresponding key in hashmap
	3. remove(key) - remove the key from hashmap
		case a: key present, set the value to -1
		case b: key not present, do nothing
*/

//<--------------------------------------C++ Code------------------------------------------------>

//class for key-value pair
class Item 
{
public:
	int key, value;
	Item(int key, int value) //constructor for initialising (key-value)
	{
		this->key = key;
		this->value = value;
	}
};
class MyHashMap {
private:
    static const int size = 997; //997, 769 -> taking prime numbers as bucket size to minimize collisions
    vector<Item> List[size]; //Array of vectors to store the list of elements belonging to each bucket index
public:
    MyHashMap() {
       //no intialisation required
    }
    
    int hash_fun(int key)
    {
    	return (key%size); 
    }
    
    void put(int key, int value) {
        int bucket = hash_fun(key);
        Item e(key, value);
        for(auto& x: List[bucket])
        {
            if(x.key == key)
            {
                x.value = value;
                return;
            }
        }
        List[bucket].push_back(e);
    }
    
    int get(int key) {
       int bucket = hash_fun(key);
       for(auto x: List[bucket])
       {
       		if(x.key == key) return x.value;
       }
       return -1; 
    }
    
    void remove(int key) {
       int bucket = hash_fun(key);
       for(auto& x: List[bucket]){
       		if(x.key == key) x.value = -1;
       }
    }
};

